//
// Created by kshou on 2021/12/23.
//

#include "Sorting/SortingAlgorithm.h"


SortingAlgorithm::SortingAlgorithm(Array<int>& arrayToSort, Engine* engine)
    : arrayToSort(arrayToSort)            // perform shallow copy of the array object
        , engine(engine)
    {}

SortingAlgorithm::~SortingAlgorithm() = default;