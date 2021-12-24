//
// Created by kshou on 2021/12/23.
//

#include "Process.h"
#include <iostream>
using namespace sf;

const int WINDOW_WIDTH = 512;
const int WINDOW_HEIGHT = 512;
const int HEIGHT_SCALE = 10;
const float DELAY_TIME = 0.1;       // unit: seconds

// function declaration
void printArray(int* arr, int size);

// initializing the new array by shuffling it
void initializeArrays(int* arr, RectangleShape* rectArr, int size)
{
    float rectangle_width = WINDOW_WIDTH / float(size);

    // initialize the array by ascending order
    for (int i=0; i < size; ++i) {
        // HEIGHT_SCALE means to enlarge the number
        // arr[i] indicates the height of rectArr[i]
        arr[i] = (i + 1) * HEIGHT_SCALE;         // start from 1, prevent zero

        rectArr[i].setSize(Vector2f(rectangle_width, (float)arr[i]));
        rectArr[i].setFillColor(Color::Black);
        // set the origin of all rectangles to their left-bottom corner for drawing easier
        rectArr[i].setOrigin(0, rectArr[i].getSize().y);
        rectArr[i].setPosition(float(i) * rectArr[i].getSize().x, WINDOW_HEIGHT);
    }

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
    : size(sizeOfArray), clock()
{
    // window part i.e. UI
    resolution = Vector2i(WINDOW_WIDTH, WINDOW_HEIGHT);
    window.create(VideoMode(resolution.x, resolution.y), "Sorting Visualizer", Style::Close | Style::Titlebar);

    // create a sorting algorithm instance
    arrayToSort = new int[size];        // create the dynamic array
    rectArray = new RectangleShape[size];
    initializeArrays(arrayToSort, rectArray, size);

    sortProcess = new BogoSort(arrayToSort, size);

    printArray(arrayToSort, size);
}


// the main game loop end until the window is closed
void Process::run()
{
    // keep handling input and drawing while the Process is running
    while (window.isOpen()) {
        handleInput();

        float timeChange = clock.getElapsedTime().asSeconds();
        if (timeChange >= DELAY_TIME){              // similar to time.sleep(DELAY_TIME)
            sortProcess->sortOneIteration();        // TODO: add more sorting algorithms
            draw(arrayToSort, rectArray, size);     // draw the array out after each iteration of the sorting algorithm
            clock.restart();
        }
    }

}

// two-buffering drawing
void Process::draw(int* arrayToDraw, RectangleShape* rectArr, int sizeOfArr)
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

Process::~Process()
{
    delete [] arrayToSort;       // release dynamic allocated memory
    delete [] rectArray;
    delete sortProcess;

}