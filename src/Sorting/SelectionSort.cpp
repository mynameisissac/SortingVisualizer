//
// Created by kshou on 2021/12/26.
//

#include "Sorting/SelectionSort.h"


SelectionSort::SelectionSort(Array<int>& arrayToSort)
    : SortingAlgorithm(arrayToSort), stage(0)
{}


// findMinIndex(Array<int> array, int stage); TODO

void SelectionSort::sortOneIteration()
{
    if (stage < arrayToSort.getSize() - 1) {

        // swap the stage-th element with the minimum elements after it
        arrayToSort.swap(stage, arrayToSort.findMinIndex(stage));
        stage++;        // update the stage status
    }

}

