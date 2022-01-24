#pragma once

#include "Question.h"

bool Question::m_nextLevel = false;
bool Question::m_gameRestart = false;
int Question::m_questionsAnswered = 0;

Question::Question(sf::View view, int level, int difficulty) : m_level(level), m_difficulty(difficulty)
{
	setQuestions();

	m_scroll.setSize(sf::Vector2f(SCROLL_WIDTH, SCROLL_HEIGHT));
	if (SCROLL_WIDTH * 2 < WINDOW_WIDTH && SCROLL_HEIGHT * 2 < WINDOW_HEIGHT)
		m_scroll.setScale(2, 2);
	m_scroll.setTexture(&SingleLoatData::getInstance()->get_texture(SCROLL_TEXTURE));

	for (int i = 0; i <= ANSWERS; i++)
	{
		if (i == 0) {
			if (m_scroll.getScale() == sf::Vector2f(1, 1))
				m_text[i].setCharacterSize(m_scroll.getSize().x / 35);
			else
				m_text[i].setCharacterSize(m_scroll.getSize().x / 15);
			m_text[i].setFont(SingleLoatData::getInstance()->getFonts(RIDDLE_FONT));
			m_text[i].setFillColor(sf::Color::White);
			m_text[i].setString(m_riddle);
		}
		else {
			if (i == 1)
				m_text[i].setFillColor(sf::Color::Red);
			else
				m_text[i].setFillColor(sf::Color::White);

			if (m_scroll.getScale() == sf::Vector2f(1, 1))
				m_text[i].setCharacterSize(m_scroll.getSize().x / 20);
			else
				m_text[i].setCharacterSize(m_scroll.getSize().x / 10);

			m_text[i].setFont(SingleLoatData::getInstance()->getFonts(ANSWER_FONT));
		}

		m_text[i].setOutlineThickness(5);

	}
	setPosition(view);
}

void Question::setQuestions()
{
	m_wrong.clear();
	if (m_gameRestart) {
		m_difficulty = 0;
		m_level = 1;
		m_gameRestart = false;
	}

	if (m_nextLevel) {
		m_riddle = "";
		return;
	}
	switch (m_level) {
	case 1:
		switch (m_difficulty) {
		case 0:
			m_riddle = "What does OOP stand for?";
			m_answer = "Object Oriented Programming";
			m_wrong.push_back("Oompa Loompa");
			m_wrong.push_back("Obviously On Point");
			m_wrong.push_back("Out of Portugal");
			break;
		case 1:
			m_riddle = "Jon had 6 apples and gave half to Reuven,\nhow many apples does he have left?";
			m_answer = "3";
			m_wrong.push_back("1");
			m_wrong.push_back("4");
			m_wrong.push_back("6");
			break;
		case 2:
			m_riddle = "What is another word for tough?";
			m_answer = "Complicated";
			m_wrong.push_back("Never");
			m_wrong.push_back("Currently");
			m_wrong.push_back("Happy");
			break;
		case 3:
			m_riddle = "What does dispute mean?";
			m_answer = "Disagreement";
			m_wrong.push_back("Wrong");
			m_wrong.push_back("Fun");
			m_wrong.push_back("House");
			break;
		case 4:
			m_riddle = "What rhymes with dance, prance and France?";
			m_answer = "Chance";
			m_wrong.push_back("Prize");
			m_wrong.push_back("High-five");
			m_wrong.push_back("Can't");
			break;
		}
		break;
	case 2:
		switch (m_difficulty) {
		case 0:
			m_riddle = "How do you spell the pet that barks?";
			m_answer = "Dog";
			m_wrong.push_back("Dag");
			m_wrong.push_back("Dawg");
			m_wrong.push_back("Dug");
			break;
		case 1:
			m_riddle = "What time is it 5 hours after 20:00?";
			m_answer = "1:00";
			m_wrong.push_back("12:00");
			m_wrong.push_back("00:00");
			m_wrong.push_back("25:00");
			break;
		case 2:
			m_riddle = "If Danielle had 4 rabbits and they each had\n 3 bunnies, how many rabbits were there in total?";
			m_answer = "12";
			m_wrong.push_back("2");
			m_wrong.push_back("7");
			m_wrong.push_back("24");
			break;
		case 3:
			m_riddle = "How many sides does an octagon have?";
			m_answer = "8";
			m_wrong.push_back("5");
			m_wrong.push_back("10");
			m_wrong.push_back("19");
			break;
		case 4:
			m_riddle = "If you have 3 point and need 20 points to win,\nhow many more points do you need?";
			m_answer = "17";
			m_wrong.push_back("6");
			m_wrong.push_back("20");
			m_wrong.push_back("14");
			break;
		}
		break;
	case 3:
		switch (m_difficulty) {
		case 0:
			m_riddle = "What do people need to breath to live?";
			m_answer = "Oxygen";
			m_wrong.push_back("Helium");
			m_wrong.push_back("Calcium");
			m_wrong.push_back("H2O");
			break;
		case 1:
			m_riddle = "Which is not flammable?";
			m_answer = "Stone";
			m_wrong.push_back("Oxygen");
			m_wrong.push_back("Wood");
			m_wrong.push_back("Alcohol");
			break;
		case 2:
			m_riddle = "What country does NOT border Israel?";
			m_answer = "Cyprus";
			m_wrong.push_back("Lebanon");
			m_wrong.push_back("Egypt");
			m_wrong.push_back("Jordan");
			break;
		case 3:
			m_riddle = "What is water made up of?";
			m_answer = "Hydrogen and Oxygen";
			m_wrong.push_back("Helium and Potassium");
			m_wrong.push_back("Drops of smaller water");
			m_wrong.push_back("Minerals");
			break;
		case 4:
			m_riddle = "Which country was not one of Allied forces in WWII";
			m_answer = "Italy";
			m_wrong.push_back("United States");
			m_wrong.push_back("United Kingdom");
			m_wrong.push_back("Russia");
			break;
		}
		break;
	default:
		m_riddle = "";
		m_answer = "";
		for (auto answers : m_wrong)
			answers = "";
	}

	srand(time(NULL));
	int place = rand() % 4;
	m_wrong.insert(m_wrong.begin() + place, m_answer);

	m_text[0].setString(m_riddle);
	for (int i = 1; i <= ANSWERS; i++)
		m_text[i].setString(m_wrong[i - 1]);
}

