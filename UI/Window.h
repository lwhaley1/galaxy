#pragma once

#include "SDL.h"
#include "FrameData.h"
#include "KeyEvent.h"
#include "IEventResponse.h"
#include "Renderer.h"

#include <string>
#include <map>
#include <vector>

namespace UI
{

class Window
{
public:
    Window(const std::string &title, int width, int height);
    virtual ~Window();

    void ShowAndWait();
    void AddKeyListener(const Events::KeyEvent &key, Events::IEventResponse& responder);
    void FullScreen();

private:
    std::map<Events::KeyEvent, std::vector<Events::IEventResponse*>> _keyEventListeners;
    SDL_Window *_window = NULL;
    Renderer *_renderer = NULL;
    FrameData _frameData;
    bool _isQuit = false;

    void PollEvents();
    void HandleEvent(SDL_Event &e);
    void HandleDeltaTime();
    void HandleFPS();
    void InitFrameData();
};

}