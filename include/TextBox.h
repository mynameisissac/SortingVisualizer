//
// Created by kshou on 2022/1/9.
//

#ifndef SORTINGVISUALIZER_TEXTBOX_H
#define SORTINGVISUALIZER_TEXTBOX_H

#include "UI_common.h"
#include <sstream>

#define DELETE_KEY 8
#define ENTER_KEY 13


class TextBox {
    private:
        // the label of the inputBox (i.e. "Array size = ")
        sf::Text label;
        // where the user input shown on screen
        sf::Text inputBox;
        // font of both the label and inputBox's text
        sf::Font font;

        // a rectangle to outline the inputBox on screen
        sf::RectangleShape boxOutline;

        std::string text;
        // limit of length of text input
        int limit = 255;
        // user can only input to the textBox when it is selected
        bool isSelected = false;

    public:
        TextBox();
        explicit TextBox(bool isSelected);

        // check if the user mouse in the inputBox region
        bool isHovering(sf::RenderWindow& window) const;
        // accessor
        bool getSelected() const;
        // mutator
        void setSelected(bool selected);
        // check if the input key is a valid char to enter the textbox
        static bool validInput(const int& charTyped);
        void input(int charTyped);
        void draw(sf::RenderWindow& window);
};


#endif //SORTINGVISUALIZER_TEXTBOX_H
