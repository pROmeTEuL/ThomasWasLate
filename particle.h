#ifndef PARTICLE_H
#define PARTICLE_H

#include <SFML/Graphics.hpp>

using namespace sf;

class Particle
{
    Vector2f m_Position;
    Vector2f m_Velocity;
public:
    Particle(Vector2f direction);
    void update(float dtAsSeconds);
    void setPosition(Vector2f postition);
    Vector2f getPosition();
};

#endif // PARTICLE_H
