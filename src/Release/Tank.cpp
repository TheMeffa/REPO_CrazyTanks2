#include <conio.h>
#include <cstdlib>

#include "Tank.h"
#include "Constants.h"
#include "CurrentState.h"


Tank::Tank()
{
}


Tank :: ~Tank()
{
}

bool Tank::gameIsPlaying = false;

void Tank::setTankConfiguration(bool isItHeroTank, GameMap &gameMapAll)
{

	if (isItHeroTank == true) {

		gameIsPlaying = true;
		positionX_ = FIELD_WIDTH / 2;
		positionY_ = FIELD_HEIGHT - 2;
		isHeroTank_ = true;
		texture_ = HERO_TANK;
		heroLives_ = MAX_HERO_LIVES;
		moveDirection_ = shotDirection_ = UP;
		bullet_.setIsHeroBullet(true);
		bullet_.setShoted(false);
		heroScores = 0;
		isAlive_ = true;


	}
	else {
		setEnemyStartPosition(gameMapAll);
		isHeroTank_ = false;
		texture_ = ENEMY_TANK;
		isAlive_ = true;
		bullet_.setIsHeroBullet(false);
	}

}

void Tank::setHeroLives(int heroLives)
{
	heroLives_ = heroLives;
}

void Tank::setIsAlive(bool isAlive)
{
	isAlive_ = isAlive;
}


Bullet& Tank::getBullet()

{
	Bullet& rBullet_ = bullet_;
	return rBullet_;
}




MoveDirection Tank::getMoveDirection()
{
	return moveDirection_;
}

 int Tank :: heroScores = 0;



void Tank::heroDriving(GameMap& allGameMap)
{


	
	if (_kbhit()) {
		switch (_getch()) {

		case ARROW_UP:					//Press arrow UP;
			moveDirection_ = shotDirection_ = UP;
			break;

		case ARROW_DOWN:					// Press arrow DOWN;
			moveDirection_ = shotDirection_ = DOWN;
			break;

		case ARROW_LEFT:					//Press arrow LEFT;
			moveDirection_ = shotDirection_ = LEFT;
			break;

		case ARROW_RIGHT:					//Press arrow RIGHT
			moveDirection_ = shotDirection_ = RIGHT;
			break;

		case SPACE:					//Press space;
			if (bullet_.getIsShoted() != 1) {
				bullet_.setPosition(getPositionX(), getPositionY(), getShotDirection());
				bullet_.setShoted(true);
				bullet_.setIsHeroBullet(true);
				break;
			}
		}
	}
}







void Tank :: enemyAI(int heroPositionX, int heroPositionY) {
	if (isAlive_ == true) {

		if (way_ <= 0) {
			moveDirection_ = static_cast <MoveDirection> (rand() % 4);
			way_ = rand() % MAX_ETANK_WAY;
		}
	

		if (positionX_ == FIELD_WIDTH - BORDER_OUT) {
			moveDirection_ = DOWN;
			if (bullet_.getIsShoted() != 1) {
				bullet_.setPosition(getPositionX(), getPositionY(), getMoveDirection());
				bullet_.setShoted(true);
			}
		}

		if (positionY_ == FIELD_WIDTH - BORDER_OUT) {
			moveDirection_ = RIGHT;
			if (bullet_.getIsShoted() != 1) {
				bullet_.setPosition(getPositionX(), getPositionY(), getMoveDirection());
				bullet_.setShoted(true);
			}
		}

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

		moveDirection_ = static_cast<MoveDirection>(rand() % COUNT_DIRECTIONS);
	}
	else {
		positionX_ = FIELD_WIDTH;
		positionY_ = FIELD_HEIGHT;
		bullet_.setDefault();
	}
}



