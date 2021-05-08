//
// Created by teufel on 8/29/2019.
//

#include "Game.h"
#include "Keyboard.hpp"

void Game::playNew() {
    /* Get user input */
    Hand handOne = getHand(one);
    std::cout << std::endl;
    Hand handTwo = getHand(two);
    std::cout << std::endl;
    std::cout << "Is " << *one << " going first? " << std::flush;
    bool playerOneTurn = Keyboard::readYesNo("");

    /* Create the board */
    Board board = Board(handOne, handTwo);
    if (!playerOneTurn)
        board.invert();

    /* Play until all spaces are filled */
    for ( int turn = 0; turn < Board::NUM_LOCATIONS; turn++ ) {
        std::cout << std::endl;
        if ( playerOneTurn ) {
            std::cout << "Time for " << *one << " to move" << std::endl;
            one->makeMove(board);
        } else {
            std::cout << "Time for " << *two << " to move" << std::endl;
            two->makeMove(board);
        }
        playerOneTurn = !(playerOneTurn);
        board.invert();
    }

    /* Compute final score */
    if (!playerOneTurn)
        board.invert();
    int oneScore = board.mineInPlay() + board.mineInHand();
    int twoScore = board.oppInPlay() + board.oppInHand();
    std::cout << std::endl << "Final score:" << std::endl
              << *one << " - " << oneScore << std::endl
              << *two << " - " << twoScore << std::endl;
}

void Game::playNew(Hand& handOne, Hand& handTwo) {
    bool playerOneTurn = true;
    /* Create the board */
    Board board = Board(handOne, handTwo);
    if (!playerOneTurn)
        board.invert();

    /* Play until all spaces are filled */
    for ( int turn = 0; turn < Board::NUM_LOCATIONS; turn++ ) {
        std::cout << std::endl;
        if ( playerOneTurn ) {
            std::cout << "Time for " << *one << " to move" << std::endl;
            one->makeMove(board);
        } else {
            std::cout << "Time for " << *two << " to move" << std::endl;
            two->makeMove(board);
        }
        playerOneTurn = !(playerOneTurn);
        board.invert();
    }

    /* Compute final score */
    if (!playerOneTurn)
        board.invert();
    int oneScore = board.mineInPlay() + board.mineInHand();
    int twoScore = board.oppInPlay() + board.oppInHand();
    std::cout << std::endl << "Final score:" << std::endl
              << *one << " - " << oneScore << std::endl
              << *two << " - " << twoScore << std::endl;
}

std::ostream &operator<<(std::ostream &os, const Game &game) {
    os << *game.one << std::endl << *game.two << std::endl;
    return os;
}

Hand Game::getHand(Player* player) {
    std::cout << "Input a hand for " << *player << std::endl;
    Hand hand = Hand();
    for ( int i = 0; i < Hand::MAX_SIZE; i++ ) {
        Card c = Card::read();
        hand.add(c);
    }
    return hand;
}
