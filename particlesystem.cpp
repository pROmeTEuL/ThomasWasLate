#include "particlesystem.h"

//ParticleSystem::ParticleSystem()
//{

//}


void ParticleSystem::draw(RenderTarget &target, RenderStates states) const
{
    target.draw(m_Verticies, states);
}

void ParticleSystem::init(int count)
{
    m_Verticies.setPrimitiveType(Points);
    m_Verticies.resize(count);
    for (int i = 0; i < count; ++i) {
        srand(time(0) + i);
        float angle = (rand() % 360) * 3.14f / 180.f;
        float speed = (rand() % 600) * 600.f;
        Vector2f direction = Vector2f(cos(angle) * speed, sin(angle) * speed);
        m_Particles.push_back(Particle(direction));
    }
}

void ParticleSystem::emitParticles(Vector2f position)
{
    m_IsRunning = true;
    m_Duration = 2;
    int currentVertex = 0;
    for (auto el : m_Particles) {
        m_Verticies[currentVertex++].color = Color::Yellow;
        el.setPosition(position);
    }
}

void ParticleSystem::update(float elapsed)
{
    m_Duration -= elapsed;
    int currentVertext = 0;
    for (auto& el : m_Particles) {
        el.update(elapsed);
        m_Verticies[currentVertext++].position = el.getPosition();
    }
    if (m_Duration < 0)
        m_IsRunning = false;
}

bool ParticleSystem::running()
{
    return m_IsRunning;
}
