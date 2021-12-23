//
// Created by kshou on 2021/12/23.
//

#ifndef SORTINGVISUALIZER_BOGOSORT_H
#define SORTINGVISUALIZER_BOGOSORT_H
#include "SortingAlgorithm.h"

// function object class
class BogoSort : public SortingAlgorithm{

    public:
        BogoSort(int* arr, int size);
        void sortOneIteration() override;
};


#endif //SORTINGVISUALIZER_BOGOSORT_H
