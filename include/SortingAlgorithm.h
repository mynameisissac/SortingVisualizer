//
// Created by kshou on 2021/12/23.
//

#ifndef SORTINGVISUALIZER_SORTINGALGORITHM_H
#define SORTINGVISUALIZER_SORTINGALGORITHM_H

// abstract base class for all sorting function object class
class SortingAlgorithm {
    protected:
        int* arrayToSort;
        int size;       // size of the array to be sorted

    public:
        SortingAlgorithm(int* arrayToSort, int size);     // constructor
        virtual ~SortingAlgorithm();        // destructor

        // pure virtual overloaded operator() for performing the sorting of one iteration
        virtual void sortOneIteration() = 0;
};


#endif //SORTINGVISUALIZER_SORTINGALGORITHM_H
