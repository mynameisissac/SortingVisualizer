//
// Created by kshou on 2021/12/23.
//

#include "BogoSort.h"
#include <cstdlib>
#include <ctime>

// constructor
BogoSort::BogoSort(int* arr, int size)
    : SortingAlgorithm(arr, size)
{
    /* initialize random seed: */
    srand(time(nullptr)); // NOLINT(cert-msc51-cpp)
}


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

}
