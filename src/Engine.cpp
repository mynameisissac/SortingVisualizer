//
// Created by kshou on 2021/12/23.
//

#include "Engine.h"
#include "UI_common.h"
#include <ctime>
#include <iostream>
using namespace sf;


// create a sorting visualization process by passing a size of array to sort
Engine::Engine(int sizeOfArray)
    : arrayToSort(sizeOfArray), clock(),
    sideBar(Vector2f(DISPLAY_WIDTH, 0.0f), Vector2f(SIDEBAR_WIDTH, SIDEBAR_HEIGHT), SIDEBAR_COLOR,
            new PauseButton(Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT),
                Vector2f((SIDEBAR_WIDTH - BUTTON_WIDTH) / 2 + DISPLAY_WIDTH, BUTTON_HEIGHT )))
        , backgroundUI(window, &sideBar)
{
    // window part i.e. UI
    resolution = Vector2i(WINDOW_WIDTH, WINDOW_HEIGHT);
    window.create(VideoMode(resolution.x, resolution.y), "Sorting Visualizer", Style::Close | Style::Titlebar);

    // array to be sorted as an object
    arrayToSort.initialization();
    /* initialize random seed: */
    srand(time(nullptr)); // NOLINT(cert-msc51-cpp)
    BogoSort::shuffleArray(arrayToSort.getArrayPointer(), arrayToSort.getSize());       // randomize the array

    // create sorting algorithm instance
    sortProcess1 = new BubbleSort(arrayToSort);          // choose a sorting algorithm here

    arrayToSort.print();            // print the shuffled arrayToSort
    backgroundUI.draw();
}


// the main game loop end until the window is closed
void Engine::run()
{
    // keep handling input and drawing while the Engine is running
    while (window.isOpen()) {
        static bool freeze = false;     // a flag to control the pause event
        handleInput(freeze);

        if (!freeze){              // similar to time.sleep(DELAY_TIME)
            arrayToSort.draw(window);             // draw the array out after each iteration of the sorting algorithm
            backgroundUI.draw();
            sortProcess1->sortOneIteration();        // TODO: add more sorting algorithms
        }

        //sortProcess1->sort(backgroundUI);
    }
}


Engine::~Engine()
{
    delete sortProcess1;
}