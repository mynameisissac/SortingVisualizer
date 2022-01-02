//
// Created by kshou on 2022/1/1.
//

#include "BackGroundUI.h"


BackGroundUI::BackGroundUI(sf::RenderWindow& window, const SideBar* sideBar)
    : window(window), sideBar(sideBar), backGroundColor(BACKGROUND_COLOR)
{}


sf::RenderWindow& BackGroundUI::getWindow() const
{
    return window;
}

// two-buffering drawing
void BackGroundUI::draw(const std::string& stopWatch)
{
    // update the text to shown on stopWatch first
    sideBar->stopWatchUpdate(stopWatch);
    // draw all the ui elements here
    sideBar->draw(window);
    window.display();       // show(render) the drawn objects on screen

    window.clear(backGroundColor);      // clear everything for next drawing
}