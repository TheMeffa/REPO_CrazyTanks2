#pragma once
#ifndef GameEngine_H

#include "GameMap.h"
#include "Tank.h"


class GameEngine
{
public:
	GameEngine();
	~GameEngine();

	void gameEngine(GameMap& gameMap, Tank& tank, Bullet& bullet);
};

#endif // !GameEngine_H


