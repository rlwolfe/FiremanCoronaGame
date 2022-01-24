#pragma once

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include "Const.h"

class SingleLoatData {
    static SingleLoatData* instance;
    std::vector<sf::Texture> m_tex;
    std::vector<sf::Font> m_fonts;

    // Private constructor so that no objects can be created.
    SingleLoatData() {
        loadTextures();
        loadFonts();
    }

public:
    static SingleLoatData* getInstance() {
        if (!instance)
            instance = new SingleLoatData;
        return instance;
    }
    void loadTextures();
    void loadFonts();
    sf::Texture& get_texture(int num) {
        return this->m_tex[num];
    }

    sf::Font& getFonts(int num) {
        return this->m_fonts[num];
    }
};


