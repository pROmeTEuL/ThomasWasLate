#ifndef PLAYABLECHARACTER_H
#define PLAYABLECHARACTER_H

#include<SFML/Graphics.hpp>

using namespace sf;

class PlayableCharacter {
    float m_gravity;
    float m_speed = 400;
    Vector2f m_position;
    FloatRect m_feet;
    FloatRect m_head;
    FloatRect m_right;
    FloatRect m_left;
    Texture m_texture;
protected:
    Sprite m_sprite;
    float m_jumpDuration;
    bool m_isJumping;
    bool m_isFalling;
    bool m_leftPressed;
    bool m_rightPressed;
    float m_timeThisJump;
    bool m_justJumped;
public:
    void spawn(Vector2f startPosition, float gravity);
    bool virtual handleInput(const Event& event) = 0;
    FloatRect getPosition();
    FloatRect getFeet();
    FloatRect getHead();
    FloatRect getRight();
    FloatRect getLeft();
    Sprite getSprite();
    void stopFalling(float position);
    void stopRight(float position);
    void stopLeft(float position);
    void stopJump();
    Vector2f getCenter();
    void update(float elapsedTime);
    bool getJump();
};

#endif // PLAYABLECHARACTER_H
