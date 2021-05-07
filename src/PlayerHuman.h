//
// Created by teufel on 8/28/2019.
//

#ifndef TRIPLETRIAD_PLAYERHUMAN_H
#define TRIPLETRIAD_PLAYERHUMAN_H

#include <iostream>
#include "Board.h"
#include "Card.h"
#include "Player.hpp"

class PlayerHuman : public Player {
public:
    explicit PlayerHuman(std::string name);
    ~PlayerHuman() override = default;
    void makeMove(Board& board) override;
private:
    int getCardIndex(Board board);
    int getPosition(Board board);
};


#endif //TRIPLETRIAD_PLAYERHUMAN_H
