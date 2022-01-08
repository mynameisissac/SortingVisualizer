//
// Created by kshou on 2022/1/7.
//

#include "Menu.h"
#include "Engine.h"
#include <iostream>
using namespace sf;

Menu::Menu(Engine* engine)
    : engine(engine), selectedItemIndex(-1), selectionList{}, confirmButton(nullptr)
{
    for (int i = 0; i < TOTAL; ++i)
        // instances of selectionButton
        selectionList[i] = new SelectionButton(Vector2f(SELECTION_BUTTON_WIDTH, SELECTION_BUTTON_HEIGHT),
                                               Vector2f(MENU_SELECTION_POSITION_X, MENU_SELECTION_POSITION_Y +
                                                                                   (float) i * SELECTION_BUTTON_HEIGHT),
                                               i);
    // instance of confirmButton
    confirmButton = new ConfirmButton(Vector2f(CONFIRM_BUTTON_WIDTH, CONFIRM_BUTTON_HEIGHT),
                                      Vector2f(MENU_CONFIRM_POSITION_X, MENU_CONFIRM_POSITION_Y));
}

void Menu::draw()
{
    // draw the selectionList
    for (auto & selectionButton : selectionList)
        selectionButton->draw(engine->window);

    // draw the confirmButton
    confirmButton->draw(engine->window);
    engine->window.display();

    engine->window.clear(BACKGROUND_COLOR);
}

// destructor for Button array
Menu::~Menu()
{
    for(auto & selectionButton : selectionList)
        delete selectionButton;

    delete confirmButton;
}

void Menu::run()
{
    bool algorithmSelected = false;
    bool arraySizeValid = true;         // since we have default array size

    // the main loop of the start menu process
    while (!algorithmSelected || !arraySizeValid || !confirmButton->isConfirmed()) {
        draw();
        handleInput(algorithmSelected, arraySizeValid);
    }

    // construct an Array<int> instance and copy it to engine->arrayToSort, and
    // assign the selected sorting algorithm for engine
    engine->arrayToSort = SizeOfArray;          // call implicit conversion constructor and overloaded operator=
    if (selectedItemIndex == 0)
        engine->sortProcess1 = new SelectionSort(engine->arrayToSort, engine);
    else if (selectedItemIndex == 1)
        engine->sortProcess1 = new BubbleSort(engine->arrayToSort, engine);
    else if (selectedItemIndex == 2)
        engine->sortProcess1 = new InsertionSort(engine->arrayToSort, engine);
    else if (selectedItemIndex == 3)
        engine->sortProcess1 = new QuickSort(engine->arrayToSort, engine);
    else if (selectedItemIndex == 4)
        engine->sortProcess1 = new BogoSort(engine->arrayToSort, engine);
}

void Menu::handleInput(bool& selected, bool& arraySizeValid)
{
    Event event{};

    // event listening loop
    while (engine->window.pollEvent(event)) {

        if (event.type == Event::MouseMoved) {
            // check the selection list buttons and confirmation button
            for (auto& selectionButton: selectionList) {
                if (selectionButton->isHovering(engine->window))
                    selectionButton->onHovering();
                else
                    selectionButton->resetTexture();
            }
            // check confirmation button
            if (confirmButton->isHovering(engine->window))
                confirmButton->onHovering();
            else
                confirmButton->resetTexture();
        }

        // Mouse clicking events
        if (event.type == Event::MouseButtonPressed) {
            // onClick event handling of the selection menu
            for (int i = 0; i < TOTAL; ++i)
                if (selectionList[i]->isHovering(engine->window)) {
                    // call onClick() of old selectedButton to reverse its beingSelected flag
                    if (selectedItemIndex != -1)
                        selectionList[selectedItemIndex]->onClick();
                    selectedItemIndex = i;
                    selectionList[selectedItemIndex]->onClick();
                    selected = true;

                    // any changes will reset the confirmation flag
                    confirmButton->reset();
                }

            // onClick event of confirmButton
            if (confirmButton->isHovering(engine->window))
                confirmButton->onClick();
        }

    }
}


