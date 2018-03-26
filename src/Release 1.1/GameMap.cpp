#include <iostream>
#include <time.h>

#include "GameMap.h"
#include "CurrentState.h"
#include "Constants.h"


using namespace std;

GameMap::GameMap()
{
	for (int i = 0; i < FIELD_HEIGHT; i++) {
		for (int j = 0; j < FIELD_WIDTH; j++) {
			if (j == 0 || j == FIELD_WIDTH - 1 ||
				i == 0 || i == FIELD_HEIGHT - 1) {
				gameMap[i][j].setCurrentState(TWO_LIVES_BLOCK);
			}
			else if (i >= (FIELD_HEIGHT - CASTLE_WALL_LENGHT) && j >= (FIELD_WIDTH - CASTLE_WALL_LENGHT)) {
				if (i == j && i == (FIELD_HEIGHT - 2)) {
					gameMap[i][j].setCurrentState(GOLDEN_BLOCK);
				}
				else gameMap[i][j].setCurrentState(TWO_LIVES_BLOCK);
			}
			else gameMap[i][j].setCurrentState(EMPTY_BLOCK);
		}
	}
	//nRandSettings = quantify of vertical walls on the map;
	int nRandSettings = rand() % MAX_RAND_SETTINGS;

	// Generating random vertical walls;
	for (int i = 0; i < nRandSettings; i++) {
		int startRandomWallX = rand() % FIELD_HEIGHT + rand() % MAX_WALL_LENGHT;
		int startRandomWallY = rand() % FIELD_HEIGHT + rand() % MAX_WALL_LENGHT;
		int endRandWall = rand() % MAX_WALL_LENGHT;
		for (int j = 0; j < endRandWall; j++) {
			if (gameMap[startRandomWallY][startRandomWallX].getCurrentState() != GOLDEN_BLOCK) {
				gameMap[startRandomWallY][startRandomWallX].setCurrentState(TWO_LIVES_BLOCK);
			}
			startRandomWallY++;
		}
	}
	//nRandSettings = quantify of horizontal walls on the map;
	nRandSettings = rand() % MAX_RAND_SETTINGS;

	// Generating random horizontal walls;
	for (int i = 0; i < nRandSettings; i++) {
		int startRandomWallX = rand() % FIELD_WIDTH + rand() % MAX_WALL_LENGHT;
		int startRandomWallY = rand() % FIELD_WIDTH + rand() % MAX_WALL_LENGHT;
		int endRandWall = rand() % MAX_WALL_LENGHT;
		for (int j = 0; j < endRandWall; j++) {
			if (gameMap[startRandomWallY][startRandomWallX].getCurrentState() != GOLDEN_BLOCK) {
				  gameMap[startRandomWallY][startRandomWallX].setCurrentState(TWO_LIVES_BLOCK);
			}startRandomWallX++;
		}
	}

	bool pointIsCreated = false;

	while (pointIsCreated == false) {
		int portalPositionX = rand() % FIELD_WIDTH - BORDER_OUT;
		int portalPositionY = rand() % FIELD_HEIGHT- BORDER_OUT;
		if (portalPositionX != 0 && portalPositionY != 0) {
			if (gameMap[portalPositionY][portalPositionX].getCurrentState() == EMPTY_BLOCK) {
				gameMap[portalPositionY][portalPositionX].setCurrentState(PORTAL_POINT);

				portalPositionX_ = portalPositionX;
				portalPositionY_ = portalPositionY;

				pointIsCreated = true;
			}
		}
	}

	pointIsCreated = false;
	while (pointIsCreated == false) {

		int portalToPositionX = rand() % FIELD_WIDTH - BORDER_OUT;
		int portalToPositionY = rand() % FIELD_HEIGHT - BORDER_OUT;
		
		if (gameMap[portalToPositionY][portalToPositionX].getCurrentState() == EMPTY_BLOCK) {
			gameMap[portalToPositionY][portalToPositionX].setCurrentState(PORTALING_TO_POINT);

			portalToPositionX_ = portalToPositionX;
			portalToPositionY_ = portalToPositionY;

			pointIsCreated = true;
		}

	}


}

 

GameMap::~GameMap()
{
}


void GameMap::draw(const int& userScore, const time_t& startTime, const int& heroLives) {
	system("cls");

	cout << "Your score: "    << userScore
		 << "  Your live`s: " << heroLives
		 << "  Playing time:" << static_cast <int> (difftime(time(0), startTime)) / SECONDS_MINUTES << "m."
		 << static_cast <int> (difftime(time(0), startTime)) % SECONDS_MINUTES << "s. " << endl << endl;

	for (int i = 0; i < FIELD_HEIGHT; i++) {
		cout << "            ";
		for (int j = 0; j < FIELD_WIDTH; j++) {
			cout << gameMap[i][j].getCurrentStateTexture() << ' ';
		}
		cout << endl;
	}
}
