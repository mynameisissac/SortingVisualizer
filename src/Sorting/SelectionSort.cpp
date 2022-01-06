//
// Created by kshou on 2021/12/26.
//

#include "Sorting/SelectionSort.h"


SelectionSort::SelectionSort(Array<int>& arrayToSort,  Engine* engine)
    : SortingAlgorithm(arrayToSort, engine), stage(0), searchingStage(1), currentMinIndex(0)
{}


bool SelectionSort::sortOneIteration()
{
    if (stage < arrayToSort.getSize() - 1) {

        if (arrayToSort.getArrayPointer()[currentMinIndex] > arrayToSort.getArrayPointer()[searchingStage])
            currentMinIndex = searchingStage;

        arrayToSort.getRecArrPointer()[searchingStage].setFillColor(arrayColor);        // restore the old color
        // update the stages(counters)
        if ( (searchingStage + 1) >= arrayToSort.getSize()) {       // if need to go to next stage
            // swap the stage-th element with the minimum elements before going to next stage
            arrayToSort.swap(stage, currentMinIndex);
            // update the stage
            ++stage;
            // reset the start searching position
            currentMinIndex = stage;
            searchingStage = stage + 1;
        }
        else
            ++searchingStage;

        // highlight while scanning
        if (searchingStage < arrayToSort.getSize())
            arrayToSort.getRecArrPointer()[searchingStage].setFillColor(arrayHighlightColor);


        return false;
    }

    return true;        // whole sorting is finished
}

bool SelectionSort::sort()
{

}