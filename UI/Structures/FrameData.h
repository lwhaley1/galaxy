#pragma once

namespace UI::Structures
{

struct FrameData
{
    float t;
    float dt;
    float current;
    float accumulator;

    Uint32 fps_lasttime;
    Uint32 fps_current;
    Uint32 fps_frames;
};

}