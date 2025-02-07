#include <iostream>
#include <vector>

int FindMaxValue(int array[], int arrLength) {
    int MaxValue = array[0]; // Initialize with the first element
    for (int i = 1; i < arrLength; i++) {
        if (array[i] > MaxValue) {
            MaxValue = array[i];
        }
    }
    return MaxValue;
}

void CountSort(int array[], int arrLength, int exp) {
    const int n = arrLength;

    std::vector<int> count(10, 0); // Only 10 digits
    std::vector<int> output(n);

    // Count occurrences of digits
    for (int i = 0; i < n; i++) {
        count[(array[i] / exp) % 10]++;
    }

    // Cumulative sum of counts
    for (int i = 1; i < 10; i++) {
        count[i] += count[i - 1];
    }

    // Place the elements in the output array
    for (int i = n - 1; i >= 0; i--) {
        output[count[(array[i] / exp) % 10] - 1] = array[i];
        count[(array[i] / exp) % 10]--;
    }

    // Copy the sorted array back to the original
    for (int i = 0; i < n; i++) {
        array[i] = output[i];
    }
}

void RadixSort(int arr[], int n, int MaxValue) {
    // Perform counting sort for every digit (ones, tens, hundreds, etc.)
    for (int exp = 1; MaxValue / exp > 0; exp *= 10) {
        CountSort(arr, n, exp);
    }
}

int main() {
    int arrayToSort[10] = { 0, 13, 5, 11, 20, 9, 8, 6, 7, 4 };
    const int arrLength = sizeof(arrayToSort) / sizeof(arrayToSort[0]);
    const int maxV = FindMaxValue(arrayToSort, arrLength);

    std::cout << "array before sort \n";
    for (int i = 0; i < 10; i++) {
        std::cout << arrayToSort[i] << " ";
    }
    std::cout << std::endl;

    RadixSort(arrayToSort, arrLength, maxV);

    std::cout << "array after sort \n";
    for (int i = 0; i < 10; i++) {
        std::cout << arrayToSort[i] << " ";
    }
}
