#include "soundmanager.h"

SoundManager::SoundManager()
{
    //buffers
    m_FireBuffer.loadFromFile("sound/fire1.wav");
    m_FallInFireBuffer.loadFromFile("sound/fallinfire.wav");
    m_FallInWaterBuffer.loadFromFile("sound/fallinwater.wav");
    m_JumpBuffer.loadFromFile("sound/jump.wav");
    m_ReachGoalBuffer.loadFromFile("sound/reachgoal.wav");
    //sounds
    m_Fire1Sound.setBuffer(m_FireBuffer);
    m_Fire2Sound.setBuffer(m_FireBuffer);
    m_Fire3Sound.setBuffer(m_FireBuffer);
    m_FallInFireSound.setBuffer(m_FallInFireBuffer);
    m_FallInWaterSound.setBuffer(m_FallInWaterBuffer);
    m_JumpSound.setBuffer(m_JumpBuffer);
    m_ReachGoalSound.setBuffer(m_ReachGoalBuffer);
    //spatial sound settings
    float minDistance = 150;
    float attenuation = 15;
    m_Fire1Sound.setAttenuation(attenuation);
    m_Fire2Sound.setAttenuation(attenuation);
    m_Fire3Sound.setAttenuation(attenuation);
    m_Fire1Sound.setMinDistance(minDistance);
    m_Fire2Sound.setMinDistance(minDistance);
    m_Fire3Sound.setMinDistance(minDistance);
    m_Fire1Sound.setLoop(true);
    m_Fire2Sound.setLoop(true);
    m_Fire3Sound.setLoop(true);
}

void SoundManager::playFire(Vector2f emitterLocation, Vector2f listenerLocation)
{
    Listener::setPosition(listenerLocation.x, listenerLocation.y, 0.0f);
    switch(m_nextSound) {
    case 1:
        m_Fire1Sound.setPosition(emitterLocation.x, listenerLocation.y, 0.0f);
        if (m_Fire1Sound.getStatus() == Sound::Status::Stopped)
            m_Fire1Sound.play();
        break;
    case 2:
        m_Fire2Sound.setPosition(emitterLocation.x, listenerLocation.y, 0.0f);
        if (m_Fire2Sound.getStatus() == Sound::Status::Stopped)
            m_Fire2Sound.play();
        break;
    case 3:
        m_Fire3Sound.setPosition(emitterLocation.x, listenerLocation.y, 0.0f);
        if (m_Fire3Sound.getStatus() == Sound::Status::Stopped)
            m_Fire3Sound.play();
        break;
    }
    ++m_nextSound;
    if (m_nextSound > 3)
        m_nextSound = 1;
}

void SoundManager::playFallInFire()
{
    m_FallInFireSound.setRelativeToListener(true);
    m_FallInFireSound.play();
}

void SoundManager::playFallInWater()
{
    m_FallInWaterSound.setRelativeToListener(true);
    m_FallInWaterSound.play();
}

void SoundManager::playJump()
{
    m_JumpSound.setRelativeToListener(true);
    m_JumpSound.play();
}

void SoundManager::playReachGoal()
{
    m_ReachGoalSound.setRelativeToListener(true);
    m_ReachGoalSound.play();
}
