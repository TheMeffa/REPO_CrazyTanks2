#include "Bullet.h"
#include "moveDirection.h"
#include "GameMap.h"
#include "FieldPart.h"
#include "CurrentState.h"

Bullet::Bullet()
{

}



 CurrentState Bullet :: getTexture ()
 {
	 return BULLET_TEXTURE;
 }

void Bullet::setIsHeroBullet(bool isHero) 
{
	isHeroBullet_ = isHero;
}


void Bullet :: setShoted(bool isShoted)
{
	isShoted_ = isShoted;
}


int Bullet :: getPositionY()
{
	return positionY_;
}

int Bullet::getPositionX()
{
	return positionX_;
}


void Bullet :: setPosition(int x, int y, MoveDirection moveDirection)
{ 
	positionX_ = x;
	positionY_ = y;
	moveDirection_ = moveDirection;
}



void Bullet :: setDefault()
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

	if (isShoted_ == 1) {
		switch (moveDirection_) {


		case UP:

			if (positionY_ - 1 != 0 && 
				gameMapAll.gameMap[positionY_ - 1][positionX_].getCurrentState() <= TWO_LIVES &&
				gameMapAll.gameMap[positionY_ - 1][positionX_].getCurrentState() != NO_LIVES) {
	
				gameMapAll.gameMap[positionY_ - 1][positionX_].setCurrentState 
							(static_cast<CurrentState>(gameMapAll.gameMap[positionY_ - 1][positionX_].getCurrentState() - 1));

				gameMapAll.gameMap[positionY_][positionX_].setCurrentState(NO_LIVES);
				setDefault();
			}

			else if (positionY_ - 1 != 0 &&
				gameMapAll.gameMap[positionY_ - 1][positionX_].getCurrentState() == NO_LIVES) {

				gameMapAll.gameMap[positionY_ - 1][positionX_].setCurrentState(BULLET_TEXTURE);
				gameMapAll.gameMap[positionY_][positionX_].setCurrentState(NO_LIVES);

				positionY_--;
			}
	
			else {
				setDefault();
				gameMapAll.gameMap[positionY_][positionX_].setCurrentState(NO_LIVES);
			}
			break;



		case DOWN:

			if (positionY_ + 1 != 0 &&
				gameMapAll.gameMap[positionY_ + 1][positionX_].getCurrentState() <= TWO_LIVES &&
				gameMapAll.gameMap[positionY_ + 1][positionX_].getCurrentState() != NO_LIVES) {

				gameMapAll.gameMap[positionY_ + 1][positionX_].setCurrentState
				(static_cast<CurrentState>(gameMapAll.gameMap[positionY_ + 1][positionX_].getCurrentState() - 1));
				
				gameMapAll.gameMap[positionY_ ][positionX_].setCurrentState(NO_LIVES);
				setDefault();
			}

			else if (positionY_ + 1 != FIELD_HEIGHT &&
				gameMapAll.gameMap[positionY_ + 1][positionX_].getCurrentState() == NO_LIVES) {
			
				gameMapAll.gameMap[positionY_ + 1][positionX_].setCurrentState(BULLET_TEXTURE);
				gameMapAll.gameMap[positionY_][positionX_].setCurrentState(NO_LIVES);

				positionY_++;
			}
			else {
				setDefault();
				gameMapAll.gameMap[positionY_][positionX_].setCurrentState(NO_LIVES);
			}
			break;


		case LEFT:

			if (positionX_ - 1 != 0 &&
				gameMapAll.gameMap[positionY_][positionX_ - 1].getCurrentState() <= TWO_LIVES &&
				gameMapAll.gameMap[positionY_][positionX_ - 1].getCurrentState() != NO_LIVES) {

				gameMapAll.gameMap[positionY_][positionX_ - 1].setCurrentState
				(static_cast<CurrentState> (gameMapAll.gameMap [positionY_][positionX_ - 1].getCurrentState() - 1));

				gameMapAll.gameMap[positionY_][positionX_].setCurrentState(NO_LIVES);
				setDefault();
			}

			else if (positionX_ - 1 != 0 &&
				gameMapAll.gameMap[positionY_][positionX_ - 1].getCurrentState() == NO_LIVES) {
				
				gameMapAll.gameMap[positionY_][positionX_ - 1].setCurrentState(BULLET_TEXTURE);
				gameMapAll.gameMap[positionY_][positionX_].setCurrentState(NO_LIVES);

				positionX_--;
			}

			else {
				setDefault();
				gameMapAll.gameMap[positionY_][positionX_].setCurrentState(NO_LIVES);
			}
			break;


		case RIGHT:

			if (positionX_ + 1 != FIELD_WIDTH &&
				gameMapAll.gameMap[positionY_][positionX_ + 1].getCurrentState() <= TWO_LIVES &&
				gameMapAll.gameMap[positionY_][positionX_ + 1].getCurrentState() != NO_LIVES) {

				gameMapAll.gameMap[positionY_][positionX_ + 1].setCurrentState
				(static_cast<CurrentState>(gameMapAll.gameMap[positionY_][positionX_ + 1].getCurrentState() - 1));

				gameMapAll.gameMap[positionY_][positionX_].setCurrentState(NO_LIVES);
				setDefault();
			}

			else if (positionX_ + 1 != FIELD_WIDTH &&
				gameMapAll.gameMap[positionY_][positionX_ + 1].getCurrentState() == NO_LIVES) {
				
				gameMapAll.gameMap[positionY_][positionX_ + 1].setCurrentState(BULLET_TEXTURE);
				gameMapAll.gameMap[positionY_][positionX_].setCurrentState(NO_LIVES);

				positionX_++;
			}

			else {
				setDefault();
				gameMapAll.gameMap[positionY_][positionX_].setCurrentState(NO_LIVES);
			}
			break;
		}
	}
}
