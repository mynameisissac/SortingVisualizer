//
// Created by kshou on 2021/12/27.
//

#include "Button/Button.h"
#include "UI_common.h"
using namespace sf;

Button::Button(const sf::Vector2f& size, const sf::Vector2f& position)
    : display(size), position(position)
{
    display.setPosition(position);
    display.setFillColor(BUTTON_COLOR);

}

/**
 * check if the user's mouse is on the button region
 * ,note this implementation for square button only
 * @param window the window that the button is on
 * @return true if user's mouse is hovering on the button, otherwise false
 */
bool Button::isHovering(RenderWindow& window) const
{
    if (Mouse::getPosition(window).x >= position.x && Mouse::getPosition(window).x <= (position.x + display.getSize().x)
        && Mouse::getPosition(window).y >= position.y && Mouse::getPosition(window).y <= (position.y + display.getSize().y))
        return true;

    return false;
}

void Button::setTexture(sf::Texture* texture)
{
    display.setTexture(texture);
}

void Button::draw(RenderWindow& window)
{
    window.draw(display);
}

sf::RectangleShape Button::getDisplay() const
{
    return display;
}
