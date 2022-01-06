//
// Created by kshou on 2021/12/23.
//

#include "Engine.h"
#include "UI_common.h"
#include <ctime>
#include <iostream>
#include <iomanip>
using namespace sf;


// create a sorting visualization process by passing a size of array to sort
Engine::Engine(int sizeOfArray)
    : arrayToSort(sizeOfArray), clock(), stopWatchOffSet(0),
      sideBar(Vector2f(DISPLAY_WIDTH, 0.0f), Vector2f(SIDEBAR_WIDTH, SIDEBAR_HEIGHT), SIDEBAR_COLOR,
            new PauseButton(Vector2f(BUTTON_WIDTH, BUTTON_HEIGHT),
                Vector2f((SIDEBAR_WIDTH - BUTTON_WIDTH) / 2 + DISPLAY_WIDTH, BUTTON_HEIGHT )))
        , backgroundUI(window, &sideBar)
{
    // window part i.e. UI
    resolution = Vector2i(WINDOW_WIDTH, WINDOW_HEIGHT);
    window.create(VideoMode(resolution.x, resolution.y), "Sorting Visualizer", Style::Close | Style::Titlebar);
    window.setFramerateLimit(60);

    // array to be sorted as an object
    arrayToSort.initialization();
    /* initialize random seed: */
    srand(time(nullptr)); // NOLINT(cert-msc51-cpp)
    BogoSort::shuffleArray(arrayToSort.getArrayPointer(), arrayToSort.getSize());       // randomize the array

    // create sorting algorithm instance
    sortProcess1 = new QuickSort(arrayToSort);          // choose a sorting algorithm here

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

        handleInput(*this);

        /*if (!PauseButton::isPaused() && !finished){
            arrayToSort.draw(window);            // draw the array out after each iteration of the sorting algorithm
            backgroundUI.draw(setPrecisionToString((clock.getElapsedTime().asSeconds() + stopWatchOffSet), 2));
            finished = sortProcess1->sortOneIteration();        // TODO: add more sorting algorithms
            sf::sleep(Time(milliseconds(DELAY_TIME)));
        }*/

        finished = sortProcess1->sort(*this);         // TODO: VERY future

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
