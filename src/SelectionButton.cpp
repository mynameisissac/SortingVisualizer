//
// Created by kshou on 2022/1/8.
//

#include "SelectionButton.h"

SelectionButton::SelectionButton(const sf::Vector2f& size, const sf::Vector2f& position, int choiceIndex)
    : Button(size, position), choiceIndex(choiceIndex)
{
    // load the texture and set it to the button
    std::string textureFilename = "../assets/menuSelectionList/menu_selection_" + std::to_string(choiceIndex) + "_normal.png";
    if (!normalTexture.loadFromFile(textureFilename))
        throw std::runtime_error("cannot load texture of menu selection button!");

    setTexture(&normalTexture);
    display.setFillColor(sf::Color::White);
}

void SelectionButton::onClick()
{

}
