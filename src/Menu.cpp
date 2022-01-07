//
// Created by kshou on 2022/1/7.
//

#include "Menu.h"

Menu::Menu()
{

}

void Menu::draw(sf::RenderWindow& window)
{

}

// destructor for Button array
Menu::~Menu()
{
    for(auto & i : selectionList)
        delete i;
}
