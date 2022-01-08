//
// Created by kshou on 2022/1/7.
//

#ifndef SORTINGVISUALIZER_MENU_H
#define SORTINGVISUALIZER_MENU_H

#include "SelectionButton.h"

// forward declaration of Engine
class Engine;

// note that Menu is a friend class of Engine
class Menu {
    private:
        // Selecting sorting algorithm part
        // total number of items for selection
        static const int TOTAL = 5;
        // store the currently selected item index
        int selectedItemIndex;      // from 0 to TOTAL - 1

        // an array of pointers to Button that each button represent a choice
        // the menu owns all the selection buttons
        Button* selectionList[TOTAL];

        // pointer of the engine the possessed this menu
        Engine* engine;

    public:
        explicit Menu(Engine* engine);
        ~Menu();

        void handleInput();
        void run();

        void draw();

};


#endif //SORTINGVISUALIZER_MENU_H
