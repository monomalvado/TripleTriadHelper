//
// Created by teufel on 8/28/2019.
//

#ifndef TRIPLETRIAD_PLAYER_HPP
#define TRIPLETRIAD_PLAYER_HPP

#include <ostream>
#include "Board.h"

class Player {
public:
    explicit Player(std::string name) : name(std::move(name)) {}
    virtual ~Player() = default;
    friend std::ostream &operator<<(std::ostream &os, const Player &player) {
        os << player.name;
        return os;
    }
    virtual void makeMove(Board& board) = 0;
private:
    std::string name;
};

#endif //TRIPLETRIAD_PLAYER_HPP
