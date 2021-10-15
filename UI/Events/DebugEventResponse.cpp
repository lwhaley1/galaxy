#include "DebugEventResponse.h"

namespace UI::Events
{
    DebugEventResponse::DebugEventResponse(Window &window) : _window(window)
    {
    }

    bool DebugEventResponse::HandleEvent()
    {
        _window.SetDebug(!_window.IsInDebugMode());
        return true;
    }
}