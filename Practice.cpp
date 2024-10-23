

#include <iostream>
using namespace std;

int c = 0;

void merge(int arr[], int left, int mid, int right) {
    // Calculating the size of two sub-arrays
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int arr1[n1], arr2[n2];

    // Copying the data into these sub-arrays
    for (int i = 0; i < n1; i++) {
        arr1[i] = arr[left + i];
    }
    for (int i = 0; i < n2; i++) {
        arr2[i] = arr[mid + 1 + i];
    }

    // Merging the two sub-arrays back into arr[]
    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (arr1[i] <= arr2[j]) {
            arr[k++] = arr1[i++];
        } else {
            arr[k++] = arr2[j++];
        }
    }

    // Copying remaining elements of arr1[], if any
    while (i < n1) {
        arr[k++] = arr1[i++];
    }

    // Copying remaining elements of arr2[], if any
    while (j < n2) {
        arr[k++] = arr2[j++];
    }
}

void merge_sort(int arr[], int left, int right, int n) {
    if (left >= right) {
        return;  // Base condition: stop recursion when sub-array has one element
    }

    int mid = left + (right - left) / 2;

    // Recursively sorting the first and second halves
    merge_sort(arr, left, mid, n);
    merge_sort(arr, mid + 1, right, n);

    // Merging the sorted halves
    merge(arr, left, mid, right);

    // Outputting the array after each iteration
    cout << "After iteration " << c++ << " : " << endl;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    int n;
    cout << "Number of elements the array is containing: ";
    cin >> n;
    int arr[n];

    cout << "Enter the array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    merge_sort(arr, 0, n - 1, n);

    cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

    return 0;
}
