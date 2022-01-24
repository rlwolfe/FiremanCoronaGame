#pragma once
//--------------------include Section --------------------
#include "StaticObject.h"
//--------------------Objects Class definition --------------------
class Hydrant : public StaticObject
{
public:
	//----constructor----
	using StaticObject::StaticObject;
	Hydrant();
	~Hydrant() = default;
	//----getFunctions----
	bool getFill();
	//----setFunctions----
	void setSpriteSheet(sf::Time deltaTime) override;
	//----Functions----
	void resetSpriteSheet(sf::Time deltaTime);

private:
	//----mambers----
	sf::Clock m_clock;
};