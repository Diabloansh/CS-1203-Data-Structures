#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to swap two elements
void swap(int* a, int* b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Function to check if an array is sorted
void checkIfSorted(int arr[], int size) {
    int i;
    for (i = 0; i < size - 1; i++) {
        if (arr[i] > arr[i + 1]) {
            printf("Error in sorting\n");
            exit(0);
        }
    }
}

// Function to perform Quick Sort and count comparisons and swaps
void quickSort(int arr[], int low, int high, int* comparisons, int* swaps) {
    if (low < high) {
        int pivot = arr[high];
        int i = low - 1;

        for (int j = low; j <= high - 1; j++) {
            (*comparisons)++;
            if (arr[j] < pivot) {
                i++;
                swap(&arr[i], &arr[j]);
                (*swaps)++;
            }
        }
        swap(&arr[i + 1], &arr[high]);
        (*swaps)++;
        int partitionIndex = i + 1;

        quickSort(arr, low, partitionIndex - 1, comparisons, swaps);
        quickSort(arr, partitionIndex + 1, high, comparisons, swaps);
    }
}

// Function to merge two sorted subarrays in Merge Sort
void merge(int arr[], int left, int mid, int right, int* comparisons, int* swaps) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int L[n1], R[n2];
    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int i = 0; i < n2; i++)
        R[i] = arr[mid + 1 + i];

    int i = 0;
    int j = 0;
    int k = left;

    while (i < n1 && j < n2) {
        (*comparisons)++;
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        (*swaps)++;
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}

// Function to perform Merge Sort and count comparisons and swaps
void mergeSort(int arr[], int left, int right, int* comparisons, int* swaps) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        mergeSort(arr, left, mid, comparisons, swaps);
        mergeSort(arr, mid + 1, right, comparisons, swaps);

        merge(arr, left, mid, right, comparisons, swaps);
    }
}

// Function to heapify a subtree rooted at given index
void heapify(int arr[], int n, int i, int* comparisons, int* swaps) {
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    (*comparisons)++;
    if (left < n && arr[left] > arr[largest]) {
        largest = left;
    }

    (*comparisons)++;
    if (right < n && arr[right] > arr[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(&arr[i], &arr[largest]);
        (*swaps)++;
        heapify(arr, n, largest, comparisons, swaps);
    }
}

// Function to perform Heap Sort and count comparisons and swaps
void heapSort(int arr[], int n, int* comparisons, int* swaps) {
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i, comparisons, swaps);
    }

    for (int i = n - 1; i > 0; i--) {
        swap(&arr[0], &arr[i]);
        (*swaps)++;
        heapify(arr, i, 0, comparisons, swaps);
    }
}

int main() {
    int arr[1000], arr1[1000], arr2[1000];
    int n = 100, i = 0, t;
    double ccQuick, scQuick;
    double ccMerge, scMerge;
    double ccHeap, scHeap;

    srand(time(NULL));

    for (n = 100; n <= 1000; n = n + 100) {
        ccQuick = 0.0, scQuick = 0.0;
        ccMerge = 0.0, scMerge = 0.0;
        ccHeap = 0.0, scHeap = 0.0;

        for (t = 0; t < 100; t++) {
            for (i = 0; i < n; i++) {
                arr[i] = rand() % 100;
                arr1[i] = arr[i];
                arr2[i] = arr[i];
            }

            int comparisonsQuick = 0, swapsQuick = 0;
            int comparisonsMerge = 0, swapsMerge = 0;
            int comparisonsHeap = 0, swapsHeap = 0;

            quickSort(arr, 0, n - 1, &comparisonsQuick, &swapsQuick);
            ccQuick += (double)comparisonsQuick;
            scQuick += (double)swapsQuick;

            mergeSort(arr1, 0, n - 1, &comparisonsMerge, &swapsMerge);
            ccMerge += (double)comparisonsMerge;
            scMerge += (double)swapsMerge;

            heapSort(arr2, n, &comparisonsHeap, &swapsHeap);
            ccHeap += (double)comparisonsHeap;
            scHeap += (double)swapsHeap;

            checkIfSorted(arr, n);
            checkIfSorted(arr1, n);
            checkIfSorted(arr2, n);
        }

        printf("Quick Sort n = %6d, Comparisons %.2lf Swaps %.2lf\n", n, ccQuick / 100, scQuick / 100);
        printf("Merge Sort n = %6d, Comparisons %.2lf Swaps %.2lf\n", n, ccMerge / 100, scMerge / 100);
        printf("Heap Sort n = %6d, Comparisons %.2lf Swaps %.2lf\n", n, ccHeap / 100, scHeap / 100);
        printf("----\n");
    }
    return 0;
}
