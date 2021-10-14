#include "Renderer.h"
#include "SDL_ttf.h"

#include <assert.h>

namespace UI
{
    Renderer::Renderer(SDL_Renderer *renderer)
    {
        int init = TTF_Init();
        assert(init >= 0);

        _renderer = renderer;
    }

    Renderer::~Renderer()
    {
        SDL_DestroyRenderer(_renderer);
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
}