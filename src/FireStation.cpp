#include "FireStation.h"

FireStation::FireStation()
{}

void FireStation::setSpriteSheet(sf::Time deltaTime)
{
	static sf::Time temp = sf::seconds(0.0);
	temp += deltaTime;

	if (temp.asSeconds() > 0.2)
	{
		setSpriteSource(sf::Vector2i(getSpriteSource().x + 1, getSpriteSource().y + Question::getAnswered()));
		if (getSpriteSource().x >= 2)
			setSpriteSource(sf::Vector2i(0, 0)); 
		temp = sf::seconds(0.0);
	}
	getSprite().setTextureRect(sf::IntRect(getSpriteSource().x * 471, getSpriteSource().y * 234, 471, 234));
	getSprite().setScale(0.4, 0.4);
}