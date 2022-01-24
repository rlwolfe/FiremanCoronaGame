//GameObject Class 
//***************
//this a father for all grapghical objects in the game
//***************
#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include "Const.h"

class GameObject
{
public:
	GameObject(sf::Vector2f pos, sf::Texture& texture);
	GameObject() {};
	virtual ~GameObject();
	//----getFunctions----
	sf::Vector2i getSpriteSource() const { return m_spriteSource; };
	sf::Sprite& getSprite();
	sf::Vector2f getPos() const;
	bool get_deleteMe() const;
	//----setFunctions----
	void setSpriteSource(sf::Vector2i source) { m_spriteSource = source; };
	void set_delete_me();
	void setPos(sf::Vector2f pos);
	virtual void setSpriteSheet(sf::Time deltaTime) = 0;
	//----Functions----
	virtual void draw(sf::RenderWindow& window);

private:
	//----Members----
	sf::Vector2f m_location;
	sf::Sprite m_objectSprite;
	bool m_deleteMe = false;
	sf::Vector2i m_spriteSource;
};