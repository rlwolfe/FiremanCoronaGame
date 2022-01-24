#include "Menu.h"
#include "SingleLoatData.h"



//---------------Menu constructor--------------------
Menu::Menu(float width, float height) :m_amount(MAX_NUMBER_OF_ITEMS)
{
	for (int i = 0; i < m_amount - 1; i++)
	{	
		if (i < m_amount) {
			m_menu[i].setOutlineThickness(20);			//defines the menu, from text to background
			m_menu[i].setFont(SingleLoatData::getInstance()->getFonts(MENU_FONT));
			m_menu[i].setCharacterSize(int(width / 15));
		}
		switch (i)
		{
		case 0:
			m_menu[i].setFillColor(sf::Color::Yellow);
			m_menu[i].setString("Play");
			m_menu[i].setPosition(sf::Vector2f((width / 2.35f), height / (m_amount * 2.0f) * 4.0f));
			break;
		case 1:
			m_menu[i].setFillColor(sf::Color::White);
			m_menu[i].setString("Help");
			m_menu[i].setPosition(sf::Vector2f(width / 2.35f, height / (m_amount * 2.0f) * 5.5f));
			break;

		case 2:
			m_menu[i].setFillColor(sf::Color::White);
			m_menu[i].setString("Quit");
			m_menu[i].setPosition(sf::Vector2f(width / 2.35f, height / (m_amount * 2.0f) * 7.0f));
			break;
		case 3:
			m_menu[i].setFillColor(sf::Color::White);
			m_menu[i].setString("Back");
			m_menu[i].setPosition(sf::Vector2f(width /2.0f + 100, height -130.0f));
			m_menu[i].setCharacterSize(int(width / 45));
			m_menu[i].setOutlineThickness(5);
			m_menu[i].setFillColor(sf::Color::Yellow);
			break;
		}
		if (i < MENU_IMAGES) {
			m_menuBack[i].setSize(sf::Vector2f(width, height));
			auto n = i + 23;
			m_menuBack[i].setTexture(&SingleLoatData::getInstance()->get_texture(n));
			m_menuBack[i].setPosition(0, 0);
		}
	}
}
//---------------draw function   
void Menu::draw(sf::RenderWindow& window, int numImages)
{
	window.draw(m_menuBack[numImages]);
	if (numImages == MAIN_MENU_BACK || numImages == GAMEOVER_BACKGROUND)
	{
		for (int i = 0; i < 3; i++)		//draw the menu------
		{
			window.draw(m_menu[i]);
		}
	}
	else {
		window.draw(m_menu[MAX_NUMBER_OF_ITEMS-1]);//CHECK
		window.draw(m_menu[MAX_NUMBER_OF_ITEMS - 2]);
	}
}
//---------------MoveUp function--------------------
void Menu::MoveUp()
{
	if (m_selectedItemIndex - 1 >= 0)//move up in menu
	{
		m_menu[m_selectedItemIndex].setFillColor(sf::Color::White);
		m_selectedItemIndex--;
		m_menu[m_selectedItemIndex].setFillColor(sf::Color::Yellow);
	}
}
//---------------MoveDown function--------------------
void Menu::MoveDown()
{
	if (m_selectedItemIndex + 3 < MAX_NUMBER_OF_ITEMS)		//move down in menu
	{
		m_menu[m_selectedItemIndex].setFillColor(sf::Color::White);
		m_selectedItemIndex++;
		m_menu[m_selectedItemIndex].setFillColor(sf::Color::Yellow);
	}
}
