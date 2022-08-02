#pragma once
#include <SFML/Graphics.hpp>
#include "bob.h"
#include "textureholder.h"
#include "thomas.h"
#include "levelmanager.h"
#include "soundmanager.h"
#include "hud.h"
#include "particlesystem.h"

using namespace sf;

class Engine
{
    Thomas m_Thomas;
    Bob m_Bob;
    LevelManager m_LM;
    SoundManager m_SM;
    ParticleSystem m_PS;
    Hud m_Hud;
    int m_FramesSinceLastHudUpdate = 0;
    int m_TargetFramesPerHudUpdate = 500;
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
    VertexArray m_VALevel;
    int** m_ArrayLevel = nullptr;
    Texture m_TextureTiles;
    vector<Vector2f> m_FireEmitters;
    Shader m_RippleShader;
    ////////////////////////////////////
    bool detectCollisions(PlayableCharacter& character);
    void populateEmitters(vector<Vector2f>& vSoundEmitters, int** arrayLevel);
    void input();
    void update(float dtAsSeconds);
    void draw();
    void loadLevel();
public:
    Engine();
    void run();
};
