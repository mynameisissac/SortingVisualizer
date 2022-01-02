//
// Created by kshou on 2021/12/26.
//

#include "Sorting/SelectionSort.h"


SelectionSort::SelectionSort(Array<int>& arrayToSort)
    : SortingAlgorithm(arrayToSort), stage(0), searchingStage(1), currentMinIndex(0)
{}


bool SelectionSort::sortOneIteration()
{
    if (stage < arrayToSort.getSize() - 1) {

        if (arrayToSort.getArrayPointer()[currentMinIndex] > arrayToSort.getArrayPointer()[searchingStage])
            currentMinIndex = searchingStage;

        int oldSearchingStage = searchingStage;     // store the oldSearchingPosition for filling the color
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

        arrayToSort.getRecArrPointer()[oldSearchingStage].setFillColor(arrayColor);
        arrayToSort.getRecArrPointer()[searchingStage].setFillColor(arrayHighlightColor);   // highlight while scanning

        return false;
    }

    return true;        // whole sorting is finished
}

void SelectionSort::sort(BackGroundUI& backGroundUi)
{

}