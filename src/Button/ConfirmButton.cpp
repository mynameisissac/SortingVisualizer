//
// Created by kshou on 2022/1/8.
//

#include "Button/ConfirmButton.h"

ConfirmButton::ConfirmButton(const sf::Vector2f& size, const sf::Vector2f& position)
    : Button(size, position)
{
    // load and set textures
    std::string textureFilename = "../assets/menu/menu_confirmation_normal.png";
    if (!normalTexture.loadFromFile(textureFilename))
        throw std::runtime_error("cannot load texture of menu confirmation button!");

    // load the hovering texture
    textureFilename = "../assets/menu/menu_confirmation_hovering.png";
    if (!hoveringTexture.loadFromFile(textureFilename))
        throw std::runtime_error("cannot load texture of menu confirmation button!");

    display.setTexture(&normalTexture);
    display.setFillColor(sf::Color::White);
}

void ConfirmButton::onClick()
{
    confirmed = true;
}

void ConfirmButton::onHovering()
{
    setTexture(&hoveringTexture);
}

bool ConfirmButton::isConfirmed() const
{
    return confirmed;
}

void ConfirmButton::resetTexture()
{
    if (display.getTexture() == &hoveringTexture)
        setTexture(&normalTexture);
}

void ConfirmButton::reset()
{
    confirmed = false;
}
