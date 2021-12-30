//
// Created by kshou on 2021/12/25.
//

#ifndef SORTINGVISUALIZER_UI_COMMON_H
#define SORTINGVISUALIZER_UI_COMMON_H
#include <SFML/Graphics.hpp>

// ui-related common constants and static variables

// the dimension of the window
const int WINDOW_WIDTH = 700;
const int WINDOW_HEIGHT = 512;

// the dimension of the region to display the sorting process
const float DISPLAY_WIDTH = 512.0f;
const float DISPLAY_HEIGHT = 512.0f;

// dimension of the sidebar
const float SIDEBAR_WIDTH = float(WINDOW_WIDTH) - DISPLAY_WIDTH;
const float SIDEBAR_HEIGHT = float(WINDOW_HEIGHT);
// color of sidebar
static sf::Color SIDEBAR_COLOR(224,224,224);        // light grey

//dimension of buttons
const float BUTTON_WIDTH = 100.0f;
const float BUTTON_HEIGHT = 60.0f;
// color of buttons
static sf::Color BUTTON_COLOR(189,189,189);

// height scale for rectangles bars (representation of the array)
const int HEIGHT_SCALE = 10;
// color of rectangles bars
static sf::Color ARRAY_COLOR(66,66,66);         // grey

const float DELAY_TIME = 0.4;       // unit: seconds

#endif //SORTINGVISUALIZER_UI_COMMON_H
