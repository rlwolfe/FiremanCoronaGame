#include "ShootObject.h"

ShootObject::ShootObject(sf::Vector2f& pos, sf::Texture& texture, sf::Vector2f& direction)
	:MovingObject(pos, texture)
{//Constructor
	getSprite().setTextureRect(sf::IntRect(0, 0, SHOOT_SIZE, SHOOT_SIZE));
	setDirection(direction);
	setSpriteRotation();
	getSprite().setPosition(pos);
	if (direction.x != 0)		//sides
		getSprite().setPosition(sf::Vector2f(pos.x + 10, pos.y + 15));
	else if (direction.y > 0)		//down
		getSprite().setPosition(sf::Vector2f(pos.x + 8, pos.y + 30));
	else					//up
		getSprite().setPosition(sf::Vector2f(pos.x, pos.y - 15));
}

void ShootObject::setSpriteRotation()
{//set sprite Rotation by time
	int x = 0;
	if (getDirection().x != 0) {
		if (getDirection().x > 0)
			m_direction.y = RIGHT;
		else
			m_direction.y = LEFT;
	}
	else {
		if (getDirection().y > 0)
		{
			m_direction.y = DOWN;
		}
		else
		{
			m_direction.y = UP;
		}
	}
	setSpriteSource(sf::Vector2i(m_direction));
	getSprite().setTextureRect(sf::IntRect(SHOOT_SIZE * getSpriteSource().x, SHOOT_SIZE * getSpriteSource().y, SHOOT_SIZE, SHOOT_SIZE));
	getSprite().setScale(3, 3);
}

void ShootObject::move(sf::Vector2f direction, sf::Time deltaTime)
{// override function of move
	float speed = float(10 * deltaTime.asSeconds());
	if (!get_deleteMe())
	{
		getSprite().move(direction * deltaTime.asSeconds());
		setSpriteSheet(deltaTime);
	}
	EndMove();
}

void ShootObject::setSpriteSheet(sf::Time deltaTime)
{//set sprite picture by time
	static sf::Time temp = sf::seconds(0.0); 
	temp += deltaTime;

	if (temp.asSeconds() > 0.22)
	{
		setSpriteSource(sf::Vector2i(getSpriteSource().x + 1, getSpriteSource().y));
		if (getSpriteSource().x >= 5)
			setSpriteSource(sf::Vector2i(0, getSpriteSource().y));
		temp = sf::seconds(0.0);
	}
	getSprite().setTextureRect(sf::IntRect(getSpriteSource().x * SHOOT_SIZE, getSpriteSource().y * SHOOT_SIZE, SHOOT_SIZE, SHOOT_SIZE));
}

float ShootObject::distance(sf::Vector2f vec1, sf::Vector2f vec2) {
	//calculate distance between 2 points
	return sqrt(pow(vec1.x - vec2.x, 2) + pow(vec1.y - vec2.y, 2));
}

void  ShootObject::EndMove()
{//check if the shoot out of range
	if (distance(getStartingPoint(), getPos()) >= SHOOT_DISTANCE)
		set_delete_me();
	else if (checkLimits())
		set_delete_me();
}
