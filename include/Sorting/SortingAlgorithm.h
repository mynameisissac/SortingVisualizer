//
// Created by kshou on 2021/12/23.
//

#ifndef SORTINGVISUALIZER_SORTINGALGORITHM_H
#define SORTINGVISUALIZER_SORTINGALGORITHM_H

#include "Array.h"
#include "BackGroundUI.h"

// TODO : change to template?
// abstract base class for all sorting algorithms
class SortingAlgorithm {
    protected:
        // a reference to the array object to be sorted
        Array<int>& arrayToSort;

    public:
        explicit SortingAlgorithm(Array<int>& arrayToSort);     // constructor
        virtual ~SortingAlgorithm();        // destructor

        virtual bool sort(BackGroundUI& backGroundUi) = 0;

        // pure virtual function for performing the sorting of one iteration
        // it returns true if whole sorting process is finished
        virtual bool sortOneIteration() = 0;

};


#endif //SORTINGVISUALIZER_SORTINGALGORITHM_H
