#include "GameFacade.h"
#include "Tank.h"
#include "CurrentState.h"

GameFacade::GameFacade()
{
	heroTank.setTankConfiguration(true);

	for (int i = 0; i < MAX_ENEMIES; i++) {
		enemyTanks[i].setTankConfiguration(false);
	}
}








bool GameFacade :: getGameIsPlaying() 
{
	return gameIsPlaying;
}



