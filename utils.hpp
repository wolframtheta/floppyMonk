#ifndef UTILS_HPP
#define UTILS_HPP

#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>
#include <list>
#include <queue>
#include <set>
#include <cmath>
#include <utility>
#include <sstream>

#include <SFML/System.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>

#include "menu.hpp"
#include "monjo.hpp"
#include "nota.hpp"
#include "listNota.hpp"
#include "game.hpp"


#define W_WIDTH 1920
#define W_HEIGHT 1080


#define APP_NAME "Floppy Monk"



static const sf::Vector2f posRectangle = sf::Vector2f(1250, 760);

static const char* file_monjo = "./resources/finish_monk_green.png";
static const char* file_bg = "./resources/Img_T_Game.jpg";
static const char* file_tile="./resources/sprite.png";


#endif // UTILS_HPP
