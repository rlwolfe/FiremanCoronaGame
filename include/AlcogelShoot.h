#pragma once
//--------------------include Section --------------------
#include "ShootObject.h"

//--------------------Objects Class definition --------------------
class AlcogelShoot : public ShootObject
{
public:
	AlcogelShoot(sf::Vector2f pos, sf::Texture& texture, sf::Vector2f direction);
	~AlcogelShoot() = default;
private:

};