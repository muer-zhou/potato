#include "assignment19.h"

namespace methods {
    void swap(int* a, int* b) {
        int temp = *a;  // Store the value of a in temp
        *a = *b;        // Assign the value of b to a
        *b = temp;      // Assign the value of temp (original a) to b
    }
}
