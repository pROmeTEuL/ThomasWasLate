#include "thomas.h"

Thomas::Thomas()
{
    m_sprite = Sprite(TextureHolder::instance().GetTexture("graphics/thomas.png"));
    m_jumpDuration = .45;
}

bool Thomas::handleInput(const Event &event)
{
    if (event.type != Event::EventType::KeyPressed && event.type != Event::EventType::KeyReleased)
        return m_justJumped;
    m_justJumped = false;
    switch (event.key.code) {
    case Keyboard::Key::W:
        if (event.type == Event::EventType::KeyPressed) {
            if (!m_isJumping && !m_isFalling) {
                m_isJumping = true;
                m_timeThisJump = 0;
                m_justJumped = true;
            }
        } else {
            stopJump();
        }
        break;
    case Keyboard::Key::A:
        m_leftPressed = event.type == Event::EventType::KeyPressed;
        break;
    case Keyboard::Key::D:
        m_rightPressed = event.type == Event::EventType::KeyPressed;
        break;
    default:
        break;
    }
    return m_justJumped;
}
