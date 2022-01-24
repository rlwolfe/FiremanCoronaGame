#pragma once

//--------------------include Section --------------------
#include "StaticObject.h"
#include "Question.h"

//--------------------Objects Class definition --------------------
class FireStation : public StaticObject
{
public:
	using StaticObject::StaticObject;
	FireStation();
	~FireStation() = default;
	void setSpriteSheet(sf::Time deltaTime) override;
private:
};