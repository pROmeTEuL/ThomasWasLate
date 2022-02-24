#include "textureholder.h"

TextureHolder &TextureHolder::instance()
{
    static TextureHolder th;
    return th;
}

sf::Texture &TextureHolder::GetTexture(std::string filename)
{
    auto it = m_Textures.find(filename);
    if (it == m_Textures.end()) {
        m_Textures[filename].loadFromFile(filename);
        return m_Textures[filename];
    }
    return it->second;
}
