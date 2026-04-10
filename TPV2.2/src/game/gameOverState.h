#pragma once
#include"GameState.h"

class GameOverState : public GameState
{
public:
	GameOverState() {}
	virtual ~GameOverState() {}

	virtual void enter() override;
	virtual void leave() override;
	virtual void update() override;
private:
	const char* _gameOverMessage = nullptr;
};

