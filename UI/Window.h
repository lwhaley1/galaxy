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

    void SetIcon(const std::string &imgPath);
    void ShowAndWait();
    void AddKeyListener(const Events::KeyEvent &key, Events::IEventResponse& responder);
    void FullScreen();

    int GetWidth();
    int GetHeight();

    inline bool IsInDebugMode() { return _isDebug; }
    inline void SetDebug(bool debug) { _isDebug = debug; }

private:
    std::map<Events::KeyEvent, std::vector<Events::IEventResponse*>> _keyEventListeners;
    SDL_Window *_window = nullptr;
    Renderer *_renderer = nullptr;
    Structures::FrameData _frameData;
    std::string _title;

    bool _isQuit = false;
    bool _isDebug = true;

    void PollEvents();
    void HandleEvent(SDL_Event &e);
    void HandleDeltaTime();
    void HandleFPS();
    void InitFrameData();
    void DrawDebugInformation();
};

}