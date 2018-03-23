#pragma once
#include "Constants.h"
#include "FieldPart.h"
#include "Tank.h"

#ifndef GameMap_h
#define GameMap_h


class GameMap
{
public:
	GameMap();
	~GameMap();
	void draw();

	FieldPart gameMap[FIELD_HEIGHT][FIELD_WIDTH];
};

#endif // !GameMap_h