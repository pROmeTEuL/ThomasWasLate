#ifndef HUD_H
#define HUD_H

#include <SFML/Graphics.hpp>
using namespace sf;

class Hud
{
    Font m_Font;
    Text m_StartText;
    Text m_TimeText;
    Text m_LevelText;
public:
    Hud();
    Text getMessage();
    Text getLevel();
    Text getTime();
    void setLevel(String text);
    void setTime(String text);
};

#endif // HUD_H
