#include "engine.h"
#include <sstream>

void Engine::update(float dtAsSeconds)
{
    if (m_NewLevelRequired) {
        m_Thomas.spawn(Vector2f(0, 0), GRAVITY);
        m_Bob.spawn(Vector2f(100, 0), GRAVITY);
        m_TimeRemaining = 10;
        m_NewLevelRequired = false;
        loadLevel();
    }
    if (m_Playing) {
        m_Thomas.update(dtAsSeconds);
        m_Bob.update(dtAsSeconds);
        bool bob_on_thomas = false;
        bool thomas_on_bob = false;
        if (m_Bob.getFeet().intersects(m_Thomas.getHead())) {
            m_Bob.stopFalling(m_Thomas.getHead().top);
            bob_on_thomas = true;
        }
        else if (m_Thomas.getFeet().intersects(m_Bob.getHead())) {
            m_Thomas.stopFalling(m_Bob.getHead().top);
            thomas_on_bob = true;
        }
        if (detectCollisions(m_Thomas, thomas_on_bob) && detectCollisions(m_Bob, bob_on_thomas)) {
            m_NewLevelRequired = true;
            //play goal reached sound
            m_SM.playReachGoal();
        } else {
            detectCollisions(m_Bob, bob_on_thomas);
        }
        m_TimeRemaining -= dtAsSeconds;
        if (m_TimeRemaining <= 0)
            m_NewLevelRequired = true;
    }

    for (auto it = m_FireEmitters.begin(); it != m_FireEmitters.end(); ++it) {
        float posX = (*it).x;
        float posY = (*it).y;
        FloatRect localRect(posX - 250, posY - 250, 500, 500);
        if (m_Thomas.getPosition().intersects(localRect)) {
            m_SM.playFire(Vector2f(posX, posY), m_Thomas.getCenter());
        }
    }
    if(m_SplitScreen) {
        m_LeftView.setCenter(m_Thomas.getCenter());
        m_RightView.setCenter(m_Bob.getCenter());
    } else {
        if (m_Character1)
            m_MainView.setCenter(m_Thomas.getCenter());
        else
            m_MainView.setCenter(m_Bob.getCenter());
    }
    ++m_FramesSinceLastHudUpdate;
    if (m_FramesSinceLastHudUpdate > m_TargetFramesPerHudUpdate) {
        stringstream ssTime;
        stringstream ssLevel;
        ssTime << (int)m_TimeRemaining;
        m_Hud.setTime(ssTime.str());
        ssLevel << "Level: " << m_LM.getCurrentLevel();
        m_Hud.setLevel(ssLevel.str());
        m_FramesSinceLastHudUpdate = 0;
    }
    if (m_PS.running()) {
        m_PS.update(dtAsSeconds);
    }
}
