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

	static int heroScores;
	static bool gameIsPlaying;

	MoveDirection getMoveDirection();
	MoveDirection getShotDirection();

	int  getPositionY();
	int  getPositionX();
	int  getHeroLives();
	int  getHeroScores();

	Bullet& getBullet();
	CurrentState getTexture();

	bool isEnoughClearSpace(GameMap& gameMapAll, const int& x, const int& y);
	bool getIsHeroTank();
	bool getIsAlive();

	void movement (GameMap&  allGameMap);
	void enemyAI (const int& heroPositionX, const int& heroPositionY);

	void heroDriving (GameMap& allGameMap);
	void setEnemyStartPosition (GameMap& gameMapAll);

	void setTankConfiguration (const bool& isItHeroTank,  GameMap& gameMapAll);
	void setHeroLives (const int& heroLives);
	void setIsAlive   (const bool& isAlive);

	void setPosition(const int & x, const int & y);

private:

	Bullet bullet_;


	
	int positionX_;
	int positionY_;
	CurrentState texture_;
	MoveDirection moveDirection_;
	MoveDirection shotDirection_;
	int heroLives_;
	bool isAlive_;
	bool isHeroTank_ = false;
	int way_;



};

#endif // !HeroTank_h
