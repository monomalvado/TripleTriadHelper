//
// Created by teufel on 5/7/2021.
//

#include "src/Card.h"
#include "src/Game.h"
#include "src/CardFactory.h"

int main(int argc, char** argv) {

    auto x = new PlayerAI("Human Player");
    auto y = new PlayerAI("FFVIII");
    Game game = Game(x, y);

    Hand handOne = Hand();
    handOne.add( CardFactory::get(109) );
    handOne.add( CardFactory::get(108) );
    handOne.add( CardFactory::get(107) );
    handOne.add( CardFactory::get(106) );
    handOne.add( CardFactory::get(105) );

    Hand handTwo = Hand();
    handTwo.add( CardFactory::get(95) );
    handTwo.add( CardFactory::get(86) );
    handTwo.add( CardFactory::get(99) );
    handTwo.add( CardFactory::get(88) );
    handTwo.add( CardFactory::get(91) );

    game.playNew(handOne, handTwo);

    return 0;
}