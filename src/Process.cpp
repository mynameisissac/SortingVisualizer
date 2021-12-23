//
// Created by kshou on 2021/12/23.
//

#include "Process.h"
#include <iostream>
using namespace sf;

const int WINDOW_WIDTH = 512;
const int WINDOW_HEIGHT = 512;
const int SCALE = 5;

// initializing the new array by shuffling it
void initializeArray(int* arr, int size)
{
    // initialize the array by ascending order
    for (int i=0; i < size; ++i)
        // SCALE means to enlarge the number
        arr[i] = (i + 1) * SCALE;         // start from 1, prevent zero

    BogoSort::shuffleArray(arr, size);
}

// print the array on console for checking
void printArray(int* arr, int size)
{
    for (int i =0; i < size; ++i)
        std::cout << arr[i] << ' ';
    std::cout << std::endl;
}

// create a sorting visualization process by passing a size of array to sort
Process::Process(int sizeOfArray)
    : size(sizeOfArray)
{
    // window part i.e. UI
    resolution = Vector2i(WINDOW_WIDTH, WINDOW_HEIGHT);
    window.create(VideoMode(resolution.x, resolution.y), "Sorting Visualizer", Style::Close | Style::Titlebar);

    // create a sorting algorithm instance
    arrayToSort = new int[size];        // create the dynamic array
    initializeArray(arrayToSort, size);

    sortProcess = new BogoSort(arrayToSort, size);

    printArray(arrayToSort, size);
}


// the main game loop end until the window is closed
void Process::run()
{
    // keep handling input and drawing while the Process is running
    while (window.isOpen()) {
        handleInput();
        sortProcess->sortOneIteration();
        draw(arrayToSort, size);        // draw the array out after each iteration of the sorting algorithm
    }

}

// two-buffering drawing
void Process::draw(int* arrayToDraw, int sizeOfArr)
{
    // clear the screen before drawing
    window.clear(Color::White);

    // drawing the whole array by representing elements as rectangles


    window.display();       // swap the back buffer and front buffer
}

Process::~Process()
{
    delete [] arrayToSort;       // release dynamic allocated memory
    delete sortProcess;
}