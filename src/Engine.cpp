//
// Created by kshou on 2021/12/23.
//

#include "Engine.h"
#include "UI_common.h"
#include <ctime>
#include <iostream>
#include <iomanip>
using namespace sf;

// declaration of a global variable HEIGHT_SCALE
float HEIGHT_SCALE;

// create a sorting visualization process by passing a size of array to sort
Engine::Engine(int sizeOfArray)
    : arrayToSort(sizeOfArray), clock(), stopWatchOffSet(0), startMenu(this),
      sideBar(Vector2f(DISPLAY_WIDTH, 0.0f), Vector2f(SIDEBAR_WIDTH, SIDEBAR_HEIGHT), SIDEBAR_COLOR,
            new PauseButton(Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT),
                Vector2f((SIDEBAR_WIDTH - BUTTON_WIDTH) / 2 + DISPLAY_WIDTH, BUTTON_HEIGHT )))
        , backgroundUI(window, &sideBar)
{
    // window part UI
    resolution = Vector2i(WINDOW_WIDTH, WINDOW_HEIGHT);
    window.create(VideoMode(resolution.x, resolution.y), "Sorting Visualizer", Style::Close | Style::Titlebar);
    window.setFramerateLimit(60);

    // start menu part (choosing the sorting algorithms and array size here)
    startMenu.run();

    // initialization of global variable HEIGHT_SCALE, must be done before Array<int>.initialization();
    HEIGHT_SCALE = (float)WINDOW_HEIGHT / SizeOfArray;

    // array to be sorted as an object
    arrayToSort.initialization();
    /* initialize random seed: */
    srand(time(nullptr)); // NOLINT(cert-msc51-cpp)
    BogoSort::shuffleArray(arrayToSort.getArrayPointer(), arrayToSort.getSize());       // randomize the array

    arrayToSort.print();            // print the shuffled arrayToSort
    backgroundUI.draw("0");
}

// helper function to set precision of a float and return a string
std::string setPrecisionToString(float floatNum, int n)
{
    std::stringstream stream;
    stream << std::fixed << std::setprecision(n) << floatNum;
    return stream.str();
}

// the main game loop end until the window is closed
void Engine::run()
{
    // keep handling input and drawing while the Engine is running
    while (window.isOpen()) {

        handleInput();

        /*if (!PauseButton::isPaused() && !finished){
            arrayToSort.draw(window);            // draw the array out after each iteration of the sorting algorithm
            backgroundUI.draw(setPrecisionToString((clock.getElapsedTime().asSeconds() + stopWatchOffSet), 2));
            finished = sortProcess1->sortOneIteration();        // TODO: add more sorting algorithms
            sf::sleep(Time(milliseconds(DELAY_TIME)));
        }*/

        finished = sortProcess1->sort();         // TODO: Implement all

        static bool sayOnce = true;                 //prevent printing "sorting finished." too many times
        if (finished && sayOnce) {
            std::cout << "Sorting finished." << std::endl;
            sayOnce = false;
        }
        
    }
}

Engine::~Engine()
{
    delete sortProcess1;
}

BackGroundUI& Engine::getbackGroundUI()
{
    return backgroundUI;
}

void Engine::draw()
{
    arrayToSort.draw(window);            // draw the array out after each iteration of the sorting algorithm
    backgroundUI.draw(setPrecisionToString((clock.getElapsedTime().asSeconds() + stopWatchOffSet), 2));
    sf::sleep(Time(milliseconds(DELAY_TIME)));
}

void Engine::pausing()
{
    while(PauseButton::isPaused() && window.isOpen())       // prevent program not terminating when closing with paused
        handleInput();      // until resume
}

void Engine::uiProcess()
{
    if (window.isOpen()) {
        handleInput();
        draw();
        pausing();
    }
}

bool Engine::windowIsClosed() const
{
    return !window.isOpen();
}
