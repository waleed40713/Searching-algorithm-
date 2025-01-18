#include <iostream>
#include <vector>
using namespace std;

// Function for Binary Search
int binarySearch(const vector<int>& arr, int target, int& comparisons) {
    int low = 0, high = arr.size() - 1;
    comparisons = 0; // Count the number of comparisons
    while (low <= high) {
        int mid = low + (high - low) / 2;
        comparisons++;
        if (arr[mid] == target)
            return mid; // Target found
        else if (arr[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1; // Target not found
}

// Function for Linear Search
int linearSearch(const vector<int>& arr, int target, int& comparisons) {
    comparisons = 0; // Count the number of comparisons
    for (int i = 0; i < arr.size(); i++) {
        comparisons++;
        if (arr[i] == target)
            return i; // Target found
    }
    return -1; // Target not found
}

int main() {
    vector<int> sortedArray = {1, 3, 5, 7, 9, 11, 13, 15}; // Sorted array for Binary Search
    vector<int> unsortedArray = {15, 3, 7, 11, 1, 13, 5, 9}; // Unsorted array for Linear Search

    int target, comparisons;

    // Binary Search Example
    cout << "Enter the target value for Binary Search: ";
    cin >> target;

    int binaryResult = binarySearch(sortedArray, target, comparisons);
    if (binaryResult != -1)
        cout << "Binary Search: Target found at index " << binaryResult << " with " << comparisons << " comparisons.\n";
    else
        cout << "Binary Search: Target not found. Comparisons made: " << comparisons << ".\n";

    // Linear Search Example
    cout << "Enter the target value for Linear Search: ";
    cin >> target;

    int linearResult = linearSearch(unsortedArray, target, comparisons);
    if (linearResult != -1)
        cout << "Linear Search: Target found at index " << linearResult << " with " << comparisons << " comparisons.\n";
    else
        cout << "Linear Search: Target not found. Comparisons made: " << comparisons << ".\n";

    // Worst Case Demonstration for Binary Search
    cout << "\nWorst case for Binary Search: Target value not in the sorted list.\n";
    target = 16; // Example of a target not in the list
    binaryResult = binarySearch(sortedArray, target, comparisons);
    cout << "Binary Search: Target not found. Comparisons made: " << comparisons << ".\n";

    return 0;
}
