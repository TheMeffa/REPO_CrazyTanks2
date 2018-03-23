#pragma once
#ifndef GameFacade_h
#define GameFacade_h


#include "Tank.h"
#include "GameMap.h"
#include "FieldPart.h"
#include "Bullet.h"
#include "Constants.h"


class GameFacade
{
public:
	GameFacade();
	~GameFacade();

	bool getGameIsPlaying();
	
	Tank heroTank;
	Tank enemyTanks[MAX_ENEMIES];
	GameMap gameMap;
	GameMap& rGameMap = gameMap;
private:
	bool gameIsPlaying = true;


};


#endif // !GameFacade_h