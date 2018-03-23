#include "Tank.h"
#include "Constants.h"
#include "Bullet.h"
#include <cstdlib>
#include "moveDirection.h"
#include "CurrentState.h"
#include <conio.h>
#include "Bullet.h"

Tank::Tank()
{
}


Tank :: ~Tank()
{
}


void Tank::setTankConfiguration(bool isItHeroTank) 
{

	if (isItHeroTank == true) {
		positionX_ = FIELD_WIDTH / 2;
		positionY_ = FIELD_HEIGHT - 2;
		isHeroTank_ = true;
		texture_ = HERO_TANK;
		heroLives_ = MAX_HERO_LIVES;
		moveDirection_ = UP;
		bullet_.setIsHeroBullet(true);
		bullet_.setShoted(false);

	}
	else {
		setEnemyStartPosition();
		isHeroTank_ = false;
		texture_ = ENEMY_TANK;
		isAlive_ = true;
		bullet_.setIsHeroBullet(false);
	}

}




MoveDirection Tank::getMoveDirection() 
{
	return moveDirection_;
}



void Tank::heroDriving (GameMap& allGameMap) 
{


	if (allGameMap.gameMap[positionY_][positionX_].getCurrentState() == BULLET_TEXTURE) {
		allGameMap.gameMap[positionY_][positionX_].setCurrentState(HERO_TANK);
		heroLives_--;
	}

	if (_kbhit()) {
		switch (_getch()) {

		case 72:					//Press arrow UP;
			moveDirection_ = UP;
			break;

		case 80:					// Press arrow DOWN;
			moveDirection_ = DOWN;
			break;

		case 75:					//Press arrow LEFT;
			moveDirection_ = LEFT;
			break;

		case 77:					//Press arrow RIGHT
			moveDirection_ = RIGHT;
			break;

		case 32:					//Press space;
			if (bullet_.getIsShoted() != 1) {
				bullet_.setPosition(getPositionX(), getPositionY(), getMoveDirection());
				bullet_.setShoted(true);
				bullet_.setIsHeroBullet(true);
				break;
			}
		}
	}
}







void Tank::enemyAI(int heroPositionX, int heroPositionY) {

	if (way_ <= 0) {
		moveDirection_ = static_cast <MoveDirection> (rand() % 4);
		way_ = rand() % MAX_ETANK_WAY;
	}
	/*	if (positionX_ == heroBulletPosX && positionY == heroBulletPosY) {
			positionX_ = FIELD_HEIGHT + 1;
			positionY_ = FIELD_WIDTH + 1;

			isAlive_ = false;
		}*/



	if (positionX_ == heroPositionX) {
		if (positionY_ > static_cast <unsigned int>(heroPositionY)) {
			moveDirection_ = UP;
			if (bullet_.getIsShoted() != 1) {
				bullet_.setPosition(getPositionX(), getPositionY(), getMoveDirection());
				bullet_.setShoted(true);
			}
		}
		else {
			moveDirection_ = DOWN;
			if (bullet_.getIsShoted() != 1) {
				bullet_.setPosition(getPositionX(), getPositionY(), getMoveDirection());
				bullet_.setShoted(true);
			}
		}


	}
	if (positionY_ == heroPositionY) {
		if (positionX_ > static_cast <unsigned int>(heroPositionX)) {
			moveDirection_ = LEFT;
			if (bullet_.getIsShoted() != 1) {
				bullet_.setPosition(getPositionX(), getPositionY(), getMoveDirection());
				bullet_.setShoted(true);
			}
		}
		else {
			moveDirection_ = RIGHT;
			if (bullet_.getIsShoted() != 1) {
				bullet_.setPosition(getPositionX(), getPositionY(), getMoveDirection());
				bullet_.setShoted(true);
			}
		}
	}
}



