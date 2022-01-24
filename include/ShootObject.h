#pragma once
//--------------------include Section --------------------
#include "MovingObject.h"

//--------------------Objects Class definition --------------------
class ShootObject : public MovingObject
{
public:
	//---constructor -----
	ShootObject(sf::Vector2f& pos, sf::Texture& texture, sf::Vector2f& direction);
	~ShootObject() = default;
	//----setFunctions----
	void  setSpriteRotation();
	virtual void setSpriteSheet(sf::Time deltaTime) override;
	//----Functions----
	float distance(sf::Vector2f vec1, sf::Vector2f vec2);
	void  EndMove();
	void move(sf::Vector2f direction, sf::Time deltaTime) override;

private:
	//----Members----
	sf::Vector2f m_direction;
};