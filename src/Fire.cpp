#include "Fire.h"

//static variable for count how many fire until the question jumping
int Fire::m_fireputdown = 0;
//static variable for check if the player putoff all the fire and didnt answer right enough questions
int Fire::m_fireLeft = 0;  

Fire::Fire()
{}

void Fire::setSpriteSheet(sf::Time deltaTime)
{//set sprite by time so the fire looks like it burn
	static sf::Time temp = sf::seconds(0.0);
	temp += deltaTime;

	if (temp.asSeconds() > 0.01)
	{
		if (getSpriteSource().x == 7 && getSpriteSource().y == 3)
			setSpriteSource(sf::Vector2i(0, 0));

		if (getSpriteSource().x < 7)
			setSpriteSource(sf::Vector2i(getSpriteSource().x + 1, getSpriteSource().y));
		else
			setSpriteSource(sf::Vector2i(0, getSpriteSource().y + 1));

		temp = sf::seconds(0.0);
	}
	getSprite().setTextureRect(sf::IntRect(getSpriteSource().x * BLOCK, getSpriteSource().y * BLOCK, BLOCK, BLOCK));
	getSprite().setScale(1.5, 1.5);
}

int Fire::getCount()
{
	return m_fireputdown;
}

void Fire::resetCount()
{
	m_fireputdown = 0;
}

void Fire::fireOff()
{
	++m_fireputdown;
	m_fireLeft--;
}
