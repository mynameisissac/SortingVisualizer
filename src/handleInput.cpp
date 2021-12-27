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


        if (event.type == Event::KeyPressed){

            // key P for pausing the sorting process
            if (event.key.code == Keyboard::P) {
                std::cout << ( freezeFlag ? "Resume" : "Pause" ) << std::endl;
                freezeFlag = !freezeFlag;              // reverse the freezeFlag
            }

        }

    }

}