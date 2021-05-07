//
// Created by teufel on 8/29/2019.
//

#ifndef TRIPLETRIAD_GAME_H
#define TRIPLETRIAD_GAME_H


#include <ostream>
#include "PlayerAI.h"
#include "PlayerHuman.h"

class Game {
public:
    Game(Player* one, Player* two) : one(one), two(two) {}
    void playNew();
    void playNew(Hand& handOne, Hand& handTwo);

    friend std::ostream &operator<<(std::ostream &os, const Game &game);

private:
    Player* one;
    Player* two;
    Hand getHand(Player* player);
};


#endif //TRIPLETRIAD_GAME_H
