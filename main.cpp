#include <napi.h>
#include "src/Player.hpp"
#include "src/PlayerHuman.h"
#include "src/PlayerAI.h"
#include "src/Game.h"
#include "src/Keyboard.hpp"
#include "src/CardFactory.h"

int main() {
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

Napi::Number MainWrapper(const Napi::CallbackInfo &info) {
    const Napi::Env env = info.Env();

    int result = main();

    return Napi::Number::New(env, result);
}

Napi::Object Init(Napi::Env env, Napi::Object exports) {
    exports.Set("main", Napi::Function::New(env, MainWrapper));
    return exports;
}

NODE_API_MODULE(NODE_GYP_MODE_NAME, Init)