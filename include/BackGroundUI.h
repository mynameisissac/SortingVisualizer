//
// Created by kshou on 2022/1/1.
//

#ifndef SORTINGVISUALIZER_BACKGROUNDUI_H
#define SORTINGVISUALIZER_BACKGROUNDUI_H

#include "SideBar.h"
#include "UI_common.h"

// store everything that need to be drawn on the UI
class BackGroundUI {
    private:
        // the window to draw the ui
        sf::RenderWindow& window;

        const sf::Color backGroundColor;

        // add the UI elements here
        const SideBar* sideBar;

    public:
        explicit BackGroundUI(sf::RenderWindow& window, const SideBar* sideBar);     // constructor
        sf::RenderWindow& getWindow() const;

        void draw(const std::string& stopWatch);

};


#endif //SORTINGVISUALIZER_BACKGROUNDUI_H
