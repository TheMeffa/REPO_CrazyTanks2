#include "GameFacade.h"
#include "Tank.h"
#include "CurrentState.h"

GameFacade::GameFacade()
{

	heroTank.setTankConfiguration(true, gameMap);

	for (int i = 0; i < MAX_ENEMIES; i++) {
		enemyTanks[i].setTankConfiguration(false, gameMap);
	}
	
}



Tank & GameFacade::getRefTank(Tank tank)
{
	Tank& rTank = tank;
	return rTank;
}











