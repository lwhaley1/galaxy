#pragma once

#include "SDL.h"

namespace UI::Events
{

enum KeyEvent
{
    RIGHT = SDL_KeyCode::SDLK_RIGHT,
    LEFT  = SDL_KeyCode::SDLK_LEFT,
    UP    = SDL_KeyCode::SDLK_UP,
    DOWN  = SDL_KeyCode::SDLK_DOWN,
    W     = SDL_KeyCode::SDLK_w,
    A     = SDL_KeyCode::SDLK_a,
    S     = SDL_KeyCode::SDLK_s,
    D     = SDL_KeyCode::SDLK_d
};

}