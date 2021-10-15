#include "Window.h"

#include <iostream>
#include <assert.h>

namespace UI
{
    Window::Window(const std::string &title, int width, int height)
    {
        _title = title;

        int result = SDL_Init(SDL_INIT_VIDEO);
        assert(result >= 0);

        _window = SDL_CreateWindow(title.c_str(), SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN | SDL_WINDOW_RESIZABLE);
        assert(_window != NULL);

        SDL_Renderer *renderer = SDL_CreateRenderer(_window, -1, SDL_RENDERER_ACCELERATED);
        assert(renderer != NULL);

        _renderer = new Renderer(renderer);

        InitFrameData();
    }

    Window::~Window()
    {
        delete _renderer;
        _renderer = nullptr;

        SDL_DestroyWindow(_window);
        SDL_Quit();
    }

    int Window::GetWidth()
    {
        int width, height;
        SDL_GetWindowSize(_window, &width, &height);
        return width;
    }

    int Window::GetHeight()
    {
        int width, height;
        SDL_GetWindowSize(_window, &width, &height);
        return height;
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
            if (_isDebug)
            {
                DrawDebugInformation();
            }


            _renderer->Render();
        }
    }

    void Window::AddKeyListener(const Events::KeyEvent &key, Events::IEventResponse& responder)
    {
        std::vector<Events::IEventResponse*> &responders = _keyEventListeners[key];
        responders.push_back(&responder);
    }

    void Window::SetIcon(const std::string &imgPath)
    {
        SDL_Surface *surface = _renderer->GetImageSurface(imgPath);
        SDL_SetWindowIcon(_window, surface);
        SDL_FreeSurface(surface);
    }

    void Window::DrawDebugInformation()
    {
        const int debug_topright_width = 125;

        // Draw FPS in top right.
        _renderer->DrawText(GetWidth() - debug_topright_width, 10, "FPS: " + std::to_string(_frameData.fps_current));

        // Draw DEBUG mode in top left.
        _renderer->DrawText(10, 10, _title + ": DEBUG MODE ENABLED");
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