#pragma once
#include"GameState.h"

class Texture;
class PausedState : public GameState
{
public:
	PausedState() {}
	virtual ~PausedState() {}

	virtual void enter() override;
	virtual void leave() override;
	virtual void update() override;
private:
	Texture* _remainingAsteroids = nullptr;
	Texture* _minDistanceToAsteroid = nullptr;
};

