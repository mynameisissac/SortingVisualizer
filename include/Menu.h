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
        const int TOTAL = 5;
        // store the currently selected item index
        int selectedItemIndex;

        // a pointer to an array of Buttons that each button represent a choice
        Button* selectionList;

    public:
        Menu();
        ~Menu();

        void draw(sf::RenderWindow& window);

};


#endif //SORTINGVISUALIZER_MENU_H
