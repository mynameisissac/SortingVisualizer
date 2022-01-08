//
// Created by kshou on 2021/12/25.
//

#ifndef SORTINGVISUALIZER_UI_COMMON_H
#define SORTINGVISUALIZER_UI_COMMON_H
#include <SFML/Graphics.hpp>

// default size of array to be sorted
static int SizeOfArray = 1000;            // <-- change this number to test with different sizes of array

// ui-related common constants and static variables
// background color
static sf::Color BACKGROUND_COLOR(sf::Color::White);

// the dimension of the window
const int WINDOW_WIDTH = 1650;
const int WINDOW_HEIGHT = 750;

// The information of starting menu part
// dimension of each selection button
const float SELECTION_BUTTON_WIDTH = (float) WINDOW_WIDTH / 5.06f;
const float SELECTION_BUTTON_HEIGHT = (float) WINDOW_HEIGHT / 9.18f;
// position of the top-left corner of selection menu(i.e. first selection button)
const float MENU_SELECTION_POSITION_X = (float) WINDOW_WIDTH * 2 / 5;
const float MENU_SELECTION_POSITION_Y = SELECTION_BUTTON_HEIGHT * 2.5f;

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
const float BUTTON_HEIGHT = BUTTON_WIDTH;               // make it a square button
// color of buttons
static sf::Color BUTTON_COLOR(189,189,189);

// position of the text label (stopWatch information)
const sf::Vector2f TEXTLABEL1_POSITION(DISPLAY_WIDTH + 5.0f, DISPLAY_HEIGHT * 3/4);
const sf::Vector2f TEXTLABEL2_POSITION(DISPLAY_WIDTH + 5.0f + 10.0f, DISPLAY_HEIGHT * 3/4 + 20.0f);
static sf::Color textColor(33, 33, 33);

// height scale for rectangles bars (representation of the array)
static float HEIGHT_SCALE = float(WINDOW_HEIGHT) / SizeOfArray;
// color of rectangles bars
static sf::Color arrayColor(66,66,66);         // grey
static sf::Color arrayHighlightColor(255, 193, 7);       // yellow

// control the small suspend time between each iteration/comparison
const int DELAY_TIME = 0;       // unit: milliseconds

#endif //SORTINGVISUALIZER_UI_COMMON_H
