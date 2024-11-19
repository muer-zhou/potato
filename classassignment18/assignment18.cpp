#include "assignment18.h"

namespace methods {
    void sortArray(int* arr, size_t size) {
        for (size_t i = 0; i < size - 1; ++i) {
            for (size_t j = 0; j < size - i - 1; ++j) {
                if (*(arr + j) > *(arr + j + 1)) { // Compare adjacent elements
                    // Swap using a temporary variable
                    int temp = *(arr + j);
                    *(arr + j) = *(arr + j + 1);
                    *(arr + j + 1) = temp;
                }
            }
        }
    }
}
