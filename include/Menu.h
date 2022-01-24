#pragma once
//--------------------include Section --------------------
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <cstdlib> 
#include <iostream> 
#include <vector>

#include "Const.h"

//--------------------Menu Class definition --------------------
class Menu
{
public:
	//Menu();			//constructors
	Menu(float width, float height);
	//handle menu functions--------------
	void draw(sf::RenderWindow& window, int numImages);
	void MoveUp();
	void MoveDown();
	//get function-------------
	int getPressedItem() const { return m_selectedItemIndex; }
private:
	int m_selectedItemIndex = 0, m_amount;
	sf::Text m_menu[MAX_NUMBER_OF_ITEMS];//menu text
	sf::RectangleShape m_menuBack[MENU_IMAGES];		//menu picturs in rec
};