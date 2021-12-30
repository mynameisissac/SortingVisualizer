//
// Created by kshou on 2021/12/23.
//

#ifndef SORTINGVISUALIZER_ENGINE_H
#define SORTINGVISUALIZER_ENGINE_H
#include <SFML/Graphics.hpp>
#include "Array.h"
#include "SideBar.h"
#include "Sorting/BogoSort.h"
#include "Sorting/SelectionSort.h"
#include "Sorting/BubbleSort.h"

// the flow of the whole program as an object
class Engine {
    private:    // data members
        // window
        sf::RenderWindow window;
        sf::Vector2i resolution;

        // sidebar (const)
        const SideBar sideBar;

        // clock
        sf::Clock clock;      // for timing, delay

        // the array to be sorted
        Array<int> arrayToSort;     // instantiate as array of storing int elements

        // owns sorting algorithm for performing sorting
        SortingAlgorithm* sortProcess1;          // cannot construct an abstract base class type class object

    public:
        explicit Engine(int sizeOfArray);      // conversion constructor
        ~Engine();

        void handleInput(bool& freezeFlag);

        // draw all the components on the window
        void draw();

        // the main loop of the program
        void run();

};


#endif //SORTINGVISUALIZER_ENGINE_H