void Tank::movement(GameMap& gameMapAll) {

	switch (moveDirection_) {
	case UP:
		if (gameMapAll.gameMap[positionY_ - 1][positionX_].getCurrentStateTexture() == EMPTY_AREA) {
			gameMapAll.gameMap[positionY_ - 1][positionX_].setCurrentState(getTexture());
			gameMapAll.gameMap[positionY_][positionX_].setCurrentState(NO_LIVES);
			positionY_--;
		}
		if(getIsHeroTank() == 0)
			way_--;
		moveDirection_ = STOP;
		break;

	case DOWN:
		if (gameMapAll.gameMap[positionY_ + 1][positionX_].getCurrentStateTexture() == EMPTY_AREA) {
			gameMapAll.gameMap[positionY_ + 1][positionX_].setCurrentState(getTexture());
			gameMapAll.gameMap[positionY_][positionX_].setCurrentState(NO_LIVES);
			positionY_++;
		}
		if (getIsHeroTank() == 0)
			way_--;
		moveDirection_ = STOP;
		break;

	case LEFT:
		if (gameMapAll.gameMap[positionY_][positionX_ - 1].getCurrentStateTexture() == EMPTY_AREA) {
			gameMapAll.gameMap[positionY_][positionX_ - 1].setCurrentState(getTexture());
			gameMapAll.gameMap[positionY_][positionX_].setCurrentState(NO_LIVES);
			positionX_--;
		}
		if (getIsHeroTank() == 0)
			way_--;
		moveDirection_ = STOP;

		break;

	case RIGHT:
		if (gameMapAll.gameMap[positionY_][positionX_ + 1].getCurrentStateTexture() == EMPTY_AREA) {
			gameMapAll.gameMap[positionY_][positionX_ + 1].setCurrentState(getTexture());
			gameMapAll.gameMap[positionY_][positionX_].setCurrentState(NO_LIVES);
			positionX_++;
		}
		if (getIsHeroTank() == 0)
			way_--;
		moveDirection_ = STOP;
		break;

	default:
		moveDirection_ = STOP;

	}
}





bool Tank :: getIsHeroTank()
{
	return isHeroTank_;
}



bool Tank::getIsAlive()
{
	return isAlive_;
}



int Tank :: getPositionY() 
{
	return positionY_;
}



int Tank ::getPositionX() 
{
	return positionX_;
}



int Tank :: getHeroLives()
{
	return heroLives_;
}






CurrentState Tank :: getTexture()
{
	return texture_;
}






void Tank::setEnemyStartPosition()
{

	//{
	//	while (true) {
	//		// Initialization X and Y position.
			positionX_ = rand() % FIELD_WIDTH + 1;
			positionY_ = rand() % FIELD_HEIGHT + 1;

	//		// Checking that X and Y positions are on the map.
	//		if (positionX <= 0 || positionX >= FIELD_WIDTH ||
	//			positionY <= 0 || positionY >= FIELD_HEIGHT)
	//			continue;

	//		// Checking that selected point is free
	//		// and near it are not other enemy tanks.
	//		if (firstFrameMap[positionY][positionX] != WALL_BLOCK &&
	//			firstFrameMap[positionY][positionX] != HERO_TANK &&
	//			firstFrameMap[positionY][positionX] != ENEMY_TANK) {

	//			if (isClear(positionX, positionY) != true) {
	//				int randomVar = rand() % 2;
	//				if (randomVar == 1) {
	//					positionX += MINIMAL_TANK_DISTANCE + 1;
	//				}
	//				else {
	//					positionY += MINIMAL_TANK_DISTANCE + 1;
	//				}
	//				if (isClear(positionX, positionY) == true) {

	//					break;
	//				}
	//				else
	//					continue;
	//			}
	//			else
	//				break;
	//		}
	//	}



	//	enemySD_ = static_cast<ShotDirection>(rand() % 4);
	//	modelOfObject = ENEMY_TANK;
	//	isAlive = true;
	//	way_ = rand() % MAX_ETANK_WAY;
	//}

}