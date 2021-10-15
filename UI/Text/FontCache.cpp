#include "FontCache.h"

#include <filesystem>
#include <iostream>
#include <assert.h>

namespace UI::Text
{

    FontCache::FontCache(const std::string &fontDirectory)
    {
        _fontDir = fontDirectory;

        int code = TTF_Init();
        assert(code == 0);

        LoadFonts();
    }

    FontCache::~FontCache()
    {
        for (auto const& [key, val] : _fonts)
        {
            for (auto const& [innerKey, innerVal] : val)
            {
                if (innerVal != nullptr)
                {
                    TTF_CloseFont(innerVal);
                }
            }
        }
    }

    TTF_Font &FontCache::GetFont(const std::string &name, int size)
    {
        std::map<int, TTF_Font*> &size_map = _fonts[name];
        bool size_exists = size_map.find(size) != size_map.end();
        if (size_exists)
        {
            return *size_map[size];
        }
        else
        {
            std::filesystem::path fonts = std::filesystem::canonical(std::filesystem::current_path() += std::filesystem::path ("/../" + _fontDir));
            std::filesystem::path file = std::filesystem::canonical(fonts += std::filesystem::path ("/" + name + ".ttf"));

            TTF_Font *font = TTF_OpenFont(file.string().c_str(), size);
            size_map[size] = font;

            return *font;
        }
    }

    void FontCache::LoadFonts()
    {
        const int default_size = 18;
        std::filesystem::path fonts = std::filesystem::canonical(std::filesystem::current_path() += std::filesystem::path ("/../" + _fontDir));
        for (const auto &entry : std::filesystem::directory_iterator(fonts))
        {
            std::filesystem::path full_path = entry.path();
            std::string key = full_path.filename().replace_extension().string();

            TTF_Font *font = TTF_OpenFont(full_path.string().c_str(), default_size);
            std::map<int, TTF_Font*> &size_map = _fonts[key];
            size_map[default_size] = font;
        }
    }

}