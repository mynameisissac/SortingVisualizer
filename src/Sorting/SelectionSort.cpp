//
// Created by kshou on 2021/12/26.
//

#include "Sorting/SelectionSort.h"
#include "Engine.h"
#include <iostream>

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
    static bool sortingFinished = false;    // to prevent the sorting run on sorted array
    if (sortingFinished || engine->windowIsClosed())
        return true;

    for (int i=0; i < arrayToSort.getSize() - 1; ++i){
        // prevent continue sorting after closing window
        if (engine->windowIsClosed())
            break;

        // find the minimum element
        int minIndex = i;
        for (int j = i + 1; j <= arrayToSort.getSize() - 1; ++j) {
            if (arrayToSort.getArrayPointer()[j] < arrayToSort.getArrayPointer()[minIndex])
                minIndex = j;

            //highlighting
            arrayToSort.getRecArrPointer()[j].setFillColor(arrayHighlightColor);
            // draw the array and ui
            engine->uiProcess();
            // restore its color
            arrayToSort.getRecArrPointer()[j].setFillColor(arrayColor);
        }

        arrayToSort.swap(i, minIndex);

        // draw the array and ui
        engine->uiProcess();
    }

    sortingFinished = true;
    return sortingFinished;
}
