//
// Created by kshou on 2021/12/23.
//

#ifndef SORTINGVISUALIZER_BOGOSORT_H
#define SORTINGVISUALIZER_BOGOSORT_H

#include "SortingAlgorithm.h"


class BogoSort : public SortingAlgorithm {

    public:
        explicit BogoSort(Array<int>& arrayToSort, Engine* engine);

        // this shuffleArray function can be reused by class members and others classes
        static void shuffleArray(int* arr, int size);

        bool sortOneIteration() override;

        bool sort() override;       // TODO
};


#endif //SORTINGVISUALIZER_BOGOSORT_H
