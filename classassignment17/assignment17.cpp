#include "assignment17.h"

namespace methods {
    int linearSearch(const int* arr, size_t size, int target) {
        for (size_t i = 0; i < size; ++i) {
            if (*(arr + i) == target) {
                return i;
            }
        }
        return -1;
    }
}
