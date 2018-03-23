#pragma once
#include <time.h>

#include "Constants.h"
#include "FieldPart.h"


#ifndef GameMap_h
#define GameMap_h


class GameMap
{
public:
	GameMap();
	~GameMap();
	void draw(int userScore, time_t timeStart, int heroLives);


	FieldPart gameMap[FIELD_HEIGHT + 1][FIELD_WIDTH + 1];

};

#endif // !GameMap_h