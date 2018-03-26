#include "GameEngine.h"



GameEngine::GameEngine()
{
}


GameEngine::~GameEngine()
{
}


void GameEngine::gameEngine(GameMap& gameMapAll, Tank& tank, Bullet& bullet)
{
	MoveDirection bulletMoveDirection = bullet.getMoveDirection();
	int bulletPositionX = bullet.getPositionX();
	int bulletPositionY = bullet.getPositionY();

	int tankPositionX = tank.getPositionX();
	int tankPositionY = tank.getPositionY();

	gameMapAll.gameMap[gameMapAll.portalPositionY_][gameMapAll.portalPositionX_].setCurrentState(PORTAL_POINT);
	gameMapAll.gameMap[gameMapAll.portalToPositionY_][gameMapAll.portalToPositionX_].setCurrentState(PORTALING_TO_POINT);

	if (tankPositionX == gameMapAll.portalPositionX_ &&
		tankPositionY == gameMapAll.portalPositionY_) {

		tank.setPosition(gameMapAll.portalToPositionX_, gameMapAll.portalToPositionY_);

	}

	if (bulletPositionX == gameMapAll.portalPositionX_ &&
		bulletPositionY == gameMapAll.portalPositionY_) {

		bullet.setPosition(gameMapAll.portalToPositionX_, gameMapAll.portalToPositionY_, bullet.getMoveDirection());

	}
	if (tank.getIsHeroTank() == true)
		gameMapAll.gameMap[tankPositionY][tankPositionX].setCurrentState(HERO_TANK);
	else
		gameMapAll.gameMap[tankPositionY][tankPositionX].setCurrentState(ENEMY_TANK);



	if (bulletPositionX == 0 || bulletPositionX == (FIELD_WIDTH - 1) ||
		bulletPositionY == 0 || bulletPositionY == (FIELD_HEIGHT - 1)) {
		gameMapAll.gameMap[bulletPositionY][bulletPositionX].setCurrentState(TWO_LIVES_BLOCK);
		bullet.setDefault();
	}
	else if (gameMapAll.gameMap[bulletPositionY][bulletPositionX].getCurrentState() == EMPTY_BLOCK) {
		gameMapAll.gameMap[bulletPositionY][bulletPositionX].setCurrentState(BULLET_TEXTURE);
	}




	if (bulletPositionX == tankPositionX && bulletPositionY == tankPositionY) {
		if (bullet.getIsHeroBullet() == false) {
			if (bullet.getIsShoted())
				tank.setHeroLives(tank.getHeroLives() - 1);
			gameMapAll.gameMap[tankPositionY][tankPositionX].setCurrentState(HERO_TANK);

			bullet.setDefault();

			if (tank.getHeroLives() == 0) {
				tank.gameIsPlaying = false;

			}
		}
		else {
			if (tank.getIsAlive() == true &&
				bulletPositionX == tankPositionX &&
				bulletPositionY == tankPositionY) {

				tank.heroScores++;

				tank.setIsAlive(false);

				gameMapAll.gameMap[bulletPositionY][bulletPositionX].setCurrentState(EMPTY_BLOCK);

				tank.getBullet().setDefault();
			}
		}
		if (tank.heroScores == MAX_ENEMIES) {
			tank.gameIsPlaying = false;
		}


	}

	if (gameMapAll.gameMap[bulletPositionY][bulletPositionX].getCurrentState() == TWO_LIVES_BLOCK ||
		gameMapAll.gameMap[bulletPositionY][bulletPositionX].getCurrentState() == ONE_LIVE_BLOCK &&
		bullet.getIsShoted() == true &&
		bulletPositionY != 0 && bulletPositionY != FIELD_HEIGHT &&
		bulletPositionX != 0 && bulletPositionX != FIELD_WIDTH)
	{
		gameMapAll.gameMap[bulletPositionY][bulletPositionX].setCurrentState
		(static_cast<CurrentState>(gameMapAll.gameMap[bulletPositionY][bulletPositionX].getCurrentState() - 1));

		bullet.setDefault();
	}



	if (gameMapAll.gameMap[bulletPositionY][bulletPositionX].getCurrentState() == GOLDEN_BLOCK) {
		gameMapAll.gameMap[bulletPositionY][bulletPositionX].setCurrentState(EMPTY_BLOCK);
		tank.gameIsPlaying = false;
	}
}
