#pragma once
//--------------------include Section --------------------
#include "GameObject.h"
//class Controller;

//--------------------Objects Class definition --------------------
class MovingObject : public GameObject
{
public:
	MovingObject(sf::Vector2f pos, sf::Texture& texture);
	MovingObject() {};

	bool checkLimits();
	//virtuals funcions--------------
	virtual void move(sf::Vector2f direction, sf::Time deltaTime);
	virtual void changeDirection(sf::Vector2f playerPos) {};
	virtual void setSpriteSheet(sf::Time deltaTime) {};

	//set functions-----------
	void setDirection(sf::Vector2f direction);
	void setDeltaTime(sf::Time deltaTime);
	//get functions-----------
	sf::Vector2f getDirection() const;
	sf::Vector2f getStartingPoint() const;
	sf::Time getDeltaTime() const;
	
private:
	sf::Vector2f m_direction;
	sf::Time m_deltaTime;
	sf::Vector2f m_startingPoint;
};