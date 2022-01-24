#include "Controller.h"

Controller::Controller() : m_window(sf::VideoMode(WINDOW_WIDTH, WINDOW_HEIGHT, BPP), "Fireman Sam Saves the World", sf::Style::Fullscreen)
{//constructor build manu,board and toolbar
	m_menu = std::make_unique<Menu>(WINDOW_WIDTH, WINDOW_HEIGHT);
	m_board = std::make_unique<Board>();
	m_toolbar = std::make_unique<Toolbar>();
}

//intiailise by singlton textures and fronts
SingleLoatData* SingleLoatData::instance = 0;


void Controller::openClocks()
{//restart clocks						
	m_deltaTime = m_clock.restart();		//start the clocks
	m_deltaTime += m_deltaTime;
	m_startingGame = false;
}

void Controller::buildGame(std::ifstream& gameFile)
{//build board and view
	m_board->buildBoard(m_window);
	openFile(gameFile, "levels.txt");
	readBoard(gameFile);
	m_viewPlayer.reset(sf::FloatRect((float)0, (float)0, (float)m_window.getSize().x, (float)m_window.getSize().y));
	m_viewPlayer.setViewport(sf::FloatRect(0, 0, 1.0f, 1.0f));
}

void Controller::readBoard(std::ifstream& gameFile)
{//read level data
	m_board->readStageFromFile(gameFile, m_EndGame);
	m_board->readObjectsFromFile();
}

void Controller::nextLevel(std::ifstream& gameFile)
{//skip next level
	m_board->clear();
	int life = m_board->getPlayer()->getLife();
	int score = m_board->getPlayer()->getScore();
	readBoard(gameFile);
	m_board->getPlayer()->setLife(life);
	m_board->getPlayer()->setScore(score);
	Fire::resetLeft();
	m_level++;
	m_board->changeBackgroundLevel(m_level);
}

void Controller::GameOver(std::ifstream& gameFile)
{//game over and reset the game
	if (m_board->getPlayer()->getLife() <= 0 || m_EndGame == true) {
		m_level = 0;
		Question::resetQuestions();
		m_inMenu = true;
		m_board->clear();
		gameFile.seekg(0);//clear
		readBoard(gameFile);
		m_EndGame = false;
	}
}

void Controller::handleView(sf::Vector2f current_view)
{//set the view by the player pose
	if (m_board->getPlayer()->getPos().x + 10 > m_window.getSize().x / 2) {
		if (m_board->getPlayer()->getPos().x < WINDOW_LONG)
			current_view.x = m_board->getPlayer()->getPos().x + 10;
		else
			current_view.x = WINDOW_LONG;
	}
	else
		current_view.x = (float)m_window.getSize().x / 2;
	m_viewPlayer.setCenter(current_view);
	m_window.setView(m_viewPlayer);
}

void Controller::manageGame()
{//head loop runing the all game
	sf::Event event;

	std::ifstream gameFile;
	buildGame(gameFile);
	//VIEW----------
	sf::Vector2f current_view((float)m_window.getSize().x / 2, (float)m_window.getSize().y / 2);

	//---------music------
	if (!m_menuMusic.openFromFile("MenuMusic.ogg"))
		throw std::runtime_error("\nException thrown:\nCant open MenuMusic.ogg\n");;
	m_menuMusic.play();
	m_menuMusic.setLoop(true);

	m_question = std::make_unique<Question>(m_viewPlayer, m_level);

	//main game/event loops, runs until bool false
	while (m_window.isOpen())
	{

		while (m_window.pollEvent(event))
		{
			switch (event.type)
			{
			case sf::Event::Closed:
				m_window.close();		//close window event
				break;

			case sf::Event::MouseButtonReleased: {//update play/pause and sound on or off
				auto location = m_window.mapPixelToCoords({ event.mouseButton.x, event.mouseButton.y });
				m_play = m_toolbar->pressON(location, 2, PLAY_TEXTURE, PAUSE_TEXTURE, m_play);
				m_sound = m_toolbar->pressON(location, 0, SOUND_TEXTURE, SOUNDOFF_TEXTURE, m_sound);
				if (!m_sound) {
					m_paused = m_menuMusic.getPlayingOffset();
					m_menuMusic.pause();
				}
				else if (m_paused != sf::Time::Zero) {//update music
					m_menuMusic.setPlayingOffset(m_paused);
					m_paused = sf::Time::Zero;
					m_menuMusic.play();
				}
			}
											   break;

			case sf::Event::KeyPressed://close if press escape
				if (event.key.code == sf::Keyboard::Escape)
					m_window.close();
				break;

			case sf::Event::KeyReleased:
				if (m_inMenu)
					inMenuFunc(event);//run menu
				else if (m_inQuestion)
					inQuestionFunc(event);//run question
				break;
			}
		}
		if (!m_inMenu)//if the game is on 
		{
			if (m_board->getPlayer()->getWin())
				nextLevel(gameFile);

			GameOver(gameFile);

			m_deltaTime = m_clock.restart();

			if (m_play && !m_inQuestion) {//if not pause and not in question

				if (m_board->setWeapon())
					m_toolbar->changeWeapon(m_board->getPlayer()->getWeapon());

				m_board->move(m_deltaTime);

				updateShoots();

				handleView(current_view);

				m_board->check_collision();

				updateGame();
			}
		}
		//draw all details of the game
		presentGame();
	}
	gameFile.close();
}

