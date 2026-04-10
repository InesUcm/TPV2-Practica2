#pragma once
#include"GameState.h"
#include <cstdint>

class RunningState : public GameState
{
public:
	RunningState() {}
	virtual ~RunningState() {}

	virtual void enter() override;
	virtual void leave() override;
	virtual void update() override;

private:
	void checkCollision();

	uint64_t _lastTimeAsteroidCreated = 0;
};

