//
// Created by kshou on 2021/12/31.
//

#include "Sorting/BubbleSort.h"

BubbleSort::BubbleSort(Array<int>& arrayToSort)
    : SortingAlgorithm(arrayToSort), counterInnerLoop(0), counterOuterLoop(0)
{}


void BubbleSort::sort(BackGroundUI& backGroundUi)
{
    static bool oneCycleFinished = false;

    if (oneCycleFinished)
        return;

    for (int i=0; i < arrayToSort.getSize() - 1 ; ++i)
        for (int j=0; j < arrayToSort.getSize() - 1 - i; ++j){

            if (arrayToSort.getArrayPointer()[j + 1] < arrayToSort.getArrayPointer()[j])
                arrayToSort.swap(j, j + 1);

            // draw the array after each iteration
            arrayToSort.draw(backGroundUi.getWindow());
            backGroundUi.draw();        // draw all the backGround elements and display the screen
        }

    oneCycleFinished = true;

}


void BubbleSort::sortOneIteration()
{
    if (counterOuterLoop < arrayToSort.getSize() - 1) {

        if (arrayToSort.getArrayPointer()[counterInnerLoop + 1] < arrayToSort.getArrayPointer()[counterInnerLoop])
            arrayToSort.swap(counterInnerLoop, counterInnerLoop + 1);

        // update the counters
        int oldCounterOuter = counterOuterLoop;     // temporarily store the old Counter of outer loop
        counterOuterLoop = counterOuterLoop + (counterInnerLoop + 1) / (arrayToSort.getSize() - 1 - counterOuterLoop);
        counterInnerLoop = (counterInnerLoop + 1) % (arrayToSort.getSize() - 1 - oldCounterOuter);

    }

}