//
// Created by teufel on 8/28/2019.
//

#include "PlayerHuman.h"

PlayerHuman::PlayerHuman(std::string name) : Player(std::move(name)) {}

void PlayerHuman::makeMove(Board& board) {
    int card = getCardIndex(board);
    int pos = getPosition(board);
    board.play(card, pos);
}

int PlayerHuman::getCardIndex(Board board) {
    std::cout << "Available cards:" << std::endl;
    int numCards = board.mineInHand();
    for (int i = 0; i < numCards; i++) {
        std::cout << "- " << board.fromMyHand(i) << std::endl;
    }

    /* Pick a card to play */
    int toPlay = -1;
    while ( toPlay == -1 ) {
        Card input = Card::read();
        for ( int i = 0; i < numCards; i++ ) {
            if ( input == board.fromMyHand(i) ) {
                toPlay = i;
                break;
            }
        }
        if ( toPlay == -1 )
            std::cout << "Card does not match any card in hand." << std::endl;
    }

    return toPlay;
}

int PlayerHuman::getPosition(Board board) {
    /* Display available positions */
    std::cout << "Available locations:" << std::endl << board.getEmptySpaceDisplay() << std::endl;

    /* Get a position to play */
    int posToPlay = -1;
    while ( posToPlay == -1 ) {
        std::cout << "Choose a location: ";
        std::cin >> posToPlay;
        if ( posToPlay < 0 || posToPlay >= Board::NUM_LOCATIONS || ! board.isEmpty(posToPlay) ) {
            std::cout << "Invalid location" << std::endl;
            posToPlay = -1;

        }
    }
    return posToPlay;
}
