//
// Created by teufel on 8/28/2019.
//

#include "Hand.h"

Hand::Hand() : cards(std::vector<Card>(Hand::MAX_SIZE)), numCards(0) {}

void Hand::add(Card card) {
    if ( numCards == Hand::MAX_SIZE )
        throw std::exception();

    int i = numCards;
    while (i > 0 && cards[i-1].compareTo(card) < 0) {
        cards[i] = cards[i-1];
        i--;
    }
    cards[i] = card;
    numCards++;
}

Card Hand::getCard(int index) {
    if (index >= numCards)
        throw std::exception();
    return cards[index];
}

Card Hand::remove(int index) {
    if ( index >= numCards )
        throw std::exception();
    Card ret = cards[index];
    for ( int i = index + 1; i < numCards; i++ )
        cards[i-1] = cards[i];
    numCards--;
    return ret;
}

int Hand::getNumCards() const {
    return numCards;
}

std::ostream &operator<<(std::ostream &os, const Hand &hand) {
    os << "cards: ";
    for ( auto card : hand.cards ) {
        os << card << " ";
    }
    os << " numCards: " << hand.numCards;
    return os;
}
