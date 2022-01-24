#include "Hydrant.h"
Hydrant::Hydrant()
{}

void Hydrant::setSpriteSheet(sf::Time deltaTime)
{
	getSprite().setTextureRect(sf::IntRect(getSpriteSource().x * 15, getSpriteSource().y * 23, 15, 23));
	getSprite().setScale(1.5, 1.5);
}

void Hydrant::resetSpriteSheet(sf::Time deltaTime)
{
	static sf::Time temp = sf::seconds(0.0);
	temp += deltaTime;

	if (temp.asSeconds() > 0.1)
	{
		setSpriteSource(sf::Vector2i(getSpriteSource().x + 1, getSpriteSource().y));
		if (getSpriteSource().x >= 4) 
			setSpriteSource(sf::Vector2i(0, 0));
		temp = sf::seconds(0.0);
	}
	getSprite().setTextureRect(sf::IntRect(getSpriteSource().x * 15, getSpriteSource().y * 23, 15, 23));
	getSprite().setScale(2, 2);
}

bool Hydrant::getFill()
{
	resetSpriteSheet(m_clock.getElapsedTime());
	if (m_clock.getElapsedTime().asSeconds() > HYDRANT_FILLUPT_TIME) {
		m_clock.restart();
		return true;
	}
	return false;
}