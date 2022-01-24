#pragma once
#include "MovingObject.h"
#include "WaterShoot.h"
#include <list>
#include <vector>

enum weapon {
	water, alcogel,axe 
};

class Player : public MovingObject
{
public:
	//----constructor----
	Player(sf::Vector2f pos, sf::Texture& texture);
	~Player() = default;
	//----getFunctions----
	int get_water() const;
	int getScore() const;
	int getLife() const;
	bool getWin() const { return m_win_level; };
	bool is_live();
	sf::Vector2f get_last_dir() const { return m_last_dir; };
	enum weapon getWeapon() const { return m_weapon; };
	//----setFunctions----
	void setWin(bool b) { m_win_level = b; };
	void setLife(int life) { m_life = life; };
	void setScore(int score) { m_score = score; };
	void setSlow();
	virtual void setSpriteSheet(sf::Time deltaTime) override;
	void set_last_dir(sf::Vector2f vec);
	//----Functions----
	void changeDirection(sf::Vector2f playerPos) override;
	bool canShootWater() const;
	void add_score(int sum);
	void decrease_life();
	void add_water(int sum);
	void decrease_water();
	bool shoot();
	void resetLife() { m_life = 3; };
	bool updateWeapon(sf::Texture& guntex, sf::Texture& axetex);
	void changeWeapon();

private:
	//----parivate Functions----
	void updateSpeed();
	void change_sprite(sf::Texture& guntex, sf::Texture& axetex);
	//----Members----
	sf::Vector2f m_last_dir = sf::Vector2f(300, 0);
	sf::Clock m_ChangeClock,
		m_speedClock;
	enum weapon m_weapon = water;
	bool m_win_level = false, m_slow = false;
	float m_speed = 350;
	int m_water = 20,
		m_life = 3,
		m_score = 0;
};