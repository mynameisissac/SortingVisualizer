//
// Created by kshou on 2021/12/29.
//

#include "Button/PauseButton.h"

// definition of static data member
bool PauseButton::freezeFlag = false;

PauseButton::PauseButton(const sf::Vector2f& size, const sf::Vector2f& position)
    : Button(size, position), pauseTexture(), resumeTexture()
{
    pauseTexture.loadFromFile("../assets/pauseTexture_square2.jpg");
    resumeTexture.loadFromFile("../assets/playTexture_square2.png");

    setTexture(&pauseTexture);      // initial inputBox of pauseButton is pauseTexture
}


void PauseButton::onClick()
{
    // reverse the freezeFlag to perform pausing/resuming
    freezeFlag = !freezeFlag;

    // change the button's texture
    if (getDisplay().getTexture() == &pauseTexture)
        setTexture(&resumeTexture);
    else
        setTexture(&pauseTexture);

}

bool PauseButton::isPaused()
{
    return freezeFlag;
}

void PauseButton::onHovering()
{
    // do nothing
}
