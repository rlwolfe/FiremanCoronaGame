#include "FireShoot.h"

FireShoot::FireShoot(sf::Vector2f pos, sf::Texture& texture, sf::Vector2f direction)
	: ShootObject(pos, texture, direction)
{
	setDirection(getDirection() + getDirection() + getDirection());//make fire shoot faster
}