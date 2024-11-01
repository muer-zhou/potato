// ArrayUtils.cpp
#include <iostream>
#include "assignment20.h"

namespace ArrayOps {
    int* expand(int *oldArr, int oldSize, int newSize) {
        int *newArr = new int[newSize];
        for (int i = 0; i < oldSize; i++) {
            newArr[i] = oldArr[i];
        }
        for (int i = oldSize; i < newSize; i++) {
            newArr[i] = 0;
        }
        delete[] oldArr;
        oldArr = nullptr;
        return newArr;
    }

    void printArray(int *arr, int size) {
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << std::endl;
        }
    }
}
