//
// Created by kshou on 2021/12/25.
//


// utility function that check if an array is sorted
bool sorted(const int* arr, int size)
{
    for (int i=0; i < size - 1; ++i)
        if (arr[i+1] > arr[i])
            return false;

    return true;
}