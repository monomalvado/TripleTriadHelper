//
// Created by teufel on 8/28/2019.
//

#ifndef TRIPLETRIAD_HAND_H
#define TRIPLETRIAD_HAND_H


#include "Card.h"
#include <exception>
#include <ostream>

class Hand {
public:
    const static int MAX_SIZE = 5;

    Hand();

    void add(Card card);
    Card getCard(int index);
    Card remove(int index);
    int getNumCards() const;

    friend std::ostream &operator<<(std::ostream &os, const Hand &hand);

private:
    std::vector<Card> cards;
    int numCards;
};


#endif //TRIPLETRIAD_HAND_H
