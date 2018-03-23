#include "Bullet.h"
#include "moveDirection.h"
#include "GameMap.h"
#include "FieldPart.h"
#include "CurrentState.h"
#include "Tank.h"

Bullet::Bullet()
{
	setDefault();
}



CurrentState Bullet::getTexture()
{
	return BULLET_TEXTURE;
}

void Bullet::setIsHeroBullet(bool isHero)
{
	isHeroBullet_ = isHero;
}


void Bullet::setShoted(bool isShoted)
{
	isShoted_ = isShoted;
}


int Bullet::getPositionY()
{
	return positionY_;
}

int Bullet::getPositionX()
{
	return positionX_;
}


void Bullet::setPosition(int x, int y, MoveDirection moveDirection)
{
	positionX_ = x;
	positionY_ = y;
	moveDirection_ = moveDirection;
}



void Bullet::setDefault()
{
	positionX_ = FIELD_WIDTH;
	positionY_ = FIELD_HEIGHT;
	moveDirection_ = UP;
	isShoted_ = false;
}




bool Bullet::getIsShoted()
{
	return isShoted_;
}



bool Bullet::getIsHeroBullet()
{
	return isHeroBullet_;
}








void Bullet :: movement(GameMap& gameMapAll) {

	if(gameMapAll.gameMap[positionY_][positionX_].getCurrentState() == BULLET_TEXTURE)
		gameMapAll.gameMap[positionY_][positionX_].setCurrentState(EMPTY_BLOCK);
	
	if (isShoted_ == 1) {

		switch (moveDirection_) {

		case UP:
			if(positionY_ - 1 != 0)
			positionY_--;

			else
				setDefault();

			break;

		case DOWN:
			if (positionY_ + 1 != FIELD_HEIGHT - 1)
			positionY_++;

			else
				setDefault();
			break;


		case LEFT:
			if (positionX_ - 1 != 0)
			positionX_--;

			else
				setDefault();

			break;


		case RIGHT:
			if (positionX_ + 1 != FIELD_WIDTH - 1)
				positionX_++;

			else
				setDefault();
			break;

		default:
			setDefault();
		}
	}
}

MoveDirection  Bullet::getMoveDirection()
{
	return moveDirection_;
}