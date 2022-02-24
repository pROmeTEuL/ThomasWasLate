#include "engine.h"

void Engine::draw()
{
    m_Window.clear(Color::White);
    if (!m_SplitScreen) {
        m_Window.setView(m_BGMainView);
        m_Window.draw(m_BackgroundSprite);
        m_Window.setView(m_MainView);
    } else {
        m_Window.setView(m_BGLeftView);
        m_Window.draw(m_BackgroundSprite);
        m_Window.setView(m_BGRightView);
        m_Window.draw(m_BackgroundSprite);
        m_Window.setView(m_RightView);
    }
    m_Window.setView(m_HudView);
    m_Window.display();
}
