#include "newRoundState.h"

#include "Game.h"
#include "../sdlutils/InputHandler.h"
#include "../sdlutils/SDLUtils.h"

void NewRoundState::enter() {

}

void NewRoundState::leave() {

}

void NewRoundState::update() {
    auto renderer = sdlutils().renderer();
    SDL_RenderClear(renderer);

    auto& msg = sdlutils().msgs().at("newround");
    msg.render(
        (sdlutils().width() - msg.width()) / 2,
        (sdlutils().height() - msg.height()) / 2
    );

    SDL_RenderPresent(renderer);

    if (ih().isKeyDown(SDLK_RETURN)) {

        Game::Instance()->setState(Game::RUNNING);
    }
}