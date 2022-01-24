#include "MovingObject.h"

MovingObject::MovingObject(sf::Vector2f pos, sf::Texture& texture)
	: GameObject(pos, texture), m_startingPoint(pos)
{}


void MovingObject::move(sf::Vector2f direction, sf::Time deltaTime)
{
	getSprite().move(direction * deltaTime.asSeconds());
	if (checkLimits())
		getSprite().move(-direction * deltaTime.asSeconds());
	setDeltaTime(deltaTime);
}

bool MovingObject::checkLimits() {
	if (getPos().x < 0 || getPos().y < WINDOW_HEIGHT / 3.2 ||
		getSprite().getGlobalBounds().contains(getPos().x, WINDOW_HEIGHT)
		|| getSprite().getGlobalBounds().contains(WINDOW_LONG + WINDOW_WIDTH/2, getPos().y))
		return true;
	return false;
}

void MovingObject::setDeltaTime(sf::Time deltaTime)
{
	m_deltaTime = deltaTime;
}

//get functions-----------
sf::Vector2f MovingObject::getDirection() const
{
	return m_direction;
}
void MovingObject::setDirection(sf::Vector2f direction)
{
	m_direction = direction;
}

sf::Vector2f MovingObject::getStartingPoint() const
{
	return m_startingPoint;
}

sf::Time MovingObject::getDeltaTime() const
{
	return m_deltaTime;
}

