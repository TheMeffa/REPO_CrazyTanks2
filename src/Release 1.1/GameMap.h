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
	void draw(const int& userScore, const time_t& timeStart, const int& heroLives);

	FieldPart gameMap[FIELD_HEIGHT + 1][FIELD_WIDTH + 1];

	int portalPositionX_;
	int portalPositionY_;
	int portalToPositionX_;
	int portalToPositionY_;
};


#endif // !GameMap_h