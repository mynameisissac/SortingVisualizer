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
        T* arr;     // pointer to a dynamic array of type T

        // pointer to an array of rectangles for visualizing the array
        RectangleShape* representation;
        int size;   // size of the arrays

    public:

        explicit Array(int size);        // conversion constructor
        ~Array();

        int getSize() const;
        T* getArrayPointer() const;
        RectangleShape* getRecArrPointer() const;
        bool sorted() const;
        void print() const;

        void initialization();
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
 * initialize the data array and the representation array (i.e. rectangles array)
 * @tparam T type of elements stored in the data array
 */
template <typename T>
void Array<T>::initialization()
{

    float rectangle_width = WINDOW_WIDTH / float(size);

    // initialize the array by ascending order
    for (int i=0; i < size; ++i) {
        // HEIGHT_SCALE means to enlarge the number
        // arr[i] indicates the height of rectArr[i]
        arr[i] = (i + 1) * HEIGHT_SCALE;         // start from 1, prevent zero

        representation[i].setSize(Vector2f(rectangle_width, (float)arr[i]));
        representation[i].setFillColor(Color::Black);
        // set the origin of all rectangles to their left-bottom corner for drawing easier
        representation[i].setOrigin(0, representation[i].getSize().y);
        representation[i].setPosition(float(i) * representation[i].getSize().x, WINDOW_HEIGHT);
    }

}


template <typename T>
void Array<T>::draw(RenderWindow& window)
{
    // drawing the whole array by representing elements as rectangles
    for (int i=0; i < size; ++i) {
        // no change in width but only change in height
        representation[i].setSize(Vector2f(representation[i].getSize().x, (float)arr[i]));
        representation[i].setOrigin(0, representation[i].getSize().y);
        representation[i].setPosition(float(i) * representation[i].getSize().x, WINDOW_HEIGHT);
        window.draw(representation[i]);
    }
}

#endif //SORTINGVISUALIZER_ARRAY_H
