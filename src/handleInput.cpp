//
// Created by kshou on 2021/12/23.
//

#include "Engine.h"
#include <iostream>
using namespace sf;

void Engine::handleInput()
{
    std::string setPrecisionToString(float floatNum, int n);        // declaration

    Event event{};

    // event listening loop
    while (window.pollEvent(event)) {

        // closing window (clicking on the x)
        if (event.type == Event::Closed){
            std::cout << "Closing window" << std::endl;
            window.close();
        }

        // real time event listener
        // that means the condition will be checked at any time
        if (Keyboard::isKeyPressed(Keyboard::Escape)){
            std::cout << "Closing window" << std::endl;
            window.close();
        }

        // keyboard event
        if (event.type == Event::KeyPressed){

            // key P for pausing the sorting process
            if (!finished && event.key.code == Keyboard::P) {
                std::cout << ( PauseButton::getFreezeFlag() ? "Resume" : "Pause" ) << std::endl;

                // if not paused before pressing
                if (!PauseButton::getFreezeFlag())
                    stopWatchOffSet += clock.restart().asSeconds();
                else    // if paused before
                    clock.restart();

                sideBar.getPauseButton().onClick();           // reverse the freezeFlag and change the texture of button

                // draw again to display the changed texture
                arrayToSort.draw(window);
                backgroundUI.draw(setPrecisionToString((clock.getElapsedTime().asSeconds() + stopWatchOffSet), 2));
            }

        }

        // mouse events
        if (event.type == Event::MouseButtonPressed){               // clicking

            // if mouse enter the region of pause button
            if (!finished && sideBar.getPauseButton().isHovering(window)){
                // pressing mouse left on the button
                if (Mouse::isButtonPressed(Mouse::Left)){
                    std::cout << ( PauseButton::getFreezeFlag() ? "Resume" : "Pause" ) << std::endl;

                    // if not paused before pressing
                    if (!PauseButton::getFreezeFlag())
                        stopWatchOffSet += clock.restart().asSeconds();
                    else    // if paused before
                        clock.restart();

                    sideBar.getPauseButton().onClick();           // reverse the freezeFlag and change the texture of button

                    // draw again to display the changed texture
                    arrayToSort.draw(window);
                    backgroundUI.draw(setPrecisionToString((clock.getElapsedTime().asSeconds() + stopWatchOffSet), 2));
                }
            }

        }


    }

}
