//
// Created by kshou on 2021/12/23.
//

#include "SortingAlgorithm.h"


SortingAlgorithm::SortingAlgorithm(int* arrayToSort, int size)
    : arrayToSort(arrayToSort), size(size)              // perform shallow copy of the array pointer
{}

SortingAlgorithm::~SortingAlgorithm() = default;