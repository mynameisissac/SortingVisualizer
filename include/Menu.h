//
// Created by kshou on 2022/1/7.
//

#ifndef SORTINGVISUALIZER_MENU_H
#define SORTINGVISUALIZER_MENU_H
#include "Button.h"

class Menu {
    private:
        // Selecting sorting algorithm part
        // total number of items for selection
        static const int TOTAL = 5;
        // store the currently selected item index
        int selectedItemIndex;

        // an array of pointers to Button that each button represent a choice
        // the menu owns all the selection buttons
        Button* selectionList[TOTAL];

    public:
        Menu();
        ~Menu();

        void draw(sf::RenderWindow& window);

};


#endif //SORTINGVISUALIZER_MENU_H
