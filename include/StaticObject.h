#pragma once
//--------------------include Section --------------------
#include "GameObject.h"

//--------------------Static Objects Class definition --------------------
class StaticObject : public GameObject
{
public:
	using GameObject::GameObject;
	StaticObject();
	virtual void setSpriteSheet(sf::Time deltaTime) { getSprite().setScale(1.5, 1.5); };
private:
};