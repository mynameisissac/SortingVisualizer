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
#include "Sorting/QuickSort.h"

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
        // indicate if the whole sorting is finished
        bool finished = false;

        // the array to be sorted
        Array<int> arrayToSort;     // instantiate as array of storing int elements

        // owns sorting algorithm for performing sorting
        SortingAlgorithm* sortProcess1;          // cannot construct an abstract base class type class object

        //declaration of friend global function: handleInput(Engine& engine)
        friend void handleInput(Engine& engine);

    public:
        explicit Engine(int sizeOfArray);      // conversion constructor
        ~Engine();

        // the main loop of the program
        void run();

        // accessors
        BackGroundUI& getbackGroundUI();

};


#endif //SORTINGVISUALIZER_ENGINE_H
