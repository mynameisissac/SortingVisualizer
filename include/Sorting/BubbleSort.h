//
// Created by kshou on 2021/12/31.
//

#ifndef SORTINGVISUALIZER_BUBBLESORT_H
#define SORTINGVISUALIZER_BUBBLESORT_H

#include "SortingAlgorithm.h"

class BubbleSort : public SortingAlgorithm{

    private:
        // counters of outer loop and inner loop of bubble sort for recording the progress of sorting
        int counterOuterLoop;
        int counterInnerLoop;

    public:
        explicit BubbleSort(Array<int>& arrayToSort, Engine* engine);    // constructor

        bool sortOneIteration() override;

        bool sort() override;
};


#endif //SORTINGVISUALIZER_BUBBLESORT_H
