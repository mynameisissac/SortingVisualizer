//
// Created by kshou on 2022/1/3.
//

#include "Sorting/InsertionSort.h"
#include <iostream>

InsertionSort::InsertionSort(Array<int>& arrayToSort)
    : SortingAlgorithm(arrayToSort), stage(1), searchingStage(stage - 1), found(false)
{}

bool InsertionSort::sortOneIteration()
{
    if (stage < arrayToSort.getSize()){

        // search for the correct position to stop inserting
        if (arrayToSort.getArrayPointer()[searchingStage] < arrayToSort.getArrayPointer()[searchingStage + 1])
            found = true;
        else    // swapping while searching
            arrayToSort.swap(searchingStage + 1, searchingStage);

        // update counters
        if (found || searchingStage == 0){      // if need to update stage(outer loop counter)
            ++stage;
            searchingStage = stage - 1;     // reset the first searchingPosition for next stage
            found = false;
        }
        else
            --searchingStage;

        return false;
    }

    return true;            // whole sorting is finished
}


void InsertionSort::sort(BackGroundUI& backGroundUi)
{
}
