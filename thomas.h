#ifndef THOMAS_H
#define THOMAS_H

#include "playablecharacter.h"
#include "textureholder.h"

class Thomas : public PlayableCharacter
{
public:
    Thomas();
    bool handleInput(const Event& event) override;
};

#endif // THOMAS_H
