#include "pausedState.h"
#include "Game.h"
#include "../sdlutils/InputHandler.h"
#include "../sdlutils/SDLUtils.h"
#include "../ecs/Entity.h"
#include "../ecs/EntityManager.h"
#include "../components/Transform.h"
#include <cstdint>
#include <limits>

constexpr int REMAINING_ASTEROIDS_TEXT_X = 10;
constexpr int REMAINING_ASTEROIDS_TEXT_Y = 40;
constexpr int MIN_DISTANCE_TEXT_X = 10;
constexpr int MIN_DISTANCE_TEXT_Y = 64;

void PausedState::enter() {
    sdlutils().virtualTimer().pause();

    assert(Game::Instance()->getMngr()!= nullptr);
}

void PausedState::leave() {
    sdlutils().virtualTimer().resume();
}

void PausedState::update() {
    auto renderer = sdlutils().renderer();

    SDL_RenderClear(renderer);

    //se renderizan las vidas del jugador
    //Game::Instance()->getMngr()->getEntities(ecs::grp::PLAYER).front()->getComponent<Health>()->render();

    //renderiza cuantos asteroides quedan
    _remainingAsteroids->render(REMAINING_ASTEROIDS_TEXT_X, REMAINING_ASTEROIDS_TEXT_Y);

    //renderiza cuanta es la distancia minima hasta un asteroide
    _minDistanceToAsteroid->render(MIN_DISTANCE_TEXT_X, MIN_DISTANCE_TEXT_Y);

    sdlutils().msgs().at("paused").render((sdlutils().width() - sdlutils().msgs().at("paused").width()) / 2, (sdlutils().height() - sdlutils().msgs().at("paused").height()) / 2);

    SDL_RenderPresent(renderer);

    if (ih().keyDownEvent()) {

        Game::Instance()->setState(Game::RUNNING);
    }
}