//
// Created by kshou on 2021/12/23.
//

#include "Engine.h"
#include <iostream>
using namespace sf;

void handleInput(Engine& engine)
{
    std::string setPrecisionToString(float floatNum, int n);        // declaration

    Event event{};

    // event listening loop
    while (engine.window.pollEvent(event)) {

        // closing window (clicking on the x)
        if (event.type == Event::Closed){
            std::cout << "Closing window" << std::endl;
            engine.window.close();
        }

        // real time event listener
        // that means the condition will be checked at any time
        if (Keyboard::isKeyPressed(Keyboard::Escape)){
            std::cout << "Closing window" << std::endl;
            engine.window.close();
        }

        // keyboard event
        if (event.type == Event::KeyPressed){

            // key P for pausing the sorting process
            if (!engine.finished && event.key.code == Keyboard::P) {
                std::cout << ( PauseButton::getFreezeFlag() ? "Resume" : "Pause" ) << std::endl;

                // if not paused before pressing
                if (!PauseButton::getFreezeFlag())
                    engine.stopWatchOffSet += engine.clock.restart().asSeconds();
                else    // if paused before
                    engine.clock.restart();

                engine.sideBar.getPauseButton().onClick();           // reverse the freezeFlag and change the texture of button

                // draw again to display the changed texture
                engine.arrayToSort.draw(engine.window);
                engine.backgroundUI.draw(setPrecisionToString((engine.clock.getElapsedTime().asSeconds() + engine.stopWatchOffSet), 2));
            }

        }

        // mouse events
        if (event.type == Event::MouseButtonPressed){               // clicking

            // if mouse enter the region of pause button
            if (!engine.finished && engine.sideBar.getPauseButton().isHovering(engine.window)){
                // pressing mouse left on the button
                if (Mouse::isButtonPressed(Mouse::Left)){
                    std::cout << ( PauseButton::getFreezeFlag() ? "Resume" : "Pause" ) << std::endl;

                    // if not paused before pressing
                    if (!PauseButton::getFreezeFlag())
                        engine.stopWatchOffSet += engine.clock.restart().asSeconds();
                    else    // if paused before
                        engine.clock.restart();

                    engine.sideBar.getPauseButton().onClick();           // reverse the freezeFlag and change the texture of button

                    // draw again to display the changed texture
                    engine.arrayToSort.draw(engine.window);
                    engine.backgroundUI.draw(setPrecisionToString((engine.clock.getElapsedTime().asSeconds() + engine.stopWatchOffSet), 2));
                }
            }

        }


    }

}
