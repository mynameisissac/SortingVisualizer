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
    : arrayToSort(sizeOfArray) ,clock()
{
    // window part i.e. UI
    resolution = Vector2i(WINDOW_WIDTH, WINDOW_HEIGHT);
    window.create(VideoMode(resolution.x, resolution.y), "Sorting Visualizer", Style::Close | Style::Titlebar);

    // array to be sorted as an object
    arrayToSort.initialization();
    /* initialize random seed: */
    srand(time(nullptr)); // NOLINT(cert-msc51-cpp)
    BogoSort::shuffleArray(arrayToSort.getArrayPointer(), arrayToSort.getSize());       // randomize the array

    // create a sorting algorithm instance
    sortProcess = new BogoSort(arrayToSort);


    arrayToSort.print();
}


// the main game loop end until the window is closed
void Engine::run()
{
    // keep handling input and drawing while the Engine is running
    while (window.isOpen()) {
        handleInput();

        float timeChange = clock.getElapsedTime().asSeconds();
        if (timeChange >= DELAY_TIME){              // similar to time.sleep(DELAY_TIME)
            sortProcess->sortOneIteration();        // TODO: add more sorting algorithms
            draw(arrayToSort.getArrayPointer(), arrayToSort.getRecArrPointer(), arrayToSort.getSize());     // draw the array out after each iteration of the sorting algorithm
            clock.restart();
        }
    }

}

// two-buffering drawing
void Engine::draw(int* arrayToDraw, RectangleShape* rectArr, int sizeOfArr)
{
    // clear the screen before drawing
    window.clear(Color::White);

    // drawing the whole array by representing elements as rectangles
    for (int i=0; i < sizeOfArr; ++i) {
        // no change in width but only change in height
        rectArr[i].setSize(Vector2f(rectArr[i].getSize().x, (float)arrayToDraw[i]));
        rectArr[i].setOrigin(0, rectArr[i].getSize().y);
        rectArr[i].setPosition(float(i) * rectArr[i].getSize().x, WINDOW_HEIGHT);
        window.draw(rectArr[i]);
    }

    window.display();       // swap the back buffer and front buffer
}

Engine::~Engine()
{
    delete sortProcess;
}