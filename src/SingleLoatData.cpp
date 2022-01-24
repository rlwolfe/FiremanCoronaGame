#include "SingleLoatData.h"

void SingleLoatData::loadTextures()
{// load all textures for the gameand if its cant load throw error with name of the texture wasnt load
	
	for (int i = 0; i < NUM_OF_TEXTURES; i++)
	{
		sf::Texture temp;
		m_tex.push_back(temp);
		switch (i)
		{
		case PLAYER_TEXTURE:
			if (!m_tex[i].loadFromFile("mickey.png"))
				throw std::runtime_error("\nException thrown:\nCant open texture mickey.png\n");
			break;
		case FIRE_TEXTURE:
			if (!m_tex[i].loadFromFile("dynamicFire.png"))
				throw std::runtime_error("\nException thrown:\nCant open texture dynamicFire.png\n");
			break;
		case HYDRANT_TEXTURE:
			if (!m_tex[i].loadFromFile("hydrant.png"))
				throw std::runtime_error("\nException thrown:\nCant open texture hydrant.png\n");
			break;
		case CORONA_TEXTURE:
			if (!m_tex[i].loadFromFile("corona.png"))
				throw std::runtime_error("\nException thrown:\nCant open texture corona.png\n");
			break;
		case WATER_TEXTURE:
			if (!m_tex[i].loadFromFile("waterShoot.png"))
				throw std::runtime_error("\nException thrown:\nCant open texture waterShoot.png\n");
			break;
		case WALL_TEXTURE:
			if (!m_tex[i].loadFromFile("Red_Brick.png"))
				throw std::runtime_error("\nException thrown:\nCant open texture Red_Brick.png\n");
			break;
		case FIRENEMY_TEXTURE:
			if (!m_tex[i].loadFromFile("fireEnemy.png"))
				throw std::runtime_error("\nException thrown:\nCant open texture fireEnemy.png\n");
			break;
		case FIRESHOOT_TEXTURE:
			if (!m_tex[i].loadFromFile("fireshoot.png"))
				throw std::runtime_error("\nException thrown:\nCant open texture fireshoot.png\n");
			break;
		case FIRESTATION_TEXTURE:
			if (!m_tex[i].loadFromFile("fireStation.png"))
				throw std::runtime_error("\nException thrown:\nCant open texture fireStation.png\n");
			break;
		case PLAYER2_TEXTURE:
			if (!m_tex[i].loadFromFile("mickeyAxe.png"))
				throw std::runtime_error("\nException thrown:\nCant open texture mickeyAxe.png\n");
			break;
		case WOODWALL_TEXTURE:
			if (!m_tex[i].loadFromFile("wood_wall.png"))
				throw std::runtime_error("\nException thrown:\nCant open texture wood_wall.png\n");
			break;
		case ALCOGEL_TEXTURE:
			if (!m_tex[i].loadFromFile("alcogelShoot.png"))
				throw std::runtime_error("\nException thrown:\nCant open texture alcogelShoot.png\n");
			break;
		case GAMEBACK_TEXTURE:
			if (!m_tex[i].loadFromFile("GameBack.jpg"))
				throw std::runtime_error("\nException thrown:\nCant open texture GameBack.jpg\n");
			break;
		case CITYBACK_TEXTURE:
			if (!m_tex[i].loadFromFile("cityBack.jpg"))
				throw std::runtime_error("\nException thrown:\nCant open texture cityBack.jpg\n");
			break;
		case SOUND_TEXTURE:
			if (!m_tex[i].loadFromFile("soundOn.png"))
				throw std::runtime_error("\nException thrown:\nCant open texture soundOn.png\n");
			break;
		case KEY_TEXTURE:
			if (!m_tex[i].loadFromFile("key.png"))
				throw std::runtime_error("\nException thrown:\nCant open texture key.png\n");
			break;
		case PLAY_TEXTURE:
			if (!m_tex[i].loadFromFile("play.png"))
				throw std::runtime_error("\nException thrown:\nCant open texture play.png\n");
			break;
		case PAUSE_TEXTURE:
			if (!m_tex[i].loadFromFile("pause.png"))
				throw std::runtime_error("\nException thrown:\nCant open texture pause.png\n");
			break;
		case SOUNDOFF_TEXTURE:
			if (!m_tex[i].loadFromFile("soundOff.png"))
				throw std::runtime_error("\nException thrown:\nCant open texture soundOff.png\n");
			break;
		case ALCOGELT_TEXTURE:
			if (!m_tex[i].loadFromFile("alcogel.png"))
				throw std::runtime_error("\nException thrown:\nCant open texture alcogel.png\n");
			break;
		case WATERT_TEXTURE:
			if (!m_tex[i].loadFromFile("water.png"))
				throw std::runtime_error("\nException thrown:\nCant open texture water.png\n");
			break;
		case AXET_TEXTURE:
			if (!m_tex[i].loadFromFile("axe.png"))
				throw std::runtime_error("\nException thrown:\nCant open texture axe.png\n");
			break;
		case FIREM_TEXTURE:
			if (!m_tex[i].loadFromFile("Fire.jpg"))
				throw std::runtime_error("\nException thrown:\nCant open texture Fire.jpg\n");
			break;
		case FIREHELPM_TEXTURE:
			if (!m_tex[i].loadFromFile("FireHelp.jpg"))
				throw std::runtime_error("\nException thrown:\nCant open texture FireHelp.jpg\n");
			break;
		case GOCOVER_TEXTURE:
			if (!m_tex[i].loadFromFile("gameovercover.jpg"))
				throw std::runtime_error("\nException thrown:\nCant open texture gameovercover.jpg\n");
			break;
		case SCROLL_TEXTURE:
			if (!m_tex[i].loadFromFile("scroll.png"))
				throw std::runtime_error("\nException thrown:\nCant open texture scroll.png\n");
			break;
		case LIGHT_TEXTURE0:
			if (!m_tex[i].loadFromFile("toolbarLights0.png"))
				throw std::runtime_error("\nException thrown:\nCant open texture toolbarLights0.png\n");
			break;
		case LIGHT_TEXTURE1:
			if (!m_tex[i].loadFromFile("toolbarLights1.png"))
				throw std::runtime_error("\nException thrown:\nCant open texture toolbarLights1.png\n");
			break;
		case LIGHT_TEXTURE2:
			if (!m_tex[i].loadFromFile("toolbarLights2.png"))
				throw std::runtime_error("\nException thrown:\nCant open texture toolbarLights2.png\n");
			break;
		case LIGHT_TEXTURE3:
			if (!m_tex[i].loadFromFile("toolbarLights3.png"))
				throw std::runtime_error("\nException thrown:\nCant open texture toolbarLights3.png\n");
			break;
		case LIGHT_TEXTURE4:
			if (!m_tex[i].loadFromFile("toolbarLights4.png"))
				throw std::runtime_error("\nException thrown:\nCant open texture toolbarLights4.png\n");
			break;
		case LIGHT_TEXTURE5:
			if (!m_tex[i].loadFromFile("toolbarLights5.png"))
				throw std::runtime_error("\nException thrown:\nCant open texture toolbarLights5.png\n");
			break;
		}
	}
}

void SingleLoatData::loadFonts()
{// load all fonts for the game and if its cant load throw error with name of the fornt eho cant load
	for (auto i = 0; i < FONT_SIZE; i++)
	{
		sf::Font temp;
		m_fonts.push_back(temp);
		switch (i)
		{
		case TOOLBAR_FONT:
			if (!m_fonts[i].loadFromFile("f_toolbar.ttf"))
				throw std::runtime_error("\nException thrown:\nCant open texture f_toolbar.ttf\n");
			break;
		case MENU_FONT:
			if (!m_fonts[i].loadFromFile("f_menu.TTF"))
				throw std::runtime_error("\nException thrown:\nCant open texture f_menu.TTF\n");
			break;
		case RIDDLE_FONT:
			if (!m_fonts[i].loadFromFile("f_riddle.ttf"))
				throw std::runtime_error("\nException thrown:\nCant open texture f_riddle.ttf\n");
			break;
		case ANSWER_FONT:
			if (!m_fonts[i].loadFromFile("f_answers.ttf"))
				throw std::runtime_error("\nException thrown:\nCant open texture f_answers.ttf\n");
			break;
		}
	}
}