void Controller::updateGame()
{//update score and question
	int numfire = Fire::getCount();
	if (m_fire < numfire) {
		m_fire = numfire;
		m_board->getPlayer()->add_score(PUTOUT_FIRE);
	}
	m_board->checkdelete();
	if (numfire > 2 && !Question::getKey()) {
		m_inQuestion = true;
		m_play = m_toolbar->pressON(sf::Vector2f(WINDOW_WIDTH - 2, 2), 2, PLAY_TEXTURE, PAUSE_TEXTURE, !m_inQuestion);
		m_fire = 0;
	}
}


void Controller::updateShoots()
{//update fireshoots, watershoots and alcogel shoots
	if (m_shootingClock.getElapsedTime().asSeconds() > 0.15) {
		m_board->shoot();
		m_shootingClock.restart();
	}
	m_board->shootFireenemy();
}

void Controller::presentGame()
{//draw game or menu or question
	if (m_inQuestion) {
		m_question->setPosition(m_viewPlayer);
		m_question->draw(m_window, 0);
	}
	else {
		if (m_inMenu) {
			drawMenu();
		}
		else {
			drawLevel();
		}
	}
	m_window.display();
}

void Controller::drawMenu()
{
	if (m_start || m_EndGame)
		m_menu->draw(m_window, MAIN_MENU_BACK);
	else
		m_menu->draw(m_window, GAMEOVER_BACKGROUND);
}

void Controller::drawLevel()
{//draw level 
	m_start = false;
	m_board->draw(m_window, m_deltaTime);
	m_toolbar->drawToolbar(m_window, m_viewPlayer, m_board->getPlayer()->getLife(),
		m_board->getPlayer()->get_water(), m_level, m_board->getPlayer()->getScore());
	if (Question::getKey())
		m_toolbar->setKeyOn();
	else
		m_toolbar->setKeyOff();
}

void Controller::inMenuFunc(sf::Event& event)
{//inside menu loop
	switch (event.key.code)
	{
	case sf::Keyboard::Up:
		m_menu->MoveUp();
		break;					//move up and down in menu
	case sf::Keyboard::Down:
		m_menu->MoveDown();
		break;

	case sf::Keyboard::Return:				//enter pressed
		switch (m_menu->getPressedItem())
		{
		case 0:
			m_inMenu = false;
			openClocks();
			break;
		case 1:
			if (m_helpClock.getElapsedTime().asSeconds() > 0.2) {
				inHelpMenu();
				m_helpClock.restart();
			}
			break;

		case 2:
			m_window.close();
			break;
		}
	}
}

void Controller::inQuestionFunc(sf::Event& event)
{
	switch (event.key.code)
	{
	case sf::Keyboard::Up:
		if (m_question->getPressedItem() != 1)
			m_question->moveUp();
		break;					//move up and down in menu
	case sf::Keyboard::Down:
		if (m_question->getPressedItem() != 4)
			m_question->moveDown();
		break;

	case sf::Keyboard::Return:				//enter pressed
		m_question->setSelected(m_question->getPressedItem());
		m_question->checkAnswer();
		while (m_question->getPressedItem() != 1)
			m_question->moveUp();
		Fire::resetCount();
		m_inQuestion = false;
		m_play = m_toolbar->pressON(sf::Vector2f(WINDOW_WIDTH - 2, 2), 2, PLAY_TEXTURE, PAUSE_TEXTURE, !m_inQuestion);
		break;
	}
}

void Controller::inHelpMenu()
{//run help inside menu
	m_help = true;
	while (m_help) {
		m_window.clear();
		m_menu->draw(m_window, HELP_BACKGROUND);
		m_window.display();
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Enter)) {
			m_help = false;
		}
	}
}

void Controller::openFile(std::ifstream& file, std::string fileName)
{
	file.open(fileName);					//function to open the game file
	if (!file.is_open())				//if the file dosent open throw exception
		throw std::runtime_error("\nException thrown:\nCan't open file\n");
}