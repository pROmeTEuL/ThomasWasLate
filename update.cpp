#include "engine.h"
#include <sstream>

void Engine::update(float dtAsSeconds)
{
    if (m_Playing) {
        m_TimeRemaining -= dtAsSeconds;
        if (m_TimeRemaining <= 0)
            m_NewLevelRequired = true;
    }
}
