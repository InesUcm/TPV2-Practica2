#pragma once
#include"GameState.h"

class NewGameState : public GameState{
public:
	NewGameState() {}
	virtual ~NewGameState() {}

	virtual void enter() override;
	virtual void leave() override;
	virtual void update() override;
};

