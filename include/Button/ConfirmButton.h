//
// Created by kshou on 2022/1/8.
//

#ifndef SORTINGVISUALIZER_CONFIRMBUTTON_H
#define SORTINGVISUALIZER_CONFIRMBUTTON_H

#include "Button.h"

class ConfirmButton : public Button{
    private:
        // indicate the state of this button
        bool confirmed = false;
        // texture
        sf::Texture normalTexture;
        sf::Texture hoveringTexture;

    public:
        ConfirmButton(const sf::Vector2f& size, const sf::Vector2f& position);

        void resetTexture();
        void onClick() override;
        // reset the confirmed status to false;
        void reset();
        void onHovering() override;

        // accessor
        bool isConfirmed() const;
};


#endif //SORTINGVISUALIZER_CONFIRMBUTTON_H
