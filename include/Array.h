//
// Created by kshou on 2021/12/25.
//

#ifndef SORTINGVISUALIZER_ARRAY_H
#define SORTINGVISUALIZER_ARRAY_H


// implementation of custom Array class type template
template <typename T>
class Array {
    private:
        T* arr;     // pointer to a dynamic array of type T
        int size;

    public:
        // TODO: implement them
        bool sorted() const;
        void printArray() const;

};


#endif //SORTINGVISUALIZER_ARRAY_H
