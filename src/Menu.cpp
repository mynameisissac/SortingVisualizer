//
// Created by kshou on 2022/1/7.
//

#include "Menu.h"
#include "Engine.h"
#include <iostream>
using namespace sf;

Menu::Menu(Engine* engine)
    : engine(engine), selectedItemIndex(0), selectionList{}
{
    for (int i = 0; i < TOTAL; ++i)
        selectionList[i] = new SelectionButton(Vector2f(SELECTION_BUTTON_WIDTH, SELECTION_BUTTON_HEIGHT),
                                               Vector2f(MENU_SELECTION_POSITION_X, MENU_SELECTION_POSITION_Y +
                                                                                   (float) i * SELECTION_BUTTON_HEIGHT),
                                               i);
}

void Menu::draw()
{
    // draw the selectionList
    for (auto & selectionButton : selectionList)
        selectionButton->draw(engine->window);
    engine->window.display();

    engine->window.clear(BACKGROUND_COLOR);
}

// destructor for Button array
Menu::~Menu()
{
    for(auto & selectionButton : selectionList)
        delete selectionButton;
}

void Menu::run()
{
    // the main loop of the start menu process
    while (true) {
        draw();
        handleInput();
    }
}

void Menu::handleInput()
{
    Event event{};

    // event listening loop
    while (engine->window.pollEvent(event)) {
        // closing window (clicking on the x)
        if (event.type == Event::Closed){
            std::cout << "Closing window" << std::endl;
            engine->window.close();
        }

        // real time event listener
        // that means the condition will be checked at any time
        if (Keyboard::isKeyPressed(Keyboard::Escape)){
            std::cout << "Closing window" << std::endl;
            engine->window.close();
        }

        if (event.type == Event::MouseMoved)
            for (auto& selectionButton: selectionList) {
                if (selectionButton->isHovering(engine->window))
                    selectionButton->onHovering();
                else
                    selectionButton->resetTexture();
            }
    }
}


