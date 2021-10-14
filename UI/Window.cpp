#include "Window.h"

#include <iostream>
#include <assert.h>

namespace UI
{
    Window::Window(const std::string &title, int width, int height)
    {
        int result = SDL_Init(SDL_INIT_VIDEO);
        assert(result >= 0);

        _window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN);
        assert(_window != NULL);

        SDL_Renderer *renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
        assert(renderer != NULL);

        _renderer = new Renderer(renderer);

        InitFrameData();
    }

    Window::~Window()
    {
        delete _renderer;
        _renderer = NULL;

        SDL_DestroyWindow(_window);
        SDL_Quit();
    }

    void Window::FullScreen()
    {
        SDL_SetWindowFullscreen(_window, SDL_WINDOW_FULLSCREEN_DESKTOP);
    }

    void Window::ShowAndWait()
    {
        while (!_isQuit)
        {
            PollEvents();
            HandleDeltaTime();
            HandleFPS();
            
            _renderer->Clear();
            _renderer->DrawCircle(300, 300, 100);
            _renderer->Render();
        }
    }

    void Window::AddKeyListener(const Events::KeyEvent &key, Events::IEventResponse& responder)
    {
        std::vector<Events::IEventResponse*> &responders = _keyEventListeners[key];
        responders.push_back(&responder);
    }

    void Window::HandleFPS()
    {
        _frameData.fps_frames++;
        if (_frameData.fps_lasttime < SDL_GetTicks() - 1000)
        {
            _frameData.fps_lasttime = SDL_GetTicks();
            _frameData.fps_current = _frameData.fps_frames;
            _frameData.fps_frames = 0;
        }
    }

    void Window::HandleDeltaTime()
    {
        float time = (float) SDL_GetPerformanceCounter();
        float frame = time - _frameData.current;
        if (frame > 0.25f)
            frame = 0.25f;
        _frameData.current = time;
        _frameData.accumulator += frame;

        while (_frameData.accumulator >= _frameData.dt)
        {
            _frameData.t += _frameData.dt;
            _frameData.accumulator -= _frameData.dt;
        }
    }

    void Window::PollEvents()
    {
        SDL_Event e;
        while (SDL_PollEvent(&e) != 0)
        {
            HandleEvent(e);
        }
    }

    void Window::HandleEvent(SDL_Event &e)
    {
        if (e.type == SDL_QUIT)
        {
            _isQuit = true;
        }

        if (e.type == SDL_KEYDOWN)
        {
            std::vector<Events::IEventResponse*> responders = _keyEventListeners[(Events::KeyEvent) e.key.keysym.sym];
            for (auto responder : responders)
            {
                responder->HandleEvent();
            }
        }
    }

    void Window::InitFrameData()
    {
        _frameData.t = 0.0f;
        _frameData.dt = 0.01f;
        _frameData.current = (float) SDL_GetPerformanceCounter(),
        _frameData.accumulator = 0.0f;
        _frameData.fps_lasttime = SDL_GetTicks();
        _frameData.fps_current = 0;
        _frameData.fps_frames = 0;
    }
}