
#pragma once
//--------------------include Section --------------------
#include "Enemy.h"


//--------------------Smart Monster Class definition --------------------
class FireEnemy : public Enemy
{
public:
	//constructor ---------------
	FireEnemy(sf::Vector2f pos, sf::Texture& texture);
	//----setFunctions----
	void setSideDirection(sf::Vector2f playerPos) override;
	void setDirectionHelp(int dir1, int dir2, int num1, int num2);
	void setSideCollision(int place);
	//----Functions----
	bool shootFire();

private:
	//----private Functions----
	void checkClocks();
	void go();
	void checkXside(sf::Vector2f playerPos);
	void checkYside(sf::Vector2f playerPos);
	//----private Members----
	bool m_start = true;
	sf::Clock m_moveClock,
		m_fireClock;
	bool m_sides[4];
	int m_direct[4];
};