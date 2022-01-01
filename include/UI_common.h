//
// Created by kshou on 2021/12/25.
//

#ifndef SORTINGVISUALIZER_UI_COMMON_H
#define SORTINGVISUALIZER_UI_COMMON_H
#include <SFML/Graphics.hpp>

// ui-related common constants and static variables
// background color
static sf::Color BACKGROUND_COLOR(sf::Color::White);

// the dimension of the window
const int WINDOW_WIDTH = 1300;
const int WINDOW_HEIGHT = 512;

// the dimension of the region to display the sorting process
const float DISPLAY_WIDTH = 1100.0f;
const float DISPLAY_HEIGHT = 512.0f;

// dimension of the sidebar
const float SIDEBAR_WIDTH = float(WINDOW_WIDTH) - DISPLAY_WIDTH;
const float SIDEBAR_HEIGHT = float(WINDOW_HEIGHT);
// color of sidebar
static sf::Color SIDEBAR_COLOR(224,224,224);        // light grey

//dimension of buttons
const float BUTTON_WIDTH = int(SIDEBAR_WIDTH * 3/5);
const float BUTTON_HEIGHT = 60.0f;
// color of buttons
static sf::Color BUTTON_COLOR(189,189,189);

// height scale for rectangles bars (representation of the array)
const float HEIGHT_SCALE = 0.42f;
// color of rectangles bars
static sf::Color ARRAY_COLOR(66,66,66);         // grey

const int DELAY_TIME = 15;       // unit: milliseconds

#endif //SORTINGVISUALIZER_UI_COMMON_H
