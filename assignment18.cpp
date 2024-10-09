#include <iostream>

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; ++i) {
        if (arr[i] == target) {
            return i;  
        }
    }
    return -1; 
}

int main() {
    int arr[] = {10, 25, 30, 45, 50};
    int size = sizeof(arr) / sizeof(arr[0]);
    int target = 45;

    int index = linearSearch(arr, size, target);

    if (index != -1) {
        std::cout << "Target " << target << " found at index " << index << std::endl;
    } else {
        std::cout << "Target " << target << " not found in the array." << std::endl;
    }

    return 0;
}
