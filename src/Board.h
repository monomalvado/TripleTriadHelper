//
// Created by teufel on 8/28/2019.
//

#ifndef TRIPLETRIAD_BOARD_H
#define TRIPLETRIAD_BOARD_H


#include "Hand.h"
#include <vector>
#include <exception>
#include <ostream>

class Board {
public:
    const static int NUM_LOCATIONS = 9;
    Board(Hand playerOne, Hand playerTwo);
    void invert();
    int mineInPlay();
    int mineInHand();
    Card fromMyHand(int index);
    int oppInPlay();
    int oppInHand();
    Card fromOppHand(int index);
    bool isEmpty(int space);
    std::string getEmptySpaceDisplay();

    void play(int index, int space);
    void undo();

    friend std::ostream &operator<<(std::ostream &os, const Board &board);

private:
    const static int MAX_FLIP_PER_MOVE = 4;
    Card board[NUM_LOCATIONS];
    Hand handOne;
    Hand handTwo;
    int inPlayOne;
    int inPlayTwo;
    bool ownedByOne[Board::NUM_LOCATIONS];
    int locationOfMove[Board::NUM_LOCATIONS];
    int flippedByMove[Board::NUM_LOCATIONS];
    int cardsFlipped[Board::NUM_LOCATIONS][Board::MAX_FLIP_PER_MOVE];
    bool _invert;
};


#endif //TRIPLETRIAD_BOARD_H
