//
// Created by kshou on 2022/1/9.
//

#include "TextBox.h"
using namespace sf;

TextBox::TextBox() = default;


TextBox::TextBox(bool isSelected)
    : isSelected(isSelected)
{
    // load the font file and set the properties of text labels and inputBox text
    if (!font.loadFromFile("../assets/JetBrainsMono-Bold.ttf"))
        throw std::runtime_error("Could not load font!");
    label.setFont(font);
    label.setCharacterSize(TEXTBOX_LABEL_FONTSIZE);
    label.setString("Array size = ");
    label.setPosition(Vector2f(TEXTBOX_LABEL_POSITION_X, TEXTBOX_LABEL_POSITION_Y));
    label.setFillColor(TEXTBOX_TEXT_COLOR);

    inputBox.setFont(font);
    inputBox.setCharacterSize(TEXTBOX_LABEL_FONTSIZE - 2);
    inputBox.setPosition(Vector2f(TEXTBOX_INPUT_POSITION_X, TEXTBOX_INPUT_POSITION_Y));
    inputBox.setFillColor(TEXTBOX_TEXT_COLOR);
    if (isSelected)
        inputBox.setString('_');
    else
        inputBox.setString("");     // set to nothing by default when not selected

    boxOutline.setPosition(Vector2f(TEXTBOX_INPUT_POSITION_X - TEXTBOX_LABEL_FONTSIZE, TEXTBOX_INPUT_POSITION_Y));
    boxOutline.setSize(Vector2f(TEXTBOX_INPUT_WIDTH, TEXTBOX_INPUT_HEIGHT));
    boxOutline.setFillColor(BACKGROUND_COLOR);
    boxOutline.setOutlineThickness(2);
    boxOutline.setOutlineColor(TEXTBOX_TEXT_COLOR);
}

void TextBox::input(int charTyped)
{
    // read the key inputted into the text
    if (charTyped != DELETE_KEY && charTyped != ENTER_KEY && validInput(charTyped)){
        text += static_cast<char>(charTyped);           // put the char typed into the text
    }

    // when the input key is DELETE_KEY
    else if (charTyped == DELETE_KEY){
        if (text.length() > 0)  // prevent deleting char from empty string
            // removing last char from the string
            text.pop_back();
    }

    // update the inputBox
    inputBox.setString(text + '_');
}

bool TextBox::validInput(const int& charTyped)
{
    // if the char going to input is not a digit(i.e. not in range 0 to 9)
    if (charTyped < '0' || charTyped > '9')
        return false;

    return true;
}

void TextBox::draw(sf::RenderWindow& window)
{
    window.draw(label);
    // remember to draw the boxOutline before drawing the text (overlapping problem)
    window.draw(boxOutline);
    window.draw(inputBox);
}

void TextBox::setSelected(bool selected)
{
    // do not show the '_' at the end when the textBox is not selected
    if (!isSelected && selected)
        inputBox.setString(text + '_');
    isSelected = selected;
}

bool TextBox::getSelected() const
{
    return isSelected;
}

bool TextBox::isHovering(RenderWindow& window) const
{
    if (Mouse::getPosition(window).x >= boxOutline.getPosition().x && Mouse::getPosition(window).x <= (boxOutline.getPosition().x + boxOutline.getSize().x)
        && Mouse::getPosition(window).y >= boxOutline.getPosition().y &&
        Mouse::getPosition(window).y <= (boxOutline.getPosition().y + boxOutline.getSize().y))
        return true;

    return false;
}
