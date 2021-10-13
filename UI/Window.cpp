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

        _frameData.t = 0.0f;
        _frameData.dt = 0.01f;
        _frameData.current = (float) SDL_GetPerformanceCounter(),
        _frameData.accumulator = 0.0f;
    }

    Window::~Window()
    {
        SDL_DestroyWindow(_window);
        SDL_Quit();
    }

    void Window::ShowAndWait()
    {
        while (!_isQuit)
        {
            PollEvents();
            HandleDeltaTime();

            
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
            // key press handling.
        }
    }
}