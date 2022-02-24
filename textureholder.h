#pragma once

#include <SFML/Graphics.hpp>
#include <map>

class TextureHolder
{
    TextureHolder() = default;
    std::map<std::string, sf::Texture> m_Textures;
public:
    static TextureHolder &instance();
    sf::Texture &GetTexture(std::string filename);
};
