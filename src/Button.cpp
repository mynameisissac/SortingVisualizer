//
// Created by kshou on 2021/12/27.
//

#include "Button.h"
#include "UI_common.h"
using namespace sf;

Button::Button(const sf::Vector2f& size, const sf::Vector2f& position)
    : display(size), position(position)
{
    display.setPosition(position);
    display.setFillColor(BUTTON_COLOR);

}

void Button::draw(RenderWindow& window)
{
    window.draw(display);
}

// event handler of when clicking the Button
void Button::onClick()
{}