//
// Created by kshou on 2021/12/27.
//

#include "SideBar.h"
using namespace sf;

SideBar::SideBar(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& color, Button* pauseButton)
    : dimension(size), position(position), display(size), backGroundColor(color), pauseButton(pauseButton)
    , font(), timeLabel(new Text), stopWatch(new Text)
{
    display.setPosition(position);
    display.setFillColor(backGroundColor);

    // load the font file and set the properties of text labels
    if (!font.loadFromFile("../assets/JetBrainsMono-Bold.ttf"))
        throw std::runtime_error("Could not load font!");

    timeLabel->setFont(font);
    timeLabel->setCharacterSize(16);
    timeLabel->setPosition(TEXTLABEL1_POSITION);
    timeLabel->setString("Time elapsed: ");
    timeLabel->setFillColor(textColor);
    stopWatch->setFont(font);
    stopWatch->setCharacterSize(15);
    stopWatch->setPosition(TEXTLABEL2_POSITION);
    stopWatch->setString("0");
    stopWatch->setFillColor(textColor);
}

SideBar::~SideBar()
{
    delete pauseButton;
    delete stopWatch;
    delete timeLabel;
}

void SideBar::stopWatchUpdate(const std::string& timeToDisplay) const
{
    stopWatch->setString(timeToDisplay);
}

void SideBar::draw(RenderWindow& window) const
{
    window.draw(display);
    window.draw(*timeLabel);
    window.draw(*stopWatch);
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