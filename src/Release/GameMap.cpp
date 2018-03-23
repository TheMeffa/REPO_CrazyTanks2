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
}



GameMap::~GameMap()
{
}


void GameMap::draw(int userScore, time_t startTime, int heroLives) {
	system("cls");

	cout << "Your score: "    << userScore
		 << "  Your live`s: " << heroLives
		 << "  Playing time:" << static_cast <int> (difftime(time(0), startTime)) / 60 << "m."
		 << static_cast <int> (difftime(time(0), startTime)) % 60 << "s. " << endl << endl;

	for (int i = 0; i < FIELD_HEIGHT; i++) {
		cout << "            ";
		for (int j = 0; j < FIELD_WIDTH; j++) {
			cout << gameMap[i][j].getCurrentStateTexture() << ' ';
		}
		cout << endl;
	}
}
