//
// Created by kshou on 2021/12/23.
//

#include "Engine.h"
#include <iostream>
using namespace sf;

void Engine::handleInput(bool& freezeFlag)
{
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
            if (event.key.code == Keyboard::P) {
                std::cout << ( freezeFlag ? "Resume" : "Pause" ) << std::endl;
                PauseButton::onClick(freezeFlag);              // reverse the freezeFlag
            }

        }

        // mouse events
        if (event.type == Event::MouseButtonPressed){               // clicking

            // if mouse enter the region of pause button
            if (sideBar.getPauseButton().isHovering(window)){
                // pressing mouse left on the button
                if (Mouse::isButtonPressed(Mouse::Left)){
                    std::cout << ( freezeFlag ? "Resume" : "Pause" ) << std::endl;
                    PauseButton::onClick(freezeFlag);           // reverse the freezeFlag
                    clock.restart();            // make the animation smoother
                }
            }

        }


    }

}