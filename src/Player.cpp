#include "Player.h"

Player::Player(sf::Vector2f pos, sf::Texture& texture) :
	MovingObject(pos, texture)
{
	getSprite().setTextureRect(sf::IntRect(0, 0, PLAYER_WIDTH, PLAYER_HEIGHT));
}

void Player::updateSpeed()
{//after hit corona his speed get lower
	if (m_speedClock.getElapsedTime().asSeconds() > 10)
		m_slow = false;
	if (m_slow)
		m_speed = PLAYER_SPEED_CORONA;
	else
		m_speed = PLAYER_SPEED;
}

void Player::setSlow()
{
	m_slow = true;
	m_speedClock.restart();
}

void Player::changeDirection(sf::Vector2f playerPos)
{//change the direction of the player by the user press
	updateSpeed();
	setDirection(sf::Vector2f(0, 0));
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Up))
	{
		setDirection(sf::Vector2f(0, -m_speed));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			setDirection(sf::Vector2f(m_speed, -m_speed));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			setDirection(sf::Vector2f(-m_speed, -m_speed));
	}

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Down))
	{
		setDirection(sf::Vector2f(0, m_speed));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
			setDirection(sf::Vector2f(m_speed, m_speed));
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
			setDirection(sf::Vector2f(-m_speed, m_speed));

	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Right))
		setDirection(sf::Vector2f(m_speed, 0));

	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::Left))
		setDirection(sf::Vector2f(-m_speed, 0));

	if (getDirection() != sf::Vector2f(0, 0))
		set_last_dir(getDirection());
}

void Player::setSpriteSheet(sf::Time deltaTime)
{//set the picutre by the side the player go
	static sf::Time temp = sf::seconds(0.0);
	temp += deltaTime;

	if (temp.asSeconds() > 0.2)
	{
		setSpriteSource(sf::Vector2i(getSpriteSource().x + 1, getSpriteSource().y));
		temp = sf::seconds(0.0);
	}
	if ((getSpriteSource().x * PLAYER_WIDTH) >= (this->getSprite().getTexture()->getSize().x))
	{
		setSpriteSource(sf::Vector2i(0, getSpriteSource().y));
	}

	if (getDirection().x != 0)
	{
		if (getDirection().x > 0)
			setSpriteSource(sf::Vector2i(getSpriteSource().x, RIGHT));
		else
			setSpriteSource(sf::Vector2i(getSpriteSource().x, LEFT));
	}
	else
	{
		if (getDirection().y > 0)
			setSpriteSource(sf::Vector2i(getSpriteSource().x, DOWN));
		else
			setSpriteSource(sf::Vector2i(getSpriteSource().x, UP));
	}
	if(getDirection() != sf::Vector2f(0,0))			// for the play wont change direction when user unpress keyboard
		getSprite().setTextureRect(sf::IntRect(getSpriteSource().x * PLAYER_WIDTH, getSpriteSource().y * PLAYER_HEIGHT, PLAYER_WIDTH, PLAYER_HEIGHT));
	getSprite().setScale(1.2, 1.2);	
}

bool Player::shoot()
{//shoot water/alcogel depend on the weapon of the player
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) {	
		if (m_weapon == weapon::alcogel)
			return true;
		else if (m_weapon == weapon::water && canShootWater()) {
			decrease_water();
			return true;
		}	
	}
	return false;
}

bool Player::updateWeapon(sf::Texture& guntex, sf::Texture& axetex)
{//update the current waepon of the player
	if (m_ChangeClock.getElapsedTime().asSeconds() > 0.20) {
		if(sf::Keyboard::isKeyPressed(sf::Keyboard::LControl)) {
			changeWeapon();
			change_sprite(guntex, axetex);
			m_ChangeClock.restart();
			return true;		
		}	
	}
	return false;
}

void Player::change_sprite(sf::Texture& guntex, sf::Texture& axetex)
{//change sprite depend on player weapon
	if (m_weapon == weapon::water || m_weapon == alcogel)
		getSprite().setTexture(guntex);
	else 
		getSprite().setTexture(axetex);
}

void Player::changeWeapon()
{//change waepon of the player
	if (m_weapon == weapon::water)
		m_weapon = weapon::alcogel;
	else if (m_weapon == weapon::alcogel)
		m_weapon = weapon::axe;
	else
		m_weapon = weapon::water;
}

int Player::get_water() const
{
	return m_water;
}

void Player::add_water(int sum)
{
	m_water += sum;
}

bool Player::canShootWater() const
{
	return (m_water > 0 && m_weapon == weapon::water);
}

void Player::decrease_water()
{
	m_water--;
}

int Player::getScore() const
{
	return m_score;
}

void Player::add_score(int sum)
{
	m_score += sum;
}

int Player::getLife() const
{
	return m_life;
}

void Player::decrease_life()
{
	m_life--;
}

bool Player::is_live()
{
	if(m_life == 0)
		return false;
	return true;
}

void Player::set_last_dir(sf::Vector2f vec)
{
	m_last_dir = vec;
}

