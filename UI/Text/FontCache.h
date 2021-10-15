#pragma once

#include "SDL_ttf.h"

#include <string>
#include <map>

namespace UI::Text
{

class FontCache
{
public:
    FontCache(const std::string &fontDirectory);
    virtual ~FontCache();

    TTF_Font &GetFont(const std::string &name, int size);

private:
    std::map<std::string, std::map<int, TTF_Font*>> _fonts;
    std::string _fontDir;

    void LoadFonts();
};

}