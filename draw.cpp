#include "engine.h"

void Engine::draw()
{
    m_Window.clear(Color::White);
    m_RippleShader.setUniform("uTime",
                              m_GameTotalTime.asSeconds());
    if (!m_SplitScreen) {
        m_Window.setView(m_BGMainView);
//        m_Window.draw(m_BackgroundSprite);
        m_Window.draw(m_BackgroundSprite, &m_RippleShader);
        m_Window.setView(m_MainView);
        m_Window.draw(m_VALevel, &m_TextureTiles);
        m_Window.draw(m_Thomas.getSprite());
        m_Window.draw(m_Bob.getSprite());
        if (m_PS.running())
            m_Window.draw(m_PS);
    } else {
        m_Window.setView(m_BGLeftView);
//        m_Window.draw(m_BackgroundSprite);
        m_Window.draw(m_BackgroundSprite, &m_RippleShader);
        m_Window.setView(m_LeftView);
        m_Window.draw(m_VALevel, &m_TextureTiles);
        m_Window.draw(m_Bob.getSprite());
        m_Window.draw(m_Thomas.getSprite());
        if (m_PS.running())
            m_Window.draw(m_PS);
        ///////////////////////////////////////////////
        m_Window.setView(m_BGRightView);
//        m_Window.draw(m_BackgroundSprite);
        m_Window.draw(m_BackgroundSprite, &m_RippleShader);
        m_Window.setView(m_RightView);
        m_Window.draw(m_VALevel, &m_TextureTiles);
        m_Window.draw(m_Thomas.getSprite());
        m_Window.draw(m_Bob.getSprite());
        if (m_PS.running())
            m_Window.draw(m_PS);
    }
    m_Window.setView(m_HudView);
    m_Window.draw(m_Hud.getLevel());
    m_Window.draw(m_Hud.getTime());
    if (!m_Playing)
        m_Window.draw(m_Hud.getMessage());
    m_Window.display();
}
