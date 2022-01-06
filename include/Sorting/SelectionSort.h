//
// Created by kshou on 2021/12/26.
//

#ifndef SORTINGVISUALIZER_SELECTIONSORT_H
#define SORTINGVISUALIZER_SELECTIONSORT_H

#include "SortingAlgorithm.h"

class SelectionSort : public SortingAlgorithm{
    private:
        // indicate which iteration(outer loop) is currently sort to
        int stage;
        // indicate the index of element currently comparing in findingMinIndex
        int searchingStage;
        // store the currently min index
        int currentMinIndex;

    public:
        explicit SelectionSort(Array<int>& arrayToSort, Engine* engine);    // constructor

        bool sortOneIteration() override;

        bool sort() override;
};


#endif //SORTINGVISUALIZER_SELECTIONSORT_H
