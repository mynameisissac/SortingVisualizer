//
// Created by kshou on 2022/1/7.
//

#ifndef SORTINGVISUALIZER_MENU_H
#define SORTINGVISUALIZER_MENU_H

#include "Button/SelectionButton.h"
#include "Button/ConfirmButton.h"
#include "TextBox.h"

// forward declaration of Engine
class Engine;

// note that Menu is a friend class of Engine
class Menu {
    private:
        // Selecting sorting algorithm part
        // total number of items for selection
        static const int TOTAL = 5;
        // store the currently selected item index
        // from 0 to (TOTAL - 1), -1 means not yet selected
        int selectedItemIndex;

        // an array of pointers to Button that each button represent a choice
        // the menu owns all the selection buttons
        SelectionButton* selectionList[TOTAL];

        // textBox for inputting array size by user
        TextBox* textBox;

        // confirm button
        ConfirmButton* confirmButton;
        // pointer of the engine the possessed this menu
        Engine* engine;

    public:
        explicit Menu(Engine* engine);
        ~Menu();

        void handleInput(bool& selected, bool& arraySizeValid);
        void run();

        void draw();

};


#endif //SORTINGVISUALIZER_MENU_H
