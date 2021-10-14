#pragma once

namespace UI::Events
{

class IEventResponse
{
public:
    virtual ~IEventResponse() {}
    virtual bool HandleEvent() = 0;
};

}