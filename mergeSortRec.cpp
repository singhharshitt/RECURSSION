#include <iostream>
using namespace std;

// Function to merge two halves of an array
void merge(int arr[], int l, int mid, int r) {
    // Calculate sizes of the two subarrays to be merged
    int n1 = mid - l + 1;
    int n2 = r - mid;

    // Create temporary arrays to hold the two halves
    int arr1[n1], arr2[n2];

    // Copy data to temporary arrays arr1 and arr2
    for (int i = 0; i < n1; i++) {
        arr1[i] = arr[l + i]; // Copy the left half
    }
    for (int i = 0; i < n2; i++) {
        arr2[i] = arr[mid + 1 + i]; // Copy the right half
    }

    // Merge the two temporary arrays back into the original array
    int i = 0; // Initial index of first subarray
    int j = 0; // Initial index of second subarray
    int k = l; // Initial index of merged subarray

    // Merge elements from arr1 and arr2 into arr
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            arr[k] = arr1[i]; // Take element from arr1 if it is smaller
            i++;
        } else {
            arr[k] = arr2[j]; // Take element from arr2 if it is smaller
            j++;
        }
        k++;
    }

    // Copy the remaining elements of arr1 (if any)
    while (i < n1) {
        arr[k] = arr1[i];
        i++;
        k++;
    }

    // Copy the remaining elements of arr2 (if any)
    while (j < n2) {
        arr[k] = arr2[j];
        j++;
        k++;
    }
}

// Recursive function to perform merge sort
void mergesort(int arr[], int l, int r) {
    if (l < r) {
        // Find the middle point
        int mid = l + (r - l) / 2;

        // Recursively sort the first half
        mergesort(arr, l, mid);

        // Recursively sort the second half
        mergesort(arr, mid + 1, r);

        // Merge the two sorted halves
        merge(arr, l, mid, r);
    }
}

int main() {
    int n;
    cout << "Enter number of elements: ";
    cin >> n;

    // Declare the array
    int arr[n];

    // Input the array elements
    cout << "Enter the elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    // Call merge sort on the array
    mergesort(arr, 0, n - 1);

    // Output the sorted array
    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
