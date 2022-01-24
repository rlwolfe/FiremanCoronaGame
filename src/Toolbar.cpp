#include "Toolbar.h"
#include "SingleLoatData.h"

Toolbar::Toolbar()
{
	for (int i = 0; i < NUM_TEX; i++) {
		m_tex[i].setFont(SingleLoatData::getInstance()->getFonts(TOOLBAR_FONT));
		m_tex[i].setFillColor(sf::Color::Black);
		m_tex[i].setCharacterSize(WINDOW_HEIGHT / 25);
	}
	loadIcons();
}

void  Toolbar::loadIcons()
{
	m_rec[0].setSize(sf::Vector2f(WINDOW_WIDTH / 20, WINDOW_HEIGHT / 20));
	m_rec[0].setTexture(&SingleLoatData::getInstance()->get_texture(SOUND_TEXTURE));

	m_rec[1].setSize(sf::Vector2f(WINDOW_WIDTH / 20 * 2, WINDOW_HEIGHT / 20));
	m_rec[1].setOutlineThickness(3);
	m_rec[1].setOutlineColor(sf::Color::Red);
	m_rec[1].setTexture(&SingleLoatData::getInstance()->get_texture(KEY_TEXTURE));

	m_rec[2].setSize(sf::Vector2f(WINDOW_WIDTH / 20, WINDOW_HEIGHT / 20));
	m_rec[2].setTexture(&SingleLoatData::getInstance()->get_texture(PLAY_TEXTURE));

	m_rec[3].setSize(sf::Vector2f(WINDOW_WIDTH / 20, WINDOW_HEIGHT / 20));
	m_rec[3].setTexture(&SingleLoatData::getInstance()->get_texture(WATERT_TEXTURE));

	m_rec[4].setSize(sf::Vector2f(WINDOW_WIDTH / 20 * 3, WINDOW_HEIGHT / 20));
	m_rec[4].setTexture(&SingleLoatData::getInstance()->get_texture(LIGHT_TEXTURE0));
}

void Toolbar::drawToolbar(sf::RenderWindow& window, sf::View& view, int life, int water, int level, int score)
{
	setStrings(life, water, level, score);
	addLights();
	setPositions(view);
	for (int i = 0; i < NUM_TEX; i++)
		window.draw(m_tex[i]);
	for (int i = 0; i < NUM_REC; i++)
		window.draw(m_rec[i]);
}

void Toolbar::setStrings(int life, int water, int level, int score)
{
	m_tex[0].setString("LIFE: " + std::to_string(life));
	m_tex[1].setString("WATER: " + std::to_string(water));
	m_tex[2].setString("LEVEL: " + std::to_string(level));
	m_tex[3].setString("SCORE: " + std::to_string(score));
}

void Toolbar::setPositions(sf::View& view)
{
	m_tex[0].setPosition(sf::Vector2f(view.sf::View::getCenter().x - (WINDOW_WIDTH / 2), 0));
	m_tex[1].setPosition(sf::Vector2f(m_tex[0].getPosition().x + 175, 0));
	m_tex[2].setPosition(sf::Vector2f(m_tex[1].getPosition().x + 275, 0));
	m_tex[3].setPosition(sf::Vector2f(m_tex[2].getPosition().x + 225, 0));
	m_rec[0].setPosition(sf::Vector2f(view.sf::View::getCenter().x + (WINDOW_WIDTH / 2) - m_rec[0].getSize().x, 0));
	m_rec[2].setPosition(sf::Vector2f(m_rec[0].getPosition().x - m_rec[2].getSize().x - 5, 0));
	m_rec[1].setPosition(sf::Vector2f(m_rec[2].getPosition().x - m_rec[1].getSize().x - 5, 0));
	m_rec[3].setPosition(sf::Vector2f(m_tex[3].getPosition().x + 250, 0));
	m_rec[4].setPosition(sf::Vector2f(m_rec[3].getPosition().x + 200, 0));
}

void Toolbar::setKeyOn()
{
	m_rec[1].setOutlineColor(sf::Color::Yellow);
}

void Toolbar::setKeyOff()
{
	m_rec[1].setOutlineColor(sf::Color::Red);
}


bool Toolbar::pressON(sf::Vector2f location, int rec, int tex1, int tex2, bool play)
{
	if (m_rec[rec].getGlobalBounds().contains(location)) {
		if (!play) {
			m_rec[rec].setTexture(&SingleLoatData::getInstance()->get_texture(tex1));
			return true;
		}
		else {
			m_rec[rec].setTexture(&SingleLoatData::getInstance()->get_texture(tex2));
			return false;
		}
	}
	return play;
}

void Toolbar::changeWeapon(weapon weap)
{//changes between possible shooting types and the axe
	if (weap == weapon::water)
		m_rec[3].setTexture(&SingleLoatData::getInstance()->get_texture(WATERT_TEXTURE));
	else if (weap == weapon::axe)
		m_rec[3].setTexture(&SingleLoatData::getInstance()->get_texture(AXET_TEXTURE));
	else
		m_rec[3].setTexture(&SingleLoatData::getInstance()->get_texture(ALCOGELT_TEXTURE));
}

void Toolbar::addLights()
{
	switch (Question::getAnswered()) {
	case 0:
		m_rec[4].setTexture(&SingleLoatData::getInstance()->get_texture(LIGHT_TEXTURE0));
		break;

	case 1:
		m_rec[4].setTexture(&SingleLoatData::getInstance()->get_texture(LIGHT_TEXTURE1));
		break;

	case 2:
		m_rec[4].setTexture(&SingleLoatData::getInstance()->get_texture(LIGHT_TEXTURE2));
		break;

	case 3:
		m_rec[4].setTexture(&SingleLoatData::getInstance()->get_texture(LIGHT_TEXTURE3));
		break;

	case 4:
		m_rec[4].setTexture(&SingleLoatData::getInstance()->get_texture(LIGHT_TEXTURE4));
		break;

	case 5:
		m_rec[4].setTexture(&SingleLoatData::getInstance()->get_texture(LIGHT_TEXTURE5));
	}
}

Toolbar::~Toolbar()
{}