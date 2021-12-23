//
// Created by kshou on 2021/12/23.
//

#include "Process.h"
#include <iostream>
using namespace sf;

void Process::handleInput()
{
    Event event{};

    // event listening loop
    while (window.pollEvent(event)) {

        // closing window (clicking on the x)
        if (event.type == Event::Closed){
            std::cout << "Closing window" << std::endl;
            window.close();
        }

        if (Keyboard::isKeyPressed(Keyboard::Escape)){
            std::cout << "Closing window" << std::endl;
            window.close();
        }
    }

}