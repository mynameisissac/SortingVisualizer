//
// Created by kshou on 2021/12/23.
//

#include "BogoSort.h"
#include <cstdlib>

// constructor
BogoSort::BogoSort(Array<int>& arrayToSort)
    : SortingAlgorithm(arrayToSort)
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



void BogoSort::sortOneIteration()
{
    // TODO: optimize the shuffling portion
    // shuffle the array once if not sorted
    if (!arrayToSort.sorted())
        shuffleArray(arrayToSort.getArrayPointer(), arrayToSort.getSize());
}
