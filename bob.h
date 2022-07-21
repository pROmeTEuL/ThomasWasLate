#ifndef BOB_H
#define BOB_H

#include "playablecharacter.h"

class Bob : public PlayableCharacter
{
public:
    Bob();
    bool handleInput(const Event& event) override;
};

#endif // BOB_H