void Tank::movement(GameMap& allGameMap) {

	if(isAlive_ == true){
		switch (moveDirection_) {
		case UP:
			if (allGameMap.gameMap[positionY_ - 1][positionX_].getCurrentStateTexture() == EMPTY_AREA) {
				allGameMap.gameMap[positionY_ - 1][positionX_].setCurrentState(getTexture());
				allGameMap.gameMap[positionY_][positionX_].setCurrentState(EMPTY_BLOCK);
				positionY_--;
			}
			if (getIsHeroTank() == 0)
				way_--;
			else
				moveDirection_ = STOP;
			break;

		case DOWN:
			if (allGameMap.gameMap[positionY_ + 1][positionX_].getCurrentStateTexture() == EMPTY_AREA) {
				allGameMap.gameMap[positionY_ + 1][positionX_].setCurrentState(getTexture());
				allGameMap.gameMap[positionY_][positionX_].setCurrentState(EMPTY_BLOCK);
				positionY_++;
			}
			if (getIsHeroTank() == 0)
				way_--;
			else
				moveDirection_ = STOP;
			break;

		case LEFT:
			if (allGameMap.gameMap[positionY_][positionX_ - 1].getCurrentStateTexture() == EMPTY_AREA) {
				allGameMap.gameMap[positionY_][positionX_ - 1].setCurrentState(getTexture());
				allGameMap.gameMap[positionY_][positionX_].setCurrentState(EMPTY_BLOCK);
				positionX_--;
			}
			if (getIsHeroTank() == 0)
				way_--;
			else
				moveDirection_ = STOP;

			break;

		case RIGHT:
			if (allGameMap.gameMap[positionY_][positionX_ + 1].getCurrentStateTexture() == EMPTY_AREA) {
				allGameMap.gameMap[positionY_][positionX_ + 1].setCurrentState(getTexture());
				allGameMap.gameMap[positionY_][positionX_].setCurrentState(EMPTY_BLOCK);
				positionX_++;
			}
			if (getIsHeroTank() == 0)
				way_--;
			else
				moveDirection_ = STOP;
			break;

		default:
			moveDirection_ = STOP;
		}
	}
	else {
		(allGameMap.gameMap[positionY_][positionX_].setCurrentState(EMPTY_BLOCK));
		positionX_ = FIELD_WIDTH;
		positionY_ = FIELD_HEIGHT;
	 }
	
}





bool Tank::getIsHeroTank()
{
	return isHeroTank_;
}



bool Tank::getIsAlive()
{
	return isAlive_;
}



int Tank::getPositionY()
{
	return positionY_;
}



int Tank::getPositionX()
{
	return positionX_;
}



int Tank::getHeroLives()
{
	return heroLives_;
}


MoveDirection Tank::getShotDirection() {
	return shotDirection_;
}



CurrentState Tank::getTexture()
{
	return texture_;
}


int Tank::getHeroScores()
{
	return heroScores;
}

bool Tank::isEnoughClearSpace(GameMap& gameMapAll, int x, int y)
{
	
		for (int i = y - MINIMAL_TANK_DISTANCE; i <= MINIMAL_TANK_DISTANCE * 2; i++) {
			for (int j = x - MINIMAL_TANK_DISTANCE; j <= MINIMAL_TANK_DISTANCE * 2; j++)
				if (gameMapAll.gameMap[i][j].getCurrentState() == ENEMY_TANK) {
					return false;
				}
		}
		return true;


}



void Tank::setEnemyStartPosition(GameMap& gameMapAll)
{
	{
	while (true) {
		 //Initialization X and Y position.
		positionX_ = rand() % FIELD_WIDTH + 1;
		positionY_ = rand() % FIELD_HEIGHT + 1;

		 //Checking that X and Y positions are on the map.
		if (positionX_ <= 0 || positionX_ >= FIELD_WIDTH  - 1 ||
			positionY_ <= 0 || positionY_ >= FIELD_HEIGHT - 1)
			continue;
		else break;
				// Checking that selected point is free
				// and near it are not other enemy tanks.
				if (gameMapAll.gameMap[positionY_] [positionX_].getCurrentState() != TWO_LIVES_BLOCK &&
					gameMapAll.gameMap[positionY_] [positionX_].getCurrentState() != HERO_TANK       &&
					gameMapAll.gameMap[positionY_] [positionX_].getCurrentState() != ENEMY_TANK      &&
					gameMapAll.gameMap[positionY_] [positionX_].getCurrentState() != GOLDEN_BLOCK) {

					if (isEnoughClearSpace(gameMapAll, positionX_, positionY_) != true) {
						int randomVar = rand() % 2;
						if (randomVar == 1) {
							positionX_ += MINIMAL_TANK_DISTANCE + 1;
						}
						else {
							positionY_ += MINIMAL_TANK_DISTANCE + 1;
						}
						if (isEnoughClearSpace(gameMapAll, positionX_, positionY_) == true) {

							break;
						}
						else
							continue;
					}
					else
						break;
				}
			}



		//moveDirection_ = static_cast<MoveDirection>(rand() % 4);
	
		way_ = rand() % MAX_ETANK_WAY;
	}
}