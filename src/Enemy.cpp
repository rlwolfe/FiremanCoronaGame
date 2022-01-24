#include "Enemy.h"

Enemy::Enemy(sf::Vector2f pos, sf::Texture& texture) 
	:MovingObject(pos, texture)
{}

//---------------------changeDirection function --------------------------
void Enemy::changeDirection(sf::Vector2f playerPos)
{//virtual function of enemy let them choose their side and than set Direction
	float movingRate = 50;
	setSideDirection(playerPos);
	if (m_side == RIGHT)
		setDirection(sf::Vector2f(movingRate, 0));
	else if (m_side == LEFT)
		setDirection(sf::Vector2f(-movingRate, 0));
	else if (m_side == DOWN)
		setDirection(sf::Vector2f(0, movingRate));
	else if (m_side == UP)
		setDirection(sf::Vector2f(0, -movingRate));
}

