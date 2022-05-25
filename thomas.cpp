#include "thomas.h"

Thomas::Thomas()
{
    m_sprite = Sprite(TextureHolder::instance().GetTexture("graphics/thomas.png"));
    m_jumpDuration = .45;
}

bool Thomas::handleInput()
{
    m_justJumped = false;

    if (Keyboard::isKeyPressed(Keyboard::W)) {
        if (!m_isJumping && !m_isFalling) {
            m_isJumping = true;
            m_timeThisJump = 0;
            m_justJumped = true;
        }
    } else {
        stopJump();
    }
    if (Keyboard::isKeyPressed(Keyboard::A))
        m_leftPressed = true;
    else
        m_leftPressed = false;
    if (Keyboard::isKeyPressed(Keyboard::D))
        m_rightPressed = true;
    else
        m_rightPressed = false;
    return m_justJumped;
}
