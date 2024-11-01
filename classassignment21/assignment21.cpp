// assignment20.cpp
#include <iostream>
#include "assignment21.h"

namespace ArrayOps {
    std::shared_ptr<int[]> expand(std::shared_ptr<int[]> &oldArr, int oldSize, int newSize) {
        std::shared_ptr<int[]> newArr(new int[newSize]);
        for (int i = 0; i < oldSize; i++) {
            newArr[i] = oldArr[i];
        }
        for (int i = oldSize; i < newSize; i++) {
            newArr[i] = 0;
        }
        return newArr;
    }

    void printArray(std::shared_ptr<int[]> &arr, int size) {
        for (int i = 0; i < size; i++) {
            std::cout << arr[i] << std::endl;
        }
    }
}
