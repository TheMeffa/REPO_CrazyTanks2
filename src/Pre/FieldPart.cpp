#include "FieldPart.h"
#include "Constants.h"
#include "CurrentState.h"

FieldPart :: FieldPart()

{
	
}


FieldPart :: ~FieldPart()
{
}

void FieldPart::setCurrentState(CurrentState newCurrentState) {
	currentState = newCurrentState;
}

char FieldPart::getCurrentStateTexture() {
	switch (currentState) {

	case NO_LIVES:
		return wallBlackNoLives;
		break;
	
	case ONE_LIVE:
		return wallBlockOneLive;
		break;

	case TWO_LIVES:
		return wallBlockTwoLives;
		break;

	case GOLDEN_BLOCK:
		return goldenBlock;
		break;

	case HERO_TANK:
		return heroTankTexture;
		break;

	case ENEMY_TANK:
		return enemyTankTexture;
		break;

	case BULLET_TEXTURE:
		return bulletTexture;
		break;
	
	}
}


CurrentState FieldPart::getCurrentState()
{
	return currentState;
}