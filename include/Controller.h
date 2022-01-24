#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>

#include "Const.h"
#include "Menu.h"
#include "Toolbar.h"
#include "Board.h"
#include "Question.h"
#include "SingleLoatData.h"
#include <fstream>

class Controller
{
public:
	Controller();
	~Controller() = default;
	void manageGame();
	
private:
	//-------draw functions-----------
	void drawLevel();
	void presentGame();
	void drawMenu();
	//-------loops functions-----------
	void inMenuFunc(sf::Event& event);
	void inQuestionFunc(sf::Event& event);
	void inHelpMenu();
	//-------updates functions-----------
	void openClocks();
	void updateGame();
	void updateShoots();
	//-------data functions-----------
	void handleView(sf::Vector2f current_view);
	void buildGame(std::ifstream& gameFile);
	void openFile(std::ifstream& gameFile, std::string fileName);
	void readBoard(std::ifstream& gameFile);
	//-------levels functions-----------
	void nextLevel(std::ifstream& gameFile);
	void GameOver(std::ifstream& gameFile);

	//-------members-----------
	std::unique_ptr<Menu> m_menu;
	std::unique_ptr<Board> m_board;
	std::unique_ptr<Toolbar> m_toolbar;
	std::unique_ptr<Question> m_question;
	sf::Music m_menuMusic;
	sf::RenderWindow m_window;
	sf::Clock m_clock, m_shootingClock, m_helpClock;
	sf::Time m_deltaTime, m_paused = sf::Time::Zero;
	sf::View m_viewPlayer;
	int m_level = 1, m_fire = 0;
	bool m_inMenu = true, m_inQuestion = false, m_inResult = false, m_help = false,
		m_startingGame = false, m_start = true, m_EndGame = false,
		m_play = true, m_sound = true;
};