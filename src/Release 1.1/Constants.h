#pragma once
#ifndef Constants_H
#define Constants_H

const int BORDER_OUT = 2;
const int MAX_ENEMIES = 3;
const int FIELD_HEIGHT = 15;
const int FIELD_WIDTH  = 15;
const int MAX_RAND_SETTINGS = 15;
const int MAX_WALL_LENGHT = 5;
const int MAX_ETANK_WAY = 20;
const int MIN_ETANK_WAY = 5;
const int MAX_HERO_LIVES = 3;
const int MINIMAL_TANK_DISTANCE = 2;
const int CASTLE_WALL_LENGHT = 3;
const int COUNT_DIRECTIONS = 4; 
const int DIFFICULT_LEVEL_SHOT_HERO = 60;
const int DIFFICULT_LEVEL_SHOT_GOLD = 10;
const int PERCENTS = 100;
const int SECONDS_MINUTES = 60;


const int ARROW_UP = 72;
const int ARROW_DOWN = 80;
const int ARROW_LEFT = 75;
const int ARROW_RIGHT = 77;
const int SPACE = 32;


const char BORDER_WALL = '"';
const char BULLET_TEXTURE_ = '.';
const char WALL_BLOCK_TWO_LIVES = '#';
const char HERO_TANK_TEXTURE = '8';

const char ENEMY_TANK_TEXTURE = '$';
const char EMPTY_AREA = ' ';
const char WALL_BLOCK_ONE_LIVE = '+';
const char ONE_GOLDEN_BLOCK = '%';


const char PORTAL = '*';
const char PORTAL_TO_POINT = 'O';

#endif // Constants_H
