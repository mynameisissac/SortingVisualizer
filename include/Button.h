//
// Created by kshou on 2021/12/27.
//

#ifndef SORTINGVISUALIZER_BUTTON_H
#define SORTINGVISUALIZER_BUTTON_H
#include <SFML/Graphics.hpp>


// a base class for all kinds of buttons
class Button {
    private:
        // representation of the Button on screen
        sf::RectangleShape display;
        // position of the top-left corner of the Button
        sf::Vector2f position;

    protected:
        // mutator
        void setTexture(sf::Texture* texture);

        // accessors
        sf::RectangleShape getDisplay() const;

    public:
        // constructor
        Button(const sf::Vector2f& size, const sf::Vector2f& position);
        virtual ~Button() = default;

        // check if the user's mouse is hovering on the button
        bool isHovering(sf::RenderWindow& window) const;

        void draw(sf::RenderWindow& window);

        // pure virtual function of handling onClick event
        virtual void onClick() = 0;
};


#endif //SORTINGVISUALIZER_BUTTON_H
