#pragma once
//--------------------include Section --------------------
#include "ShootObject.h"

//--------------------Objects Class definition --------------------
class FireShoot : public ShootObject
{
public:
	FireShoot(sf::Vector2f pos, sf::Texture& texture, sf::Vector2f direction);
	~FireShoot() = default;
private:

};