#pragma once
//--------------------include Section --------------------
#include "StaticObject.h"

//const int FIRE_STARTING = 3;
//--------------------Objects Class definition --------------------
class Fire : public StaticObject
{
public:
	using StaticObject::StaticObject;
	Fire();
	~Fire() = default;
	virtual void setSpriteSheet(sf::Time deltaTime) override;
	void fireOff();
	static int getCount();
	static int getLeft() { return m_fireLeft; }
	static void setLeft() { m_fireLeft++; }
	static void resetLeft() { m_fireLeft = 0; }
	static void resetCount();

private:
	static int m_fireputdown, m_fireLeft;
};