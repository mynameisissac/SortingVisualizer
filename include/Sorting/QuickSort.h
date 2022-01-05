//
// Created by kshou on 2022/1/5.
//

#ifndef SORTINGVISUALIZER_QUICKSORT_H
#define SORTINGVISUALIZER_QUICKSORT_H

#include "SortingAlgorithm.h"

class QuickSort : public SortingAlgorithm{
    private:
        // recursive quickSort implementation for sort()
        int partition(int low, int high);
        void quickSort(int low, int high, BackGroundUI& backGroundUi);

    public:
        explicit QuickSort(Array<int>& arrayToSort);

        bool sort(BackGroundUI& backGroundUi) override;

        bool sortOneIteration() override;

};


#endif //SORTINGVISUALIZER_QUICKSORT_H
