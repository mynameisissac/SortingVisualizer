//
// Created by kshou on 2021/12/26.
//

#ifndef SORTINGVISUALIZER_SELECTIONSORT_H
#define SORTINGVISUALIZER_SELECTIONSORT_H

#include "SortingAlgorithm.h"

class SelectionSort : public SortingAlgorithm{
    private:
        // indicate which iteration is currently sort to
        int stage;

    public:
        explicit SelectionSort(Array<int>& arrayToSort);    // constructor

        void sortOneIteration() override;

        void sort(BackGroundUI& backGroundUi) override;
};


#endif //SORTINGVISUALIZER_SELECTIONSORT_H
