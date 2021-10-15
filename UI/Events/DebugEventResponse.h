#pragma once

#include "IEventResponse.h"
#include "Window.h"

namespace UI::Events
{

class DebugEventResponse : public IEventResponse
{
public:
    DebugEventResponse(Window &window);
    virtual ~DebugEventResponse() {}

    virtual bool HandleEvent();

private:
    Window &_window;
};

}