//
// Created by kshou on 2021/12/25.
//

#ifndef SORTINGVISUALIZER_UI_COMMON_H
#define SORTINGVISUALIZER_UI_COMMON_H

// ui-related common constants

// the dimension of the window
const int WINDOW_WIDTH = 700;
const int WINDOW_HEIGHT = 512;

// the dimension of the region to display the sorting process
const int DISPLAY_WIDTH = 512;
const int DISPLAY_HEIGHT = 512;

// dimension of the sidebar
const int SIDEBAR_WIDTH = WINDOW_WIDTH - DISPLAY_WIDTH;
const int SIDEBAR_HEIGHT = WINDOW_HEIGHT - DISPLAY_HEIGHT;

// height scale for rectangles bar (representation of the array)
const int HEIGHT_SCALE = 10;

const float DELAY_TIME = 0.5;       // unit: seconds

#endif //SORTINGVISUALIZER_UI_COMMON_H