void Question::setPosition(sf::View view)
{
	for (int i = 0; i <= ANSWERS; i++)
	{
		if (m_scroll.getScale() == sf::Vector2f(1, 1))
			m_text[i].setPosition(sf::Vector2f(view.sf::View::getCenter().x - (SCROLL_WIDTH / 2) + (SCROLL_WIDTH / 20),
			(view.sf::View::getCenter().y - (SCROLL_HEIGHT / 2)) + SCROLL_HEIGHT / (ANSWERS * 2) * (1.5 + i)));
		else
			m_text[i].setPosition(sf::Vector2f(view.sf::View::getCenter().x - (m_scroll.getSize().x) + (m_scroll.getSize().x / 10),
			(view.sf::View::getCenter().y - (m_scroll.getSize().y)) + m_scroll.getSize().y / (ANSWERS) * (1.5 + i)));
	}
	if (m_scroll.getScale() == sf::Vector2f(1, 1))
		m_scroll.setPosition(view.sf::View::getCenter().x - (SCROLL_WIDTH / 2), view.sf::View::getCenter().y - (SCROLL_HEIGHT / 2));
	else
		m_scroll.setPosition(view.sf::View::getCenter().x - (m_scroll.getSize().x), view.sf::View::getCenter().y - (m_scroll.getSize().y));
}

void Question::setSelected(int i)
{
	m_selected = m_text[i].getString();
}


void Question::checkAnswer()
{
	if (m_answer == m_selected)
		setAnswerCorrect();
}

void Question::setAnswerCorrect()
{
	m_difficulty++;
	m_questionsAnswered++;
	m_correct = true;
	resetAnswer();

	if (m_difficulty == DIFFICULTY) {
		m_nextLevel = true;
		m_difficulty = 0;
		m_level++;
	}
}

void Question::resetAnswer()
{
	m_correct = false;
	m_riddle = m_answer = "";

	for (int i = 0; i < ANSWERS; i++)
		m_wrong[i] = "";
}

void Question::newLevel()
{
	setKey();
	m_questionsAnswered = 0;
}

void Question::resetQuestions()
{
	newLevel();
	Fire::resetCount();
	m_gameRestart = true;
}

void Question::draw(sf::RenderWindow& window, int numImages)
{
	if (m_gameRestart)
		m_difficulty = 0;

	if (m_riddle == "" && m_difficulty < DIFFICULTY && !m_nextLevel)
		setQuestions();

	window.draw(m_scroll);
	for (int i = 0; i <= ANSWERS; i++)
	{
		window.draw(m_text[i]);
	}
}

void Question::moveDown()
{
	if (m_selectedItem < ANSWERS)		//move down in menu
	{
		m_text[m_selectedItem].setFillColor(sf::Color::White);
		m_selectedItem++;
		m_text[m_selectedItem].setFillColor(sf::Color::Red);
	}
}

void Question::moveUp()
{
	if (m_selectedItem > 1)		//move up in menu
	{
		m_text[m_selectedItem].setFillColor(sf::Color::White);
		m_selectedItem--;
		m_text[m_selectedItem].setFillColor(sf::Color::Red);
	}
}