// This file is part of the course TPV2@UCM - Samir Genaim

#include "foodSystem.h"

#include <algorithm>
#include "../components/Image.h"
//#include "../components/Points.h"
//#include "../components/StarMotion.h"
#include "../components/Transform.h"
#include "../ecs/EntityManager.h"
#include "../sdlutils/SDLUtils.h"
//#include "GameCtrlSystem.h"

FoodSystem::FoodSystem() :
	_fruitLimit(30), _currNumOfFruits(0) {
}

FoodSystem::~FoodSystem() {
}

void FoodSystem::initSystem() {
}

void FoodSystem::update() {

}

void FoodSystem::addStar(unsigned int n) {

	// Always use the random number generator provided by SDLUtils
	//
	auto& rand = sdlutils().rand();

	auto limit = std::min( //
		static_cast<unsigned int>(n), //
		_fruitLimit - _currNumOfFruits);

	for (auto i = 0; i < limit; i++) {

		// add and entity to the manager
		//
		auto e = _mngr->addEntity(ecs::grp::FRUIT);

		// add a Transform component, and initialise it with random
		// size and position
		//
		auto tr = _mngr->addComponent<Transform>(e);
		auto s = rand.nextInt(50, 100);
		auto x = rand.nextInt(0, sdlutils().width() - s);
		auto y = rand.nextInt(0, sdlutils().height() - s);
		tr->init(Vector2D(x, y), Vector2D(), s, s, 0.0f);

		// add an Image Component
		//
		_mngr->addComponent<Image>(e, &sdlutils().images().at("food"));
	}
}

void FoodSystem::onStarEaten(ecs::entity_t e) {
	_mngr->setAlive(e, false);
	_currNumOfFruits--;

	// play sound on channel 1 (if there is something playing there
	// it will be cancelled
	sdlutils().soundEffects().at("pacman_eat").play("se");
}

void FoodSystem::recieve(const Message& m) {

}
