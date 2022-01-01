//
// Created by kshou on 2021/12/25.
//

#ifndef SORTINGVISUALIZER_ARRAY_H
#define SORTINGVISUALIZER_ARRAY_H

#include <SFML/Graphics.hpp>
#include "UI_common.h"
#include <iostream>
using namespace sf;

// implementation of custom Array class type template
template <typename T>
class Array {
    private:
        T* arr;                             // pointer to a dynamic array of type T

        // pointer to an array of rectangles for visualizing the array
        RectangleShape* representation;
        int size;                           // size of the arrays

    public:

        explicit Array(int size);           // conversion constructor
        ~Array();

        int getSize() const;
        T* getArrayPointer() const;
        RectangleShape* getRecArrPointer() const;
        bool sorted() const;
        void print() const;

        // find the index of minimum element starting from a specific position
        // operator< overloading for type T required
        int findMinIndex(int from) const;

        void initialization();
        bool swap(int index1, int index2);  // swap two elements in the data array by given indexes
        void draw(RenderWindow& window);
};

template <typename T>
Array<T>::Array(int size)
    : size(size)
{
    arr = new T[size];
    representation = new sf::RectangleShape[size];
}

template <typename T>
Array<T>::~Array()
{
    // release allocated memory
    delete [] arr;
    delete [] representation;
}

// accessor that return the size of the array
template <typename T>
int Array<T>::getSize() const
{
    return size;
}

// accessor that return the pointer to the first element in the data array
template <typename T>
T* Array<T>::getArrayPointer() const
{
    return arr;
}

// accessor that return the pointer to the first element in the representation array
template <typename T>
RectangleShape* Array<T>::getRecArrPointer() const
{
    return representation;
}

// predicate that check if the data array is sorted
template <typename T>
bool Array<T>::sorted() const
{
    for (int i=0; i < size - 1; ++i)
        if (arr[i+1] < arr[i])          // assumption: operator< loaded for type T
            return false;

    return true;
}

template <typename T>
void Array<T>::print() const
{
    for (int i =0; i < size; ++i)
        std::cout << arr[i] << ' ';

    std::cout << std::endl;
}

/**
 * search the minimum element from a given position
 * @tparam T type of elements stored in the data array
 * @param from starting position to search
 * @return index of minimum element start from give position
 */
template <typename T>
int Array<T>::findMinIndex(int from) const
{
    int smallestIndex = from++;

    while (from < size){
        if (arr[smallestIndex] > arr[from])
            smallestIndex = from;
        ++from;
    }

    return smallestIndex;
}

/**
 * initialize the data array and the representation array (i.e. rectangles array)
 * @tparam T type of elements stored in the data array
 */
template <typename T>
void Array<T>::initialization()
{

    float rectangle_width = DISPLAY_WIDTH / float(size);

    // initialize the array by ascending order
    for (int i=0; i < size; ++i) {
        // HEIGHT_SCALE means to enlarge the number
        // arr[i] indicates the height of rectArr[i]
        arr[i] = (i + 1) * HEIGHT_SCALE;         // start from 1, prevent zero

        representation[i].setSize(Vector2f(rectangle_width, (float)arr[i]));
        representation[i].setFillColor(ARRAY_COLOR);        // grey
        // set the origin of all rectangles to their left-bottom corner for drawing easier
        representation[i].setOrigin(0, representation[i].getSize().y);
        representation[i].setPosition(float(i) * representation[i].getSize().x, DISPLAY_HEIGHT);
    }

}

/**
 * swap two elements in the data array by given indexes
 * @tparam T type of elements stored in the data array
 * @param index1 position of element1
 * @param index2 position of element2
 * @return true if swap is successful, otherwise false
 */
template <typename T>
bool Array<T>::swap(int index1, int index2)
{
    // validation of indexes
    if (index1 < 0 || index2 < 0 || index1 >= size || index2 >= size)
        return false;

    T temp = arr[index1];
    arr[index1] = arr[index2];
    arr[index2] = temp;
    return true;
}

template <typename T>
void Array<T>::draw(RenderWindow& window)
{
    sf::sleep(Time(milliseconds(DELAY_TIME)));

    // drawing the whole array by representing elements as rectangles
    for (int i=0; i < size; ++i) {
        // no change in width but only change in height
        representation[i].setSize(Vector2f(representation[i].getSize().x, (float)arr[i]));
        representation[i].setOrigin(0, representation[i].getSize().y);
        representation[i].setPosition(float(i) * representation[i].getSize().x, DISPLAY_HEIGHT);
        window.draw(representation[i]);
    }

}

#endif //SORTINGVISUALIZER_ARRAY_H
