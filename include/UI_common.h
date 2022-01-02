//
// Created by kshou on 2021/12/25.
//

#ifndef SORTINGVISUALIZER_UI_COMMON_H
#define SORTINGVISUALIZER_UI_COMMON_H
#include <SFML/Graphics.hpp>

static const int SizeOfArray = 900;            // <-- change this number to test with different size of arrays

// ui-related common constants and static variables
// background color
static sf::Color BACKGROUND_COLOR(sf::Color::White);

// the dimension of the window
const int WINDOW_WIDTH = 1650;
const int WINDOW_HEIGHT = 750;

// the dimension of the region to display the sorting process
const float DISPLAY_WIDTH = 1500.0f;
const float DISPLAY_HEIGHT = (float)WINDOW_HEIGHT;

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
const float HEIGHT_SCALE = float(WINDOW_HEIGHT) / SizeOfArray;
// color of rectangles bars
static sf::Color arrayColor(66, 66, 66);         // grey
static sf::Color arrayHighlightColor(255, 193, 7);       // yellow

// control the small suspend time between each iteration/comparison
const int DELAY_TIME = 0;       // unit: milliseconds

#endif //SORTINGVISUALIZER_UI_COMMON_H
