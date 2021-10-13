#pragma once

#include "SDL.h"

#include <string>

namespace UI
{

class Window
{
public:
    Window(const std::string &title, int width, int height);
    virtual ~Window();

    void ShowAndWait();

private:
    struct FrameData
    {
        float t;
        float dt;
        float current;
        float accumulator;
    };

    SDL_Window *_window = NULL;
    FrameData _frameData;
    bool _isQuit = false;

    void PollEvents();
    void HandleEvent(SDL_Event &e);
    void HandleDeltaTime();
};

}