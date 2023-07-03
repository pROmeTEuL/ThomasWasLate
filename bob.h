#ifndef BOB_H
#define BOB_H

#include "playablecharacter.h"

class Bob : public PlayableCharacter
{
public:
    Bob();
    bool handleInput() override;
};

#endif // BOB_H
