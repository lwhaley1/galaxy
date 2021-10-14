#pragma once

#include "SDL.h"

namespace UI
{

class Renderer
{
public:
    Renderer(SDL_Renderer *renderer);
    virtual ~Renderer();

    void DrawCircle(int centerX, int centerY, int radius);
    void Clear();

    void Render();

private:
    SDL_Renderer *_renderer;
};

}