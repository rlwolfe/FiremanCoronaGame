#include "GameObject.h"

//====================constructor================
GameObject::GameObject(sf::Vector2f pos,
						sf::Texture& texture)
{
	texture.setSmooth(true);
	m_objectSprite.setTexture(texture);
	m_location.x = pos.y * 80;
	m_location.y = pos.x * 80 + WINDOW_HEIGHT / 3;
	m_objectSprite.setPosition(sf::Vector2f(m_location.x, m_location.y));	
	m_spriteSource = sf::Vector2i(0, 0);
}
//==============

//=============
sf::Vector2f GameObject::getPos() const
{
	return m_objectSprite.getPosition();
}
//=============

void  GameObject::setPos(sf::Vector2f pos)
{
	m_objectSprite.setPosition(pos);
}
//==============

//==============
sf::Sprite& GameObject::getSprite()
{
	return m_objectSprite;
}
//===============

//===============
void GameObject::draw(sf::RenderWindow& window)
{
	window.draw(m_objectSprite);
}
//===============

//==============

bool GameObject::get_deleteMe() const
{
	return m_deleteMe;
}

void GameObject::set_delete_me()
{
	m_deleteMe = true;
}

GameObject::~GameObject()
{
}
//=============

