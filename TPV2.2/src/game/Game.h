// This file is part of the course TPV2@UCM - Samir Genaim

#pragma once
#include "GameState.h"
#include "../utils/Singleton.h"
#include "../ecs/ecs.h"

namespace ecs {
class EntityManager;
}

class GameState;
class Game : public Singleton<Game> {
public:
	friend Singleton<Game>;

	virtual ~Game();
	bool init();
	void start();

	void initGame();

	enum State {
		RUNNING,
		PAUSED, 
		NEWGAME, 
		NEWROUND, 
		GAMEOVER
	};

	inline void setState(State s) {
		_state->leave();
		switch (s) {
		case RUNNING:
			_state = _runing_state;
			break;
		case PAUSED:
			_state = _paused_state;
			break;
		case NEWGAME:
			_state = _newgame_state;
			break;
		case NEWROUND:
			_state = _newround_state;
			break;
		case GAMEOVER:
			_state = _gameover_state;
			break;
		default:
			break;
		}
		_state->enter();
	}

	ecs::EntityManager* getMngr() { return _mngr; }
	
private:
	Game();

	GameState* _state = nullptr;
	GameState* _paused_state = nullptr;
	GameState* _runing_state = nullptr;
	GameState* _newgame_state = nullptr;
	GameState* _newround_state = nullptr;
	GameState * _gameover_state = nullptr;

	void checkCollisions();

	GameState* _gameState = nullptr;
	bool _run = true;

	ecs::EntityManager* _mngr;
	ecs::System* _pacmanSys;
	ecs::System* _ghostSys;
	ecs::System* _startsSys;
	ecs::System* _renderSys;
	ecs::System* _collisionSys;
};
