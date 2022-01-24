#include "Corona.h"


Corona::Corona(sf::Vector2f pos, sf::Texture& texture) :Enemy(pos, texture)
{//constructor
	getSprite().setTextureRect(sf::IntRect(0, 0, 50, 50));
	setSpriteSheet(sf::seconds(0.0));
	if (getSprite().getScale() != sf::Vector2f(0.8, 0.8))
		getSprite().setScale(0.8, 0.8);
	if(rand() % 2)
		setDirection(sf::Vector2f(0, -50));
	else
		setDirection(sf::Vector2f(0, 50));
}

void Corona::setSpriteSheet(sf::Time deltaTime)
{////set sprite depend on time
	static sf::Time temp = sf::seconds(0.0);
	temp += deltaTime;

	if (temp.asSeconds() > 0.25)
	{
		if (getSpriteSource().x >= 2)
			setSpriteSource(sf::Vector2i(0, 0));

		if (getSpriteSource().x < 2 && getSpriteSource().y >= 2)
			setSpriteSource(sf::Vector2i(getSpriteSource().x + 1, getSpriteSource().y));
		else
			setSpriteSource(sf::Vector2i(0, getSpriteSource().y + 1));

		temp = sf::seconds(0.0);
	}
	getSprite().setTextureRect(sf::IntRect(getSpriteSource().x * 50, getSpriteSource().y * 50, 50, 50));
}

void Corona::switchSides()
{//if the corona hits object so change the direction
	if (getSide() == DOWN)
		setSide(UP);
	else
		setSide(DOWN);
}

void Corona::setSideDirection(sf::Vector2f playerPos)
{//set the right side for going up or down
	if (getClock().getElapsedTime().asSeconds() > 0.5)
		getClock().restart();
	if (getPos().y <= (WINDOW_HEIGHT / 3.2) + 10)
		setSide(DOWN);
	else if (getSprite().getGlobalBounds().contains(WINDOW_LONG + WINDOW_WIDTH / 2, getPos().y))
		setSide(UP);
}