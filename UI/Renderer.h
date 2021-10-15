#pragma once

#include "SDL.h"
#include "FontCache.h"
#include "Rect.h"

namespace UI
{

class Renderer
{
public:
    Renderer(SDL_Renderer *renderer);
    virtual ~Renderer();

    SDL_Surface *GetImageSurface(const std::string &imgPath);

    void DrawText(int x, int y, const std::string &text, const std::string &font = "Courier", int size = 18);
    void DrawCircle(int centerX, int centerY, int radius);
    void Clear();

    void Render();

private:
    SDL_Renderer *_renderer;
    Text::FontCache *_fonts;

    SDL_Color ColorBlack();
};

}