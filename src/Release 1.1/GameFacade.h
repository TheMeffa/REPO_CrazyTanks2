#pragma once
#ifndef GameFacade_h
#define GameFacade_h


#include "Tank.h"
#include "GameMap.h"
//#include "FieldPart.h"
//#include "Bullet.h"
#include "Constants.h"
#include "GameEngine.h"


class GameFacade
{
public:
	GameFacade();


	Tank& getRefTank(Tank tank);

	GameEngine gameEngineObject;

	GameMap gameMap;

	GameMap& rGameMap = gameMap;

	Tank heroTank;
	Tank enemyTanks[MAX_ENEMIES];
	
};


#endif // !GameFacade_h