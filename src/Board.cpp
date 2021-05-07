//
// Created by teufel on 8/28/2019.
//

#include "Board.h"

Board::Board(Hand playerOne, Hand playerTwo) {
    if ( playerOne.getNumCards() != Hand::MAX_SIZE ||
        playerTwo.getNumCards() != Hand::MAX_SIZE) {
        throw std::exception();
    }

    handOne = std::move(playerOne);
    handTwo = std::move(playerTwo);
    inPlayOne = inPlayTwo = 0;

    _invert = false;

    for ( int i = 0; i < NUM_LOCATIONS; i++ ) {
        board[i] = Card();
    }
}

void Board::invert() {
    _invert = !(_invert);
}

int Board::mineInPlay() {
    return ( _invert ? inPlayTwo : inPlayOne );
}

int Board::mineInHand() {
    return ( _invert ?
        handTwo.getNumCards() :
        handOne.getNumCards());
}

Card Board::fromMyHand(int index) {
    return (_invert ?
        handTwo.getCard(index) :
        handOne.getCard(index));
}

int Board::oppInPlay() {
    return ( _invert ? inPlayOne : inPlayTwo);
}

int Board::oppInHand() {
    return ( _invert ?
         handOne.getNumCards() :
         handTwo.getNumCards());
}

Card Board::fromOppHand(int index) {
    return (_invert ?
        handOne.getCard(index) :
        handTwo.getCard(index));
}

bool Board::isEmpty(int space) {
    return (board[space].isNull());
}

std::string Board::getEmptySpaceDisplay() {
    std::string ret;
    for ( int i = 0; i < Board::NUM_LOCATIONS; i++ ) {
        if ( i % 3 != 0)
            ret += " ";
        if ( board[i].isNull() )
            ret += std::to_string( i + 1 );
        else
            ret += "-";
        if ( i % 3 == 2 && i != Board::NUM_LOCATIONS - 1)
            ret += "\n";
    }
    return ret;
}

void Board::play(int index, int space) {
    /* Compute the move number and grab the card from your hand. */
    if ( ! board[space].isNull() )
        throw std::exception();
    int moveNumber = inPlayOne + inPlayTwo;
    Card card = (_invert ? handTwo.remove(index) : handOne.remove(index));

    /* Place the card on the board */
    board[space] = card;
    if (_invert) {
        inPlayTwo++;
        ownedByOne[space] = false;
    } else {
        inPlayOne++;
        ownedByOne[space] = true;
    }
    locationOfMove[moveNumber] = space;

    /* Check for how many card flips */
    int nFlips = 0;
    // Attack Up
    if ( space >= 3 && !board[space-3].isNull() &&
        ownedByOne[space] != ownedByOne[space - 3] &&
        card.getTop() > board[space - 3].getBottom()) {
        cardsFlipped[moveNumber][nFlips++] = space - 3;
    }
    // Attack Down
    if ( space <= 5 && ! board[space + 3].isNull() &&
        ownedByOne[space] != ownedByOne[space + 3] &&
        card.getBottom() > board[space+3].getTop()) {
        cardsFlipped[moveNumber][nFlips++] = space + 3;
    }
    // Attack Left
    if ( space % 3 != 0 && ! board[space-1].isNull() &&
        ownedByOne[space] != ownedByOne[space - 1] &&
        card.getLeft() > board[space-1].getRight()
    ) {
        cardsFlipped[moveNumber][nFlips++] = space - 1;
    }
    // Attack Right
    if ( space % 3 != 2 && ! board[space + 1].isNull() &&
        ownedByOne[space] != ownedByOne[space + 1] &&
        card.getRight() > board[space+1].getLeft()) {
        cardsFlipped[moveNumber][nFlips++] = space + 1;
    }

    flippedByMove[moveNumber] = nFlips;
    if ( _invert ) {
        inPlayTwo += nFlips;
        inPlayOne -= nFlips;
        for ( int i = 0; i < nFlips; i++ )
            ownedByOne[cardsFlipped[moveNumber][i]] = false;
    } else {
        inPlayOne += nFlips;
        inPlayTwo -= nFlips;
        for ( int i = 0; i < nFlips; i++ )
            ownedByOne[cardsFlipped[moveNumber][i]] = true;
    }
}

void Board::undo() {
    /* Determine the move number of the previous move */
    int prevMove = inPlayOne + inPlayTwo - 1;
    if ( prevMove < 0 ) {
        throw std::exception();
    }

    /* Return the card to the hand of whomever played it. */
    int location = locationOfMove[prevMove];
    if ( ownedByOne[location] ) {
        handOne.add(board[location]);
        inPlayOne--;
    } else {
        handTwo.add(board[location]);
        inPlayTwo--;
    }
    board[location] = Card();

    /* Undo any flips that card being played caused */
    int numFlipped = flippedByMove[prevMove];
    for ( int i = 0; i < numFlipped; i++ ) {
        location = cardsFlipped[prevMove][i];
        if (ownedByOne[location]) {
            ownedByOne[location] = false;
            inPlayOne--;
            inPlayTwo++;
        } else {
            ownedByOne[location] = true;
            inPlayOne++;
            inPlayTwo--;
        }
    }
}

std::ostream &operator<<(std::ostream &os, const Board &board) {
    os << "board:\n";
    for (auto space : board.board) {
        os << space << "\n";
    }
    return os;
}
