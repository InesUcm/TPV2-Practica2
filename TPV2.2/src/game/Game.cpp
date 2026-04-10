// This file is part of the course TPV2@UCM - Samir Genaim

#include "Game.h"

#include "newGameState.h"
#include "newRoundState.h"
#include "runningState.h"
#include "pausedState.h"
#include "gameOverState.h"

#include "../systems/collisionsSystem.h"
#include "../systems/ghostSystem.h"
//#include "../systems/gameCtrlSystem.h"
#include "../systems/pacManSystem.h"
#include "../systems/renderSystem.h"
#include "../systems/foodSystem.h"

#include "../ecs/EntityManager.h"
#include "../sdlutils/InputHandler.h"
#include "../sdlutils/SDLUtils.h"
#include "../utils/Vector2D.h"
using ecs::EntityManager;

Game::Game() :
	_mngr(), //
	_pacmanSys(), //
	_ghostSys(), //
	_startsSys(), //
	_renderSys(), //
	_collisionSys() {

	_newgame_state = new NewGameState();
	_newround_state = new NewRoundState();
	_runing_state = new RunningState();
	_paused_state = new PausedState();
	_gameover_state = new GameOverState();

	_state = _newgame_state;
	_state->enter();
}

Game::~Game() {
	delete _mngr;

	// release InputHandler if the instance was created correctly.
	if (InputHandler::HasInstance())
		InputHandler::Release();

	// release SLDUtil if the instance was created correctly.
	if (SDLUtils::HasInstance())
		SDLUtils::Release();
}

bool Game::init() {

	// initialize the SDL singleton
	if (!SDLUtils::Init("PacMan, Stars, ...", 800, 600,
		"resources/config/resources.json")) {

		std::cerr << "Something went wrong while initializing SDLUtils"
			<< std::endl;
		return false;
	}

	// initialize the InputHandler singleton
	if (!InputHandler::Init()) {
		std::cerr << "Something went wrong while initializing SDLHandler"
			<< std::endl;
		return false;
	}
	
	// Create the manager
	_mngr = new EntityManager();

	// add the systems
	_pacmanSys = _mngr->addSystem<PacManSystem>();
	_ghostSys = _mngr->addSystem<GhostSystem>();
	_startsSys = _mngr->addSystem<FoodSystem>();
	_renderSys = _mngr->addSystem<RenderSystem>();
	_collisionSys = _mngr->addSystem<CollisionsSystem>();

	return true;
}

void Game::initGame() {
	//se crea el entityManager
	//_mngr = new EntityManager();

}

void Game::start() {

	// a boolean to exit the loop
	bool exit = false;

	auto& ihdlr = ih();

	//auto& vt = sdlutils().virtualTimer();
	//vt.resetTime();

	while (!exit) {
		Uint32 startTime = sdlutils().currRealTime();

		// refresh the input handler
		ihdlr.refresh();

		if (ihdlr.isKeyDown(SDL_SCANCODE_ESCAPE)) {
			exit = true;
			continue;
		}

		_state->update();
		_mngr->flushMessages();

		Uint32 frameTime = sdlutils().currRealTime() - startTime;

		if (frameTime < 10)
			SDL_Delay(10 - frameTime);
	}
}

