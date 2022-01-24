#pragma once
//--------------------include Section --------------------
#include "ShootObject.h"

//--------------------Objects Class definition --------------------
class WaterShoot : public ShootObject
{
public:
	WaterShoot(sf::Vector2f pos, sf::Texture& texture, sf::Vector2f direction);
	~WaterShoot() = default;
private:

};