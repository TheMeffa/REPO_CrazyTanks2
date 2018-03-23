#include <iostream>
#include <windows.h>
#include <time.h>

#include "Tank.h"
#include "moveDirection.h"
#include "Bullet.h"
#include "Constants.h"
#include "GameFacade.h"
#include "GameMap.h"
#include "FieldPart.h"



using namespace std;


int main()
{
	srand(time(0));
	time_t start = time(0); // For clock.

	GameFacade gameFacade;
	while (gameFacade.heroTank.gameIsPlaying == true) {

		gameFacade.heroTank.heroDriving(gameFacade.gameMap);
		gameFacade.heroTank.movement(gameFacade.gameMap);
		gameFacade.heroTank.getBullet().movement(gameFacade.gameMap);
		

		for (int i = 0; i < MAX_ENEMIES; i++) {

			gameFacade.enemyTanks[i]. enemyAI(gameFacade.heroTank.getPositionX(), gameFacade.heroTank.getPositionY());

			gameFacade. enemyTanks[i]. movement(gameFacade.rGameMap);
			gameFacade. enemyTanks[i]. getBullet().movement(gameFacade.gameMap);
			
			gameFacade.gameEngineObject.gameEngine (gameFacade.gameMap, 
													gameFacade.heroTank, 
													gameFacade.enemyTanks[i].getBullet());

			gameFacade.gameEngineObject.gameEngine(gameFacade.gameMap,
												   gameFacade.enemyTanks[i],
												   gameFacade.heroTank.getBullet());
		
		}

		Sleep(50);
		gameFacade.gameMap.draw(gameFacade.heroTank.heroScores, start, gameFacade.heroTank.getHeroLives());

	}

	if (gameFacade.heroTank.getHeroScores() == MAX_ENEMIES) {

		cout << endl <<  "Congratulations! You`ve won!" << endl << endl;
	}
	else {

		cout << endl << "Defeat! Your score: " << gameFacade.heroTank.getHeroScores() << endl << endl;

	}

	system("pause");

	return 0;
}