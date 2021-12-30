//
// Created by kshou on 2021/12/23.
//

#include "Sorting/SortingAlgorithm.h"


SortingAlgorithm::SortingAlgorithm(Array<int>& arrayToSort)
    : arrayToSort(arrayToSort)              // perform shallow copy of the array object
{}

SortingAlgorithm::~SortingAlgorithm() = default;