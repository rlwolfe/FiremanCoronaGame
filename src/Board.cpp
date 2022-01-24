#include "Board.h"
#include "CollisionObjects.h"//check
#include "Question.h"



template <typename FwdIt, typename FzdIt, typename Fn>
void for_each_pair(FwdIt begin1, FwdIt end1, FzdIt begin2, FzdIt end2, Fn fn)
{//template function checking each moving object hit coliison all other object(movings, statics)
	for (; begin1 != end1; ++begin1) {
		auto it = begin1;
		for (auto second1 = ++it; second1 != end1; ++second1)
			fn(*begin1, *second1);
		for (auto second2 = begin2; second2 != end2; ++second2)
			fn(*begin1, *second2);
	} 		 
}

bool collide(GameObject& a, GameObject& b)
{
	return a.getSprite().getGlobalBounds().intersects(b.getSprite().getGlobalBounds());
}


bool Board::setWeapon()
{
	return m_player->updateWeapon(SingleLoatData::getInstance()->get_texture(PLAYER_TEXTURE), SingleLoatData::getInstance()->get_texture(PLAYER2_TEXTURE));
}

void Board::readStageFromFile(std::ifstream& gameFile , bool& game)
{//read current level
	m_boardRepresentation.clear();
	std::string currentLine;
	std::getline(gameFile, currentLine);
	if (currentLine == "ENDGAME")
		game = true;
	while (currentLine != "ENDLEVEL" && currentLine != "ENDGAME")
	{
		std::vector < char >  t;
		for (int k = 0; k < currentLine.size(); k++)
		{	
			t.push_back(currentLine[k]);
		}
		m_boardRepresentation.push_back(t);
		std::getline(gameFile, currentLine);
	}
}

void Board::readObjectsFromFile()
{//set level objects
	SingleLoatData* s = s->getInstance();
	Question::newLevel();
	sf::Vector2f pos(0, 0);
	for (size_t i = 0; i < m_boardRepresentation.size(); i++)	//build the SFML representation from the board representation
	{
		for (size_t j = 0; j < m_boardRepresentation[i].size(); j++)//creating all objects---------------
		{
			auto k = float(i);//for warnings
			auto h = float(j);//for warnings
			sf::Vector2f objectIndex(k, h);
			char Symbol = m_boardRepresentation[i][j];
			switch (Symbol)
			{
			case PLAYER:
				m_player = std::make_shared<Player>(objectIndex, s->get_texture(PLAYER_TEXTURE));
				m_movingObjects.emplace_back(m_player);
				break;
			case FIRE:
				m_staticObjects.emplace_back(std::make_unique<Fire>(objectIndex, s->get_texture(FIRE_TEXTURE)));
				break;
			case HYDRANT:
				m_staticObjects.emplace_back(std::make_unique<Hydrant>(objectIndex, s->get_texture(HYDRANT_TEXTURE)));
				break;			
			case CORONA:
				m_movingObjects.emplace_back(std::make_unique<Corona>(objectIndex, s->get_texture(CORONA_TEXTURE)));
				break;
			case WALL:
				m_staticObjects.emplace_back(std::make_unique<Wall>(objectIndex, s->get_texture(WALL_TEXTURE)));
				break;
			case FIRENEMY:
				m_FireEnemys.emplace_back(std::make_unique<FireEnemy>(objectIndex, s->get_texture(FIRENEMY_TEXTURE)));
				m_movingObjects.emplace_back(m_FireEnemys.back());
				break;
			case FIRESTATION:
				m_staticObjects.emplace_back(std::make_unique<FireStation>(objectIndex, s->get_texture(FIRESTATION_TEXTURE)));
				break;
			case WOODWALL:
				m_staticObjects.emplace_back(std::make_unique<WoodWall>(objectIndex, s->get_texture(WOODWALL_TEXTURE)));
				break;
			}
		}
	}
}


void Board::clear()
{//clear objects from the board  
	m_staticObjects.clear();
	m_movingObjects.clear();
	m_FireEnemys.clear();
}

std::list<std::shared_ptr <FireEnemy>>&  Board::getFireEnemys()
{
	return m_FireEnemys;
}

void Board::buildBoard(sf::RenderWindow& window)
{
	m_backGroundRec.setSize(sf::Vector2f(SingleLoatData::getInstance()->get_texture(GAMEBACK_TEXTURE).getSize().x, WINDOW_HEIGHT));
	m_backGroundRec.setTexture(&SingleLoatData::getInstance()->get_texture(GAMEBACK_TEXTURE));
	m_backGroundRec.setPosition(0, 0);
}


void Board::draw(sf::RenderWindow& window, sf::Time deltaTime)
{//draw all board objects
	window.draw(m_backGroundRec);

	m_player->setSpriteSheet(deltaTime);

	for (auto& staticobject : m_staticObjects)
	{
		staticobject->setSpriteSheet(deltaTime);
		staticobject->draw(window);
	}

	for (auto& movingObjects : m_movingObjects)	
	{
		movingObjects->draw(window);
	}
	
}

void Board::check_collision()
{//check collision of board objects
	for_each_pair(m_movingObjects.begin(), m_movingObjects.end(), m_staticObjects.begin(), m_staticObjects.end(), [](auto& a, auto& b) {
		if (collide(*a, *b))
			processCollision(*a, *b);
		});
}

std::shared_ptr <Player>& Board::getPlayer()
{
	return m_player;
}

std::list<std::unique_ptr <StaticObject>>& Board::getStatics()
{
	return m_staticObjects;
}

void Board::move(sf::Time deltaTime)
{// move all moving objects of the game
	for (auto& movingObjects : m_movingObjects)
	{
		movingObjects->changeDirection(m_player->getPos());
		movingObjects->move(movingObjects->getDirection(),deltaTime);
	}
}

void Board::shoot()
{//add shoots to the game
	if (m_player->shoot()) {
		if(m_player->getWeapon() == weapon::water)
			m_movingObjects.emplace_back(std::make_shared<WaterShoot>(getPlayer()->getPos(), SingleLoatData::getInstance()->get_texture(WATER_TEXTURE), getPlayer()->get_last_dir()));
		else 
			m_movingObjects.emplace_back(std::make_shared<AlcogelShoot>(getPlayer()->getPos(), SingleLoatData::getInstance()->get_texture(ALCOGEL_TEXTURE), getPlayer()->get_last_dir()));
	}
}

void Board::shootFireenemy()
{
	for (auto& firenemy : m_FireEnemys) {
		if (firenemy->shootFire()) {
			m_movingObjects.emplace_back(std::make_shared<FireShoot>(firenemy->getPos(), SingleLoatData::getInstance()->get_texture(FIRESHOOT_TEXTURE), firenemy->getDirection()));
		}
	}
}

void Board::changeBackgroundLevel(int level)
{
	if (level % 2 == 1)
		m_backGroundRec.setTexture(&SingleLoatData::getInstance()->get_texture(GAMEBACK_TEXTURE));
	else
		m_backGroundRec.setTexture(&SingleLoatData::getInstance()->get_texture(CITYBACK_TEXTURE));
}

void Board::checkdelete()
{//delete object who set delete
	auto checkdelete = [](auto const& x) { return x->get_deleteMe(); };

	std::experimental::erase_if(m_movingObjects, checkdelete);

	std::experimental::erase_if(m_staticObjects, checkdelete);

	std::experimental::erase_if(m_FireEnemys, checkdelete);
}




