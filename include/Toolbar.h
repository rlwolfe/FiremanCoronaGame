#pragma once
#include<iostream>
#include <SFML/Graphics.hpp>
#include <vector>
#include "const.h"
#include "Player.h"
#include "Question.h"

class Toolbar
{
public:
	Toolbar();
	void setKeyOn();
	void setKeyOff();
	bool pressON(sf::Vector2f location, int rec, int tex1, int tex2, bool play);
	void changeWeapon(weapon weap);
	void addLights();
	void drawToolbar(sf::RenderWindow& window, sf::View& view, int life, int water, int level, int score);
	~Toolbar();
private:
	void  loadIcons();
	void setStrings(int life, int water, int level, int score);
	void setPositions(sf::View& view);
	//Members
	sf::Text m_tex[NUM_TEX];
	sf::RectangleShape m_rec[NUM_REC];
};