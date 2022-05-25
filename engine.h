#pragma once
#include <SFML/Graphics.hpp>
#include "bob.h"
#include "textureholder.h"
#include "thomas.h"

using namespace sf;

class Engine
{
    Thomas m_Thomas;
    Bob m_Bob;
    int const TILE_SIZE = 50;
    int const VERTS_IN_QUAD = 4;
    int const GRAVITY = 300;
    RenderWindow m_Window;
    View m_MainView;
    View m_LeftView;
    View m_RightView;
    View m_BGMainView;
    View m_BGLeftView;
    View m_BGRightView;
    View m_HudView;
    Sprite m_BackgroundSprite;
    Texture m_BackgroundTexture;
    bool m_Playing = false;
    bool m_Character1 = true;
    bool m_SplitScreen = false;
    float m_TimeRemaining = 10;
    Time m_GameTotalTime;
    bool m_NewLevelRequired = true;
    void input();
    void update(float dtAsSeconds);
    void draw();
public:
    Engine();
    void run();
};
