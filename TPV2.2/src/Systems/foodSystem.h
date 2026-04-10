// This file is part of the course TPV2@UCM - Samir Genaim

#pragma once
#include "../ecs/System.h"

class FoodSystem : public ecs::System
{
public:

	FoodSystem();
	virtual ~FoodSystem();
	void initSystem() override;
	void update() override;
	void addStar(unsigned int n);
	void onStarEaten(ecs::entity_t e);
	void recieve(const Message& m) override;
private:
	unsigned int _fruitLimit;
	unsigned int _currNumOfFruits;
};
