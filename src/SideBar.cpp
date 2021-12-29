//
// Created by kshou on 2021/12/27.
//

#include "SideBar.h"
using namespace sf;

SideBar::SideBar(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& color, Button* pauseButton)
    : dimension(size), position(position), display(size), backGroundColor(color), pauseButton(pauseButton)
{
    display.setPosition(position);
    display.setFillColor(backGroundColor);
}

SideBar::~SideBar()
{
    delete pauseButton;
}

void SideBar::draw(RenderWindow& window) const
{
    window.draw(display);
    pauseButton->draw(window);
}

// return the pause button object by reference
Button& SideBar::getPauseButton() const
{
    return *pauseButton;
}

// return the position of the top-left corner of the sidebar
Vector2f SideBar::getPosition() const
{
    return position;
}

// return the dimension(width and height) of the sidebar
Vector2f SideBar::getDimension() const
{
    return dimension;
}

// return the rectangleShape that display the sidebar
RectangleShape SideBar::getDisplay() const
{
    return display;
}

// return the background color of the sidebar
Color SideBar::getColor() const
{
    return backGroundColor;
}