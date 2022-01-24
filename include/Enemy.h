#pragma once
//--------------------include Section --------------------
#include "MovingObject.h"

//forward decleration--
//class GameManager;

//--------------------Smart Monster Class definition --------------------
class Enemy : public MovingObject
{
public:
	//---constructor -----
	Enemy(sf::Vector2f pos, sf::Texture& texture);
	//----setFunctions----
	void setSpriteSheet(sf::Time deltaTime) {};
	virtual void setSideDirection(sf::Vector2f playerPos) { ; };
	//----getFunctions----
	sf::Clock& getClock() { return m_clock; };
	void setSide(int side) { m_side = side; };
	int getSide() const { return m_side; };
	//----Functions----
	virtual void changeDirection(sf::Vector2f playerPos) override;
private:
	//----Members----
	int m_side;
	sf::Clock m_clock;
};