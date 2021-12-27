//
// Created by kshou on 2021/12/27.
//

#ifndef SORTINGVISUALIZER_BUTTON_H
#define SORTINGVISUALIZER_BUTTON_H
#include <SFML/Graphics.hpp>

class Button {
    private:
        // representation of the Button on screen
        sf::RectangleShape display;
        // position of the top-left corner of the Button
        sf::Vector2f position;

    public:
        // constructor
        Button(const sf::Vector2f& size, const sf::Vector2f& position);

        void draw(sf::RenderWindow& window);
        // event handler of when clicking the button
        void onClick();     // TODO

};


#endif //SORTINGVISUALIZER_BUTTON_H
