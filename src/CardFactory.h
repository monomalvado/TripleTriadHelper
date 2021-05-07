//
// Created by teufel on 2/24/2020.
//

#ifndef TRIPLETRIAD_CARDFACTORY_H
#define TRIPLETRIAD_CARDFACTORY_H

#include "Card.h"

class CardFactory {
public:
    static inline Card get(int index) {
        if ( index < 0 || index > 109 )
            throw std::exception("Index Out of Bounds.");
        return allCards[index];
    }
private:
    static Card allCards[110];
};


#endif //TRIPLETRIAD_CARDFACTORY_H
