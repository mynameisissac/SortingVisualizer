//
// Created by kshou on 2021/12/23.
//

#include "Sorting/BogoSort.h"
#include "Engine.h"
#include <cstdlib>

// constructor
BogoSort::BogoSort(Array<int>& arrayToSort, Engine* engine)
    : SortingAlgorithm(arrayToSort, engine)
{}


// static member function
// reference : https://en.wikipedia.org/wiki/Fisher%E2%80%93Yates_shuffle
void BogoSort::shuffleArray(int* arr, int size)
{
    for (int i = size - 1; i >= 1; --i){
        unsigned int j = rand() % (i + 1);      // 0 <= j <= i      NOLINT(cert-msc50-cpp)

        // swap arr[i] and arr[j]
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

bool BogoSort::sort()
{
    static bool sortingFinished = false;    // to prevent the sorting run on sorted array
    if (sortingFinished || engine->windowIsClosed())
        return true;

    while (!arrayToSort.sorted() && !engine->windowIsClosed()){
        shuffleArray(arrayToSort.getArrayPointer(), arrayToSort.getSize());
        // draw the output
        engine->uiProcess();
    }

    sortingFinished = true;
    return sortingFinished;
}


bool BogoSort::sortOneIteration()
{
    // shuffle the array once if not sorted
    if (!arrayToSort.sorted()) {
        shuffleArray(arrayToSort.getArrayPointer(), arrayToSort.getSize());
        return false;
    }

    return true;
}

