//
// Created by kshou on 2021/12/29.
//

#ifndef SORTINGVISUALIZER_PAUSEBUTTON_H
#define SORTINGVISUALIZER_PAUSEBUTTON_H
#include "Button.h"

class PauseButton : public Button{
    private:
        // textures
        sf::Texture pauseTexture;
        sf::Texture resumeTexture;
        // bool controlling the freezing of window
        static bool freezeFlag;

    public:
        PauseButton(const sf::Vector2f& size, const sf::Vector2f& position);
        // accessor
        static bool isPaused();

        void onClick() override;
};


#endif //SORTINGVISUALIZER_PAUSEBUTTON_H
