//
// Created by kshou on 2021/12/27.
//

#ifndef SORTINGVISUALIZER_SIDEBAR_H
#define SORTINGVISUALIZER_SIDEBAR_H
#include "Button/PauseButton.h"
#include "UI_common.h"

class SideBar {
    private:
        // x,y coordinates of the top-left corner of the sidebar
        sf::Vector2f position;

        sf::Vector2f dimension;
        sf::RectangleShape display;
        sf::Color backGroundColor;

        // Buttons (owned)
        Button* pauseButton;

        // Text labels
        sf::Font font;
        sf::Text* timeLabel;
        sf::Text* stopWatch;

    public:
        SideBar(const sf::Vector2f& position, const sf::Vector2f& size, const sf::Color& color, Button* pauseButton);
        ~SideBar();

        void stopWatchUpdate(const std::string& timeToDisplay) const;

        // draw the sideBar and all buttons on it
        void draw(sf::RenderWindow& window) const;

        //accessors
        Button& getPauseButton() const;
        sf::Vector2f getPosition() const;
        sf::Vector2f getDimension() const;
        sf::RectangleShape getDisplay() const;
        sf::Color getColor() const;

};


#endif //SORTINGVISUALIZER_SIDEBAR_H
