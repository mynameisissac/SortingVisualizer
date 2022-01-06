//
// Created by kshou on 2022/1/5.
//

#include "Sorting/QuickSort.h"
#include "Engine.h"

QuickSort::QuickSort(Array<int>& arrayToSort)
    : SortingAlgorithm(arrayToSort)
{}


bool QuickSort::sortOneIteration()
{
    return false;
}

bool QuickSort::sort(Engine& engine)
{
    static bool sortingFinished = false;    // to prevent the sorting run on sorted array
    if (sortingFinished)
        return true;

    // call the recursive quickSort()
    quickSort(0, arrayToSort.getSize() - 1, engine);

    sortingFinished = true;
    return sortingFinished;
}

// Purpose of partition is to put the pivot element into correct position so that itself become sorted.
int QuickSort::partition(int low, int high, Engine& engine)
{
    int left = low - 1;
    int right = low;
    int pivot = arrayToSort.getArrayPointer()[high];      // choose last element as the pivot element

    for (; right < high; ++right)
        if (arrayToSort.getArrayPointer()[right] < pivot) {
            // increment left pointer and swap arr[left] and arr[right]
            ++left;
            arrayToSort.swap(left, right);      // to move all smaller(than pivot) element to the left

            // draw the array and handleInput
            handleInput(engine);
            engine.draw();
            // handle pausing
            while (PauseButton::isPaused())
                handleInput(engine);
        }

    arrayToSort.swap(left + 1, high);       // swap arr[left + 1] and arr[high](pivot element)

    // draw the array and handleInput
    handleInput(engine);
    engine.draw();
    // handle pausing
    while (PauseButton::isPaused())
        handleInput(engine);

    return left + 1;        // return the new position of the pivot element
}

void QuickSort::quickSort(int low, int high, Engine& engine)
{
    if (low >= high)        // base case
        return;

    // 3 steps of recursive quickSort()
    int parted_index = partition(low, high, engine);
    quickSort(low, parted_index - 1, engine);
    quickSort(parted_index + 1, high, engine);

}


