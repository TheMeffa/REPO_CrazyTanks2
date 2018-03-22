#pragma once
#ifndef Tank_h
#define Tank_h
#include "moveDirection.h"
#include "Bullet.h"
#include "CurrentState.h"
#include "GameMap.h"


class Tank
{
public:
	Tank();
	~Tank();

	MoveDirection getMoveDirection();
	int  getPositionY();
	int  getPositionX();
	int  getHeroLives();

	CurrentState getTexture();

	bool getIsHeroTank();
	bool getIsAlive();

	void movement(GameMap& allGameMap);
	void enemyAI(int heroPositionX, int heroPositionY);

	void heroDriving(GameMap& allGameMap);
	void setEnemyStartPosition();

	void setTankConfiguration(bool isItHeroTank);
	Bullet bullet_;

private:
	int positionX_;
	int positionY_;
	CurrentState texture_;
	MoveDirection moveDirection_;
	int heroLives_;
	bool isAlive_;
	bool isHeroTank_ = false;
	int way_;
	


};

#endif // !HeroTank_h
