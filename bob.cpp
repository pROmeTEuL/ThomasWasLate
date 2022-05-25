#include "bob.h"
#include "textureholder.h"

Bob::Bob()
{
    m_sprite = Sprite(TextureHolder::instance().GetTexture("graphics/bob.png"));
    m_jumpDuration = .25;
}


bool Bob::handleInput()
{
    m_justJumped = false;

    if (Keyboard::isKeyPressed(Keyboard::Up)) {
        if (!m_isJumping && !m_isFalling) {
            m_isJumping = true;
            m_timeThisJump = 0;
            m_justJumped = true;
        }
    } else {
        stopJump();
    }
    if (Keyboard::isKeyPressed(Keyboard::Left))
        m_leftPressed = true;
    else
        m_leftPressed = false;
    if (Keyboard::isKeyPressed(Keyboard::Right))
        m_rightPressed = true;
    else
        m_rightPressed = false;
    return m_justJumped;
}
