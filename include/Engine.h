//
// Created by kshou on 2021/12/23.
//

#ifndef SORTINGVISUALIZER_ENGINE_H
#define SORTINGVISUALIZER_ENGINE_H
#include <SFML/Graphics.hpp>
#include "BackGroundUI.h"
#include "Array.h"
#include "SideBar.h"
#include "Sorting/BogoSort.h"
#include "Sorting/SelectionSort.h"
#include "Sorting/BubbleSort.h"
#include "Sorting/InsertionSort.h"

// the flow of the whole program as an object
class Engine {
    private:    // data members
        // window
        sf::RenderWindow window;
        sf::Vector2i resolution;

        // sidebar (const)
        const SideBar sideBar;

        // for drawing all elements in batch
        BackGroundUI backgroundUI;

        // clock
        sf::Clock clock;
        float stopWatchOffSet;

        // the array to be sorted
        Array<int> arrayToSort;     // instantiate as array of storing int elements

        // owns sorting algorithm for performing sorting
        SortingAlgorithm* sortProcess1;          // cannot construct an abstract base class type class object

    public:
        explicit Engine(int sizeOfArray);      // conversion constructor
        ~Engine();

        void handleInput(bool& freezeFlag);

        // the main loop of the program
        void run();

};


#endif //SORTINGVISUALIZER_ENGINE_H
