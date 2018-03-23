#pragma once

#ifndef FieldPart_h
#define FieldPart_h
#include "CurrentState.h"
#include "Constants.h"




class FieldPart
{
public:
	FieldPart();
	~FieldPart();

	char getCurrentStateTexture();
	CurrentState getCurrentState();
	void setCurrentState(CurrentState newCurrentState);


	const char wallBlockOneLive  = WALL_BLOCK_ONE_LIVE;
	const char wallBlockTwoLives = WALL_BLOCK_TWO_LIVES;
	const char wallBlackNoLives  = EMPTY_AREA; 
	const char goldenBlock       = ONE_GOLDEN_BLOCK;
	const char heroTankTexture   = HERO_TANK_TEXTURE;
	const char enemyTankTexture  = ENEMY_TANK_TEXTURE;
	const char bulletTexture     = BULLET_TEXTURE_;


	CurrentState currentState;
};

#endif // !FieldPart_h