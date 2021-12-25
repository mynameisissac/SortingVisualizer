//
// Created by kshou on 2021/12/23.
//

#ifndef SORTINGVISUALIZER_SORTINGALGORITHM_H
#define SORTINGVISUALIZER_SORTINGALGORITHM_H

#include "Array.h"


// TODO : change to template
// abstract base class for all sorting algorithms
class SortingAlgorithm {
    protected:
        // a reference to the array object to be sorted
        Array<int>& arrayToSort;

    public:
        explicit SortingAlgorithm(Array<int>& arrayToSort);     // constructor
        virtual ~SortingAlgorithm();        // destructor

        // pure virtual overloaded operator() for performing the sorting of one iteration
        virtual void sortOneIteration() = 0;
};


#endif //SORTINGVISUALIZER_SORTINGALGORITHM_H
