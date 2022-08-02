#ifndef PARTICLESYSTEM_H
#define PARTICLESYSTEM_H

#include "particle.h"
#include <cstdlib>
#include <ctime>
#include <vector>
#include <cmath>

using namespace std;

class ParticleSystem : public Drawable
{
    vector<Particle> m_Particles;
    VertexArray m_Verticies;
    float m_Duration;
    bool m_IsRunning = false;
public:
//    ParticleSystem();
    void draw(RenderTarget& target, RenderStates states) const override;
    void init(int count);
    void emitParticles(Vector2f position);
    void update(float elapsed);
    bool running();
};

#endif // PARTICLESYSTEM_H
