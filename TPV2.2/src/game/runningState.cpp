#include "runningState.h"


#include "Game.h"
#include "../sdlutils/InputHandler.h"
#include "../sdlutils/SDLUtils.h"
#include "../ecs/EntityManager.h"
#include "../components//Transform.h"
#include "../ecs/Entity.h"
#include "../utils/Collisions.h"

#include "../systems/collisionsSystem.h"
#include "../systems/ghostSystem.h"
//#include "../systems/gameCtrlSystem.h"
#include "../systems/pacManSystem.h"
#include "../systems/renderSystem.h"
#include "../systems/foodSystem.h"

constexpr int ASTEROIDS_SPAWN_COOLDOWN = 5000;

void RunningState::enter() {

}

void RunningState::leave() {

}

void RunningState::update() {
    assert(Game::Instance()->getMngr() != nullptr);

    // Lógica de juego
    //if (ih().isKeyDown(SDLK_P)) {
    //    Game::Instance()->setState(Game::PAUSED);
    //    return;
    //}

    //if (Game::Instance()->getMngr()->getEntities(ecs::grp::GHOST).size() == 0) {
    //    Game::Instance()->setState(Game::GAMEOVER);
    //    return;
    //}

    // Actualizar sistemas (antes los llamabas siempre en Game::start())
    auto* mngr = Game::Instance()->getMngr();
    mngr->getSystem<PacManSystem>()->update();
    mngr->getSystem<FoodSystem>()->update();
    mngr->getSystem<GhostSystem>()->update();
    mngr->getSystem<CollisionsSystem>()->update();

    checkCollision();

    sdlutils().clearRenderer();
    mngr->getSystem<RenderSystem>()->update();
    sdlutils().presentRenderer();
}

void RunningState::checkCollision() {

}