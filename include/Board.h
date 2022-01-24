#pragma once
//----include general---
#include <SFML/Graphics.hpp>
#include <vector>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib> 
#include <stdlib.h>
#include <fstream>
#include <list>
#include <string>
#include<istream>
#include <experimental/list>
//----include gameobjects-----
#include "Player.h"
#include "WaterShoot.h"
#include "StaticObject.h"
#include "Fire.h"
#include "Hydrant.h"
#include "Corona.h"
#include "Wall.h"
#include "FireEnemy.h"
#include "FireShoot.h"
#include "FireStation.h"
#include "WoodWall.h"
#include "AlcogelShoot.h"
#include "SingleLoatData.h"

class Board
{
public:
	Board() {};
	~Board() = default;

	//-------getObjects functions-----------
	std::shared_ptr <Player>& getPlayer();
	std::list<std::unique_ptr <StaticObject>>& getStatics();
	std::list<std::shared_ptr <FireEnemy>>&  getFireEnemys();
	//-------read functions-----------
	void readStageFromFile(std::ifstream& gameFile, bool& game);
	void readObjectsFromFile();
	void buildBoard(sf::RenderWindow& window);
	//-------runboard functions-----------
	void check_collision();
	bool setWeapon();
	void move(sf::Time deltaTime);
	void shoot();
	void checkdelete();
	void shootFireenemy();
	void clear();
	void changeBackgroundLevel(int level);
	void draw(sf::RenderWindow& window, sf::Time deltaTime);

private:
	//-------Members-----------
	sf::RectangleShape m_backGroundRec;
	std::shared_ptr <Player> m_player;
	std::list<std::unique_ptr <StaticObject>> m_staticObjects;
	std::list<std::shared_ptr <MovingObject>> m_movingObjects;
	std::list<std::shared_ptr <FireEnemy>> m_FireEnemys;
	std::vector <std::vector < char > > m_boardRepresentation;


};