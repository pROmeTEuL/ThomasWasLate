#ifndef SOUNDMANAGER_H
#define SOUNDMANAGER_H
#include <SFML/Audio.hpp>

using namespace sf;

class SoundManager
{
    //buffers
    SoundBuffer m_FireBuffer;
    SoundBuffer m_FallInFireBuffer;
    SoundBuffer m_FallInWaterBuffer;
    SoundBuffer m_JumpBuffer;
    SoundBuffer m_ReachGoalBuffer;
    //sounds
    Sound m_Fire1Sound;
    Sound m_Fire2Sound;
    Sound m_Fire3Sound;
    Sound m_FallInFireSound;
    Sound m_FallInWaterSound;
    Sound m_JumpSound;
    Sound m_ReachGoalSound;
    // next fire sound
    int m_nextSound = 1;
public:
    SoundManager();
    void playFire(Vector2f emitterLocation, Vector2f listenerLocation);
    void playFallInFire();
    void playFallInWater();
    void playJump();
    void playReachGoal();
};

#endif // SOUNDMANAGER_H
