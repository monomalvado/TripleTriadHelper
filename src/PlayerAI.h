//
// Created by teufel on 8/29/2019.
//

#ifndef TRIPLETRIAD_PLAYERAI_H
#define TRIPLETRIAD_PLAYERAI_H

#include <chrono>
#include <limits>
#include <iostream>
#include "Board.h"
#include "Card.h"
#include "Player.hpp"

class PlayerAI : public Player {
public:
    explicit PlayerAI(std::string name);
    ~PlayerAI() override = default;
    void makeMove(Board& board) override;
private:
    const static int MIN_BOUND = INT_MIN + 10;
    const static int MAX_BOUND = INT_MAX - 10;
    int recordDepth;
    int bestCard;
    int bestSpace;
    int alphaBeta(int depth, int alpha, int beta, Board board);
    int evaluate(Board& board);
};

#endif //TRIPLETRIAD_PLAYERAI_H
