#pragma once

#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include <string>
#include "Menu.h"
#include "Const.h"
#include "Fire.h"
#include "SingleLoatData.h"

class Question
{
public:
	Question(sf::View view, int level = 1, int difficulty = 0);
	void draw(sf::RenderWindow& window, int numImages);
	void setQuestions();
	void setSelected(int i);
	std::string getQuestion() { return m_riddle; }
	void moveDown();
	void moveUp();
	void setPosition(sf::View view);
	void setAnswerCorrect();
	int getPressedItem() const { return m_selectedItem; }
	void resetAnswer();
	void checkAnswer();// sf::RenderWindow& window);

	static int getAnswered() { return m_questionsAnswered; }
	static bool getKey() { return m_nextLevel; }
	static void setKey() { m_nextLevel = false; }
	static void newLevel();
	static void resetQuestions();
	static std::ifstream m_questionText;

private:

	static int m_questionsAnswered;
	static bool m_nextLevel, m_gameRestart;


	int m_level, m_difficulty, m_selectedItem = 1;
	bool m_correct = false;
	std::vector <std::string> m_wrong;
	std::string m_riddle, m_answer, m_selected;

	sf::Font m_riddleFont, m_answerFont;
	sf::Text m_text[ANSWERS + 1];
	sf::Texture m_texture;
	sf::RectangleShape m_scroll;
};