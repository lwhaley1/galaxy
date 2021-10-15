#include "Renderer.h"

#include <assert.h>
#include <filesystem>

namespace UI
{
    Renderer::Renderer(SDL_Renderer *renderer)
    {
        _renderer = renderer;
        _fonts = new Text::FontCache("Assets/Fonts");
    }

    Renderer::~Renderer()
    {
        SDL_DestroyRenderer(_renderer);

        delete _fonts;
        _fonts = nullptr;
    }

    void Renderer::Render()
    {
        SDL_RenderPresent(_renderer);
    }

    void Renderer::Clear()
    {
        SDL_SetRenderDrawColor(_renderer, 0xFF, 0xFF, 0xFF, SDL_ALPHA_OPAQUE);
        SDL_RenderClear(_renderer);
    }

    SDL_Surface *Renderer::GetImageSurface(const std::string &imgPath)
    {
        // TOOD: Change this to work with other types of images.
        std::filesystem::path fonts = std::filesystem::canonical(std::filesystem::current_path() += std::filesystem::path ("/../" + imgPath));
        return SDL_LoadBMP(fonts.string().c_str());
    }

    void Renderer::DrawText(int x, int y, const std::string &text, const std::string &font, int size)
    {
        SDL_Color font_color = ColorBlack();
        TTF_Font &ttf = _fonts->GetFont(font, size);
        SDL_Surface *surface = TTF_RenderText_Solid(&ttf, text.c_str(), font_color);
        SDL_Texture *texture = SDL_CreateTextureFromSurface(_renderer, surface);
        SDL_FreeSurface(surface);

        int width, height;
        TTF_SizeText(&ttf, text.c_str(), &width, &height);

        SDL_Rect quad = { x, y, width, height };
        SDL_RenderCopyEx(_renderer, texture, NULL, &quad, 0.0, NULL, SDL_FLIP_NONE);
        SDL_DestroyTexture(texture);
    }

    void Renderer::DrawCircle(int centerX, int centerY, int radius)
    {
        SDL_SetRenderDrawColor(_renderer, 0x00, 0x00, 0x00, SDL_ALPHA_OPAQUE);

        for (int i = 0; i < radius * 2; i++)
        {
            for (int j = 0; j < radius * 2; j++)
            {
                int dx = radius - i;
                int dy = radius - j;

                if (((dx * dx) + (dy * dy)) <= (radius * radius))
                {
                    SDL_RenderDrawPoint(_renderer, centerX + dx, centerY + dy);
                }
            }
        }
    }

    SDL_Color Renderer::ColorBlack()
    {
        SDL_Color font_color;
        font_color.a = 0xFF;
        font_color.r = 0x00;
        font_color.g = 0x00;
        font_color.b = 0x00;

        return font_color;
    }
}