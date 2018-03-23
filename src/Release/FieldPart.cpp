#include "FieldPart.h"
#include "Constants.h"
#include "CurrentState.h"

FieldPart::FieldPart()

{

}


FieldPart :: ~FieldPart()
{
}

void FieldPart::setCurrentState(CurrentState newCurrentState) {
 	currentState = newCurrentState;
}

char FieldPart::getCurrentStateTexture() {
	char varTexture;

	switch (currentState) {

	

	case EMPTY_BLOCK:
		varTexture = wallBlackNoLives;
		break;

	case ONE_LIVE_BLOCK:
		varTexture = wallBlockOneLive;
		break;

	case TWO_LIVES_BLOCK:
		varTexture = wallBlockTwoLives;
		break;

	case GOLDEN_BLOCK:
		varTexture = goldenBlock;
		break;

	case HERO_TANK:
		varTexture = heroTankTexture;
		break;

	case ENEMY_TANK:
		varTexture = enemyTankTexture;
		break;

	case BULLET_TEXTURE:
		varTexture = bulletTexture;
		break;

	case BORDER_TEXTURE:
		varTexture = borderTexture;
		break;

		
	}
	return varTexture;
}



CurrentState FieldPart::getCurrentState()
{
	return currentState;
}