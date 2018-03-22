#pragma once
#ifndef Bullet_h
#define Bullet_h
#include "Constants.h"
#include "FieldPart.h"
#include "GameMap.h"
#include "moveDirection.h"


class Bullet
{
public:
	Bullet();

	CurrentState getTexture();
	
	bool getIsShoted();
	bool getIsHeroBullet();

	void movement(GameMap& gameMapAll);
	void setIsHeroBullet(bool isHero);
	void setShoted(bool isShoted);
	void setPosition(int x, int y, MoveDirection moveDirection);
	void setDefault();

	int getPositionY();
	int getPositionX();

private:
	int positionX_;
	int positionY_;

	bool isShoted_;
	bool isHeroBullet_;

	char texture_;
	MoveDirection moveDirection_;
};

#endif //!Bullet_h