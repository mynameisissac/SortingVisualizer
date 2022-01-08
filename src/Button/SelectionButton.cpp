//
// Created by kshou on 2022/1/8.
//

#include "Button/SelectionButton.h"

SelectionButton::SelectionButton(const sf::Vector2f& size, const sf::Vector2f& position, int choiceIndex)
    : Button(size, position), choiceIndex(choiceIndex)
{
    // load the normal texture and set it to the button
    std::string textureFilename = "../assets/menu/menu_selection_" + std::to_string(choiceIndex) + "_normal.png";
    if (!normalTexture.loadFromFile(textureFilename))
        throw std::runtime_error("cannot load texture of menu selection button!");

    // load the hovering texture
    textureFilename = "../assets/menu/menu_selection_" + std::to_string(choiceIndex) + "_hovering.png";
    if (!hoveringTexture.loadFromFile(textureFilename))
        throw std::runtime_error("cannot load texture of menu selection button!");

    // load the selected texture
    textureFilename = "../assets/menu/menu_selection_" + std::to_string(choiceIndex) + "_selected.png";
    if (!selectedTexture.loadFromFile(textureFilename))
        throw std::runtime_error("cannot load texture of menu selection button!");

    setTexture(&normalTexture);
    display.setFillColor(sf::Color::White);
}

void SelectionButton::onClick()
{
    // change the texture
    if (beingSelected)
        setTexture(&normalTexture);
    else
        setTexture(&selectedTexture);

    // reverse the flag of being selected
    beingSelected = !beingSelected;
}

void SelectionButton::onHovering()
{
    if (!beingSelected)
        setTexture(&hoveringTexture);
}

void SelectionButton::resetTexture()
{
    if (!beingSelected && display.getTexture() == &hoveringTexture)
        setTexture(&normalTexture);
}
