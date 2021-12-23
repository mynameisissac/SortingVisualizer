//
// Created by kshou on 2021/12/23.
//

#ifndef SORTINGVISUALIZER_PROCESS_H
#define SORTINGVISUALIZER_PROCESS_H
#include <SFML/Graphics.hpp>
#include "SortingAlgorithm.h"
#include "BogoSort.h"

// the flow of the whole program as an object
class Process {
    private:    // data members
        // window
        sf::RenderWindow window;
        sf::Vector2i resolution;

        // the array to be sorted
        int size;
        int* arrayToSort;

        // array of rectangles to represent the array
        sf::RectangleShape* rectArray;

        // owns a sorting algorithm for performing sorting
        SortingAlgorithm* sortProcess;

    public:
        explicit Process(int sizeOfArray);      // conversion constructor
        ~Process();

        void handleInput();
        void draw(int* arrayToDraw, sf::RectangleShape* rectArr, int sizeOfArr);

        // the main loop of the program
        void run();

};


#endif //SORTINGVISUALIZER_PROCESS_H
