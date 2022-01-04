//
// Created by kshou on 2022/1/3.
//

#include "Sorting/InsertionSort.h"

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

        arrayToSort.getRecArrPointer()[searchingStage].setFillColor(arrayColor);
        // update counters
        if (found || searchingStage == 0){      // if need to update stage(outer loop counter)
            ++stage;
            searchingStage = stage - 1;     // reset the first searchingPosition for next stage
            found = false;
        }
        else
            --searchingStage;

        // highlighting
        if (searchingStage < arrayToSort.getSize() - 1)
            arrayToSort.getRecArrPointer()[searchingStage].setFillColor(arrayHighlightColor);

        return false;
    }

    return true;            // whole sorting is finished
}


bool InsertionSort::sort(BackGroundUI& backGroundUi)
{
    for (int i=1; i < arrayToSort.getSize(); ++i)
        for (int j = i - 1; j >= 0; --j) {

            // if the position to insert is found
            if (arrayToSort.getArrayPointer()[j + 1] > arrayToSort.getArrayPointer()[j])
                break;
            else
                arrayToSort.swap(j, j + 1);            // swap while searching position to insert

            // draw the array
            arrayToSort.draw(backGroundUi.getWindow());
            backGroundUi.draw("0");        // draw all the backGround elements and display the screen



        }

    return true;
}
