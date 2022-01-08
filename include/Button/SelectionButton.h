//
// Created by kshou on 2022/1/8.
//

#ifndef SORTINGVISUALIZER_SELECTIONBUTTON_H
#define SORTINGVISUALIZER_SELECTIONBUTTON_H

#include "Button.h"

class SelectionButton : public Button{
    private:
        // the index of the choice this button represent
        int choiceIndex;
        // indicate if this button is the currently selected one among the menu list
        bool beingSelected = false;

        // textures when different status
        sf::Texture normalTexture;
        sf::Texture hoveringTexture;

    public:
        // constructor
        SelectionButton(const sf::Vector2f& size, const sf::Vector2f& position, int choiceIndex);

        void resetTexture();

        void onClick() override;
        void onHovering() override;
};


#endif //SORTINGVISUALIZER_SELECTIONBUTTON_H
