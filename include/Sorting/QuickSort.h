//
// Created by kshou on 2022/1/5.
//

#ifndef SORTINGVISUALIZER_QUICKSORT_H
#define SORTINGVISUALIZER_QUICKSORT_H

#include "SortingAlgorithm.h"

class QuickSort : public SortingAlgorithm{
    private:
        // partition function will be used for both recursive and iterative quickSort
        int partition(int low, int high);
        // recursive quickSort implementation for sort()
        void quickSort(int low, int high);

    public:
        explicit QuickSort(Array<int>& arrayToSort, Engine* engine);

        bool sort() override;

        bool sortOneIteration() override;
};


#endif //SORTINGVISUALIZER_QUICKSORT_H
