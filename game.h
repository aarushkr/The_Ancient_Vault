#ifndef GAME
#define GAME

#include "player.h"

namespace Encounter {
    bool Monster(Player& p);
    bool Treasure(Player& p);
    void Trap(Player& p);
}

bool Shop(Player& p); //returns false if shopping is not possible
void Display_stats(Player& p);

#endif