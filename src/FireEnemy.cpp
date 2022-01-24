#include "FireEnemy.h"

template <typename Array, typename kind>
void resetSides(Array arr, kind r)
{//template function for reset different data to difrent kind of array
	for (int i = 0; i < NUM_OF_DIRECT; i++)
		arr[i] = r;
}

FireEnemy::FireEnemy(sf::Vector2f pos, sf::Texture& texture) :Enemy(pos, texture)
{//reset the data by call template function
	resetSides(m_sides,true);
	resetSides(m_direct, RIGHT);
}

void FireEnemy::setSideCollision(int place)
{//fire enemy collision object so set this side to false
	m_sides[place] = false;
}


void FireEnemy::setDirectionHelp(int dir1, int dir2, int num1, int num2)
{//help function
	m_direct[dir1] = num1;
	m_direct[dir2] = num2;
}

void FireEnemy::checkXside(sf::Vector2f playerPos)
{//check the best way to chase the player on X axis
	if (playerPos.x > getPos().x)
		setDirectionHelp(LEFT, DOWN, RIGHT, LEFT);
	else
		setDirectionHelp(LEFT, DOWN, LEFT, RIGHT);
}

void FireEnemy::checkYside(sf::Vector2f playerPos)
{//check the best way to chase the player on Y axis
	if (playerPos.y > getPos().y)
		setDirectionHelp(LEFT, DOWN, DOWN, UP);
	else
		setDirectionHelp(LEFT, DOWN, UP, DOWN);
}

void FireEnemy::setSideDirection(sf::Vector2f playerPos)
{/*Decide the side chasing the player by each loop deretmine the 
	better place to go for the player and if that direction is already had 
	collision with other object block his way so go the best direction afterward */
	checkClocks();
	if (getClock().getElapsedTime().asSeconds() > 2.5 || m_start) {
		m_start = false;
		if (std::abs(playerPos.x - getPos().x) > std::abs(playerPos.y - getPos().y)) {
			if (playerPos.x > getPos().x) {
				setDirectionHelp(RIGHT, UP, RIGHT, LEFT);
				checkYside(playerPos);
			}
			else {
				setDirectionHelp(RIGHT, UP, LEFT, RIGHT);
				checkYside(playerPos);
			}
		}
		else {
			if (playerPos.y > getPos().y) {
				setDirectionHelp(RIGHT, UP, DOWN, UP);
				checkXside(playerPos);
			}
			else {
				setDirectionHelp(RIGHT, UP, UP, DOWN);
				checkXside(playerPos);
			}
		}
		go();
		getClock().restart();
	}
}

void FireEnemy::checkClocks() 
{//reset the false of the direction who got coliision f
	if (m_moveClock.getElapsedTime().asSeconds() > 1) {
		m_moveClock.restart();
		resetSides(m_sides, true);
	}
}

void FireEnemy::go()
{/*check if the best way to go didnt had collision before 
	//and if it has collision so go other way*/
	if (m_sides[m_direct[RIGHT]] == true)
		setSide(m_direct[RIGHT]);
	else if (m_sides[m_direct[LEFT]] == true)
		setSide(m_direct[LEFT]);
	else if (m_sides[m_direct[DOWN]] == true)
		setSide(m_direct[DOWN]);
	else if (m_sides[m_direct[UP]] == true)
		setSide(m_direct[UP]);
}

bool FireEnemy::shootFire()
{//shoot fire to the direction limitid by time
	if (m_fireClock.getElapsedTime().asSeconds() > 2) {
		m_fireClock.restart();
		return true;
	}
	return false;
}
