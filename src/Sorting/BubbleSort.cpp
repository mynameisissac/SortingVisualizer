//
// Created by kshou on 2021/12/31.
//

#include "Sorting/BubbleSort.h"


BubbleSort::BubbleSort(Array<int>& arrayToSort)
    : SortingAlgorithm(arrayToSort), counterInnerLoop(0), counterOuterLoop(0)
{}


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