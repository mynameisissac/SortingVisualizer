//
// Created by kshou on 2021/12/31.
//

#include "Sorting/BubbleSort.h"

BubbleSort::BubbleSort(Array<int>& arrayToSort, Engine* engine)
    : SortingAlgorithm(arrayToSort, engine), counterInnerLoop(0), counterOuterLoop(0)
{}


bool BubbleSort::sort()
{
    static bool sortingFinished = false;    // to prevent the sorting run on sorted array
    if (sortingFinished)
        return true;

    for (int i=0; i < arrayToSort.getSize() - 1 ; ++i)
        for (int j=0; j < arrayToSort.getSize() - 1 - i; ++j){

            if (arrayToSort.getArrayPointer()[j + 1] < arrayToSort.getArrayPointer()[j])
                arrayToSort.swap(j, j + 1);

            /*// draw the array after each iteration
            arrayToSort.draw(backGroundUi.getWindow());
            backGroundUi.draw("0");        // draw all the backGround elements and display the screen*/
        }

    sortingFinished = true;
    return sortingFinished;    // successfully finished sorting
}


bool BubbleSort::sortOneIteration()
{
    if (counterOuterLoop < arrayToSort.getSize() - 1) {

        if (arrayToSort.getArrayPointer()[counterInnerLoop + 1] < arrayToSort.getArrayPointer()[counterInnerLoop])
            arrayToSort.swap(counterInnerLoop, counterInnerLoop + 1);

        // update the counters
        int oldCounterOuter = counterOuterLoop;     // temporarily store the old Counter of outer loop
        counterOuterLoop = counterOuterLoop + (counterInnerLoop + 1) / (arrayToSort.getSize() - 1 - counterOuterLoop);
        counterInnerLoop = (counterInnerLoop + 1) % (arrayToSort.getSize() - 1 - oldCounterOuter);

        return false;
    }

    return true;
}