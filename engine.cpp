#include "engine.h"

Engine::Engine()
{
    Vector2f resolution;
    resolution.x = VideoMode::getDesktopMode().width;
    resolution.y = VideoMode::getDesktopMode().height;
    m_Window.create(VideoMode(resolution.x, resolution.y), "Thomas was late", Style::Default);
    m_MainView.setSize(resolution);
    m_HudView.reset(FloatRect(0, 0, resolution.x, resolution.y));
    m_LeftView.setViewport(FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
    m_RightView.setViewport(FloatRect(0.5f, 0.001f, 0.499f, 0.998f));
    m_BGLeftView.setViewport(FloatRect(0.001f, 0.001f, 0.498f, 0.998f));
    m_BGRightView.setViewport(FloatRect(0.5f, 0.001f, 0.499f, 0.998f));
    if (!sf::Shader::isAvailable())
        m_Window.close(); // "Time to get a new pc"
    else
        m_RippleShader.loadFromFile("shaders/vertShader.vert",
                                    "shaders/rippleShader.frag");
    m_BackgroundTexture = TextureHolder::instance().GetTexture("graphics/background.png");
    m_BackgroundSprite.setTexture(m_BackgroundTexture);
    m_TextureTiles = TextureHolder::instance().GetTexture("graphics/tiles_sheet.png");
    m_PS.init(1000);
}

void Engine::run()
{
    Clock clock;
    while (m_Window.isOpen()) {
        Time dt = clock.restart();
        m_GameTotalTime += dt;
        float dtAsSeconds = dt.asSeconds();
        input();
        update(dtAsSeconds);
        draw();
    }
}
