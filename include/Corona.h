#pragma once
//--------------------include Section --------------------
#include "Enemy.h"

//forward decleration--
//class GameManager;

//--------------------Smart Monster Class definition --------------------
class Corona : public Enemy
{
public:
	//------constructor ----
	Corona(sf::Vector2f pos, sf::Texture& texture);
	//----setFunctions-----
	void setSpriteSheet(sf::Time deltaTime) override;
	void setSideDirection(sf::Vector2f playerPos) override;
	//----Functions----
	void switchSides();
private:
};