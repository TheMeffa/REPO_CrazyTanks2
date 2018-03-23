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
	GameFacade gameFacade;
	while (gameFacade.getGameIsPlaying() == true) {

		gameFacade.heroTank.heroDriving(gameFacade.rGameMap);
		gameFacade.heroTank.movement(gameFacade.rGameMap);
		gameFacade.heroTank.bullet_.movement(gameFacade.rGameMap);

		for (int i = 0; i < MAX_ENEMIES; i++) {
			gameFacade.enemyTanks[i].enemyAI (gameFacade.heroTank.getPositionX(),
											  gameFacade.heroTank.getPositionY());

			gameFacade.enemyTanks[i].movement(gameFacade.rGameMap);
			gameFacade.enemyTanks[i].bullet_.movement(gameFacade.rGameMap);
		}

		//Sleep(150);
		gameFacade.gameMap.draw();
		system("cls");


	}

	system("pause");

	return 0;
}