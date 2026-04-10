#include "gameOverState.h"

#include "Game.h"
#include "../sdlutils/InputHandler.h"
#include "../sdlutils/SDLUtils.h"
#include "../ecs/EntityManager.h"


void GameOverState::enter() {
    assert(Game::Instance()->getMngr() != nullptr);

    if (Game::Instance()->getMngr()->getEntities(ecs::grp::GHOST).size() == 0) {
        _gameOverMessage = "win";
    }
    if (Game::Instance()->getMngr()->getEntities(ecs::grp::GHOST).size() == 0)
    {
        _gameOverMessage = "gameover";
    }
}

void GameOverState::leave() {

}

void GameOverState::update() {
    auto renderer = sdlutils().renderer();
    SDL_RenderClear(renderer);

    auto& msg = sdlutils().msgs().at(_gameOverMessage);
    msg.render(
        (sdlutils().width() - msg.width()) / 2,
        (sdlutils().height() - msg.height()) / 2
    );

    SDL_RenderPresent(renderer);

    if (ih().keyDownEvent()) {

        Game::Instance()->setState(Game::NEWGAME);
    }
}