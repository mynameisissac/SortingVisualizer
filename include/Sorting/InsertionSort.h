//
// Created by kshou on 2022/1/3.
//

#ifndef SORTINGVISUALIZER_INSERTIONSORT_H
#define SORTINGVISUALIZER_INSERTIONSORT_H

#include "SortingAlgorithm.h"

class InsertionSort : public SortingAlgorithm{
    private:
        // counter of the outer loop
        int stage;
        // counter of the inner loop(indicate which index of sorted portion is currently at)
        int searchingStage;
        // indicate whether the correct position to insert is found
        bool found;

    public:
        explicit InsertionSort(Array<int>& arrayToSort);

        void sort(BackGroundUI& backGroundUi) override;

        bool sortOneIteration() override;


};


#endif //SORTINGVISUALIZER_INSERTIONSORT_H
