#pragma once
#include"GameState.h"

class NewRoundState : public GameState
{
public:
	NewRoundState() {}
	virtual ~NewRoundState() {}

	virtual void enter() override;
	virtual void leave() override;
	virtual void update() override;
};

