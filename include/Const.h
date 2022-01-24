#pragma once

//-----------------Menu Consts-------------------
const int MAX_NUMBER_OF_ITEMS = 5;
const int MENU_IMAGES = 3;//delete
const int MAIN_MENU_BACK = 0;
const int HELP_BACKGROUND = 1;
const int GAMEOVER_BACKGROUND = 2;

//-----------------Borad Consts-------------------
const char FIRE = 'F';
const char HYDRANT = 'H';
const char PLAYER = 'P';
const char CORONA = 'C';
const char WALL = 'W';
const char FIRENEMY = 'E';
const char FIRESTATION = 'S';
const char WOODWALL = 'D';

//-----------------singleton textures Consts-------------------
const int NUM_OF_TEXTURES = 33;
const int PLAYER_TEXTURE = 0;
const int FIRE_TEXTURE = 1;
const int HYDRANT_TEXTURE = 2;
const int CORONA_TEXTURE = 3;
const int WATER_TEXTURE = 4;
const int WALL_TEXTURE = 5;
const int FIRENEMY_TEXTURE = 6;
const int FIRESHOOT_TEXTURE = 7;
const int FIRESTATION_TEXTURE = 8;
const int PLAYER2_TEXTURE = 9;
const int WOODWALL_TEXTURE = 10;
const int ALCOGEL_TEXTURE = 11;
const int GAMEBACK_TEXTURE = 12;
const int CITYBACK_TEXTURE = 13;
const int GRASSBACK_TEXTURE = 14;
const int SOUND_TEXTURE = 15;
const int KEY_TEXTURE = 16;
const int PLAY_TEXTURE = 17;
const int PAUSE_TEXTURE = 18;
const int SOUNDOFF_TEXTURE = 19;
const int ALCOGELT_TEXTURE = 20;
const int WATERT_TEXTURE = 21;
const int AXET_TEXTURE = 22;
const int FIREM_TEXTURE = 23;
const int FIREHELPM_TEXTURE = 24;
const int GOCOVER_TEXTURE = 25;
const int SCROLL_TEXTURE = 26;
const int LIGHT_TEXTURE0 = 27;
const int LIGHT_TEXTURE1 = 28;
const int LIGHT_TEXTURE2 = 29;
const int LIGHT_TEXTURE3 = 30;
const int LIGHT_TEXTURE4 = 31;
const int LIGHT_TEXTURE5 = 32;


//-----------------singleton fonts Consts-------------------
const int FONT_SIZE = 4;
const int TOOLBAR_FONT = 0;
const int MENU_FONT = 1;
const int RIDDLE_FONT = 2;
const int ANSWER_FONT = 3;

//-----------------score points-------------------
const int PUTOUT_FIRE = 15;

//-----------------Controller Consts-------------------
//const sf::Keyboard::Key ESCAPE = sf::Keyboard::Key::Escape;
const int WINDOW_WIDTH = sf::VideoMode::getFullscreenModes()[0].width;
const int WINDOW_HEIGHT = sf::VideoMode::getDesktopMode().height;
const int BPP = sf::VideoMode::getFullscreenModes()[0].bitsPerPixel;
const int WINDOW_LONG = 4000;

//-----------------Riddle Consts-------------------
const int ANSWERS = 4;
const int DIFFICULTY = 5;
const int SCROLL_HEIGHT = 453;
const int SCROLL_WIDTH = 670;

//-----------------Hydrant Consts-------------------
const int HYDRANT_FILLUPT_TIME = 3;

//-----------------WaterShoot Consts-------------------
const int SHOOT_DISTANCE = 400;
const int HYDRANT_FILLUP = 5;

//Water ------------------------------
const int SHOOT_SIZE = 10;

//Static ------------------------------
const int BLOCK = 55;

//-----------------Color Consts-------------------
const sf::Color GREEN = sf::Color::Color(34, 139, 34);

//-----------------Toolbar Consts-------------------
const int NUM_TEX = 4;
const int NUM_REC = 5;

//-----------------Player Consts-------------------
const int PLAYER_HEIGHT = 41;
const int PLAYER_WIDTH = 29;
const float PLAYER_SPEED = 350;
const float PLAYER_SPEED_CORONA = 150;
//movement---
const int NUM_OF_DIRECT = 4;
const int DOWN = 0;
const int LEFT = 1;
const int RIGHT = 2;
const int UP = 3;
