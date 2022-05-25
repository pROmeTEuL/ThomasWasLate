#include "playablecharacter.h"


void PlayableCharacter::spawn(Vector2f startPosition, float gravity)
{
    m_position.x = startPosition.x;
    m_position.y = startPosition.y;
    m_gravity = gravity;
    m_sprite.setPosition(m_position);
}

FloatRect PlayableCharacter::getPosition()
{
    return m_sprite.getGlobalBounds();
}

FloatRect PlayableCharacter::getFeet()
{
    return m_feet;
}

FloatRect PlayableCharacter::getHead()
{
    return m_head;
}

FloatRect PlayableCharacter::getRight()
{
    return m_right;
}

FloatRect PlayableCharacter::getLeft()
{
    return m_left;
}

Sprite PlayableCharacter::getSprite()
{
    return m_sprite;
}

void PlayableCharacter::stopFalling(float position)
{
    m_position.y = position - getPosition().height;
    m_sprite.setPosition(m_position);
    m_isFalling = false;
}

void PlayableCharacter::stopRight(float position)
{
    m_position.x = position - m_sprite.getGlobalBounds().width;
    m_sprite.setPosition(m_position);
}

void PlayableCharacter::stopLeft(float position)
{
    m_position.x = position + m_sprite.getGlobalBounds().width;
    m_sprite.setPosition(m_position);
}

void PlayableCharacter::stopJump()
{
    m_isJumping = false;
    m_isFalling = true;
}

Vector2f PlayableCharacter::getCenter()
{
    return Vector2f {
        m_position.x + m_sprite.getGlobalBounds().width / 2,
        m_position.y + m_sprite.getGlobalBounds().height / 2
    };
}

void PlayableCharacter::update(float elapsedTime)
{
    if(m_rightPressed)
        m_position.x += m_speed * elapsedTime;
    if (m_leftPressed)
        m_position.x -= m_speed * elapsedTime;
    if (m_isJumping) {
        m_timeThisJump += elapsedTime;
        if (m_timeThisJump < m_jumpDuration)
            m_position.y -= m_gravity * 2 * elapsedTime;
        else
            stopJump();
    }
    if (m_isFalling)
        m_position.y += m_gravity * elapsedTime;
    FloatRect rect = getPosition();
    //feet
    m_feet.left = rect.left + 3;
    m_feet.top = rect.top + rect.height - 1;
    m_feet.width = rect.width - 6;
    m_feet.height = 1;
    //head
    m_head.left = rect.left;
    m_head.top = rect.top + (rect.height * .3);
    m_head.width = rect.width;
    m_head.height = 1;
    //right
    m_right.left = rect.left + rect.width - 2;
    m_right.top = rect.top + rect.height * .35;
    m_right.width = 1;
    m_right.height = rect.height * .3;
    //left
    m_left.left = rect.left;
    m_left.top = rect.top + rect.height * .5;
    m_left.width = 1;
    m_left.height = rect.height * .3;


    m_sprite.setPosition(m_position);
}
