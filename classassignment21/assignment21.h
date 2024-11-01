// assignment21.h
#ifndef ASSIGNMENT21_H
#define ASSIGNMENT21_H

#include <memory>

namespace ArrayOps {
    std::shared_ptr<int[]> expand(std::shared_ptr<int[]> &oldArr, int oldSize, int newSize);
    void printArray(std::shared_ptr<int[]> &arr, int size);
}

#endif // ASSIGNMENT21_H
