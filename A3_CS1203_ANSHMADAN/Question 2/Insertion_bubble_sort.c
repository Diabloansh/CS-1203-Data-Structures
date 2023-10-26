#include <stdio.h>
#include <stdlib.h> // Add this line to include the necessary header for srand
#include <time.h>

void insertionSort(int arr[], int n, int *comparisons, int *swaps) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key) {
            (*comparisons)++;
            arr[j + 1] = arr[j];
            (*swaps)++;
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

void bubbleSort(int arr[], int n, int *comparisons, int *swaps) {
    int i, j;
    for (i = 0; i < n - 1; i++) {
        for (j = 0; j < n - i - 1; j++) {
            (*comparisons)++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                (*swaps)++;
            }
        }
    }
}

int main() {
    srand(time(NULL)); // Add the missing parenthesis

    for (int n = 100; n <= 1000; n += 100) {
        double ccInsertion = 0.0, scInsertion = 0.0;
        double ccBubble = 0.0, scBubble = 0.0;

        for (int t = 0; t < 100; t++) {
            int arr[n];
            int arr1[n];

            for (int i = 0; i < n; i++) {
                arr[i] = rand() % 100;
                arr1[i] = arr[i];
            }

            int comparisonsInsertion = 0, swapsInsertion = 0;
            int comparisonsBubble = 0, swapsBubble = 0;

            insertionSort(arr, n, &comparisonsInsertion, &swapsInsertion);
            ccInsertion += comparisonsInsertion;
            scInsertion += swapsInsertion;

            bubbleSort(arr1, n, &comparisonsBubble, &swapsBubble);
            ccBubble += comparisonsBubble;
            scBubble += swapsBubble;
        }

        printf("Insertion Sort n = %6d, Comparisons %.2lf Swaps %.2lf\n", n, ccInsertion / 100, scInsertion / 100);
        printf("Bubble Sort n = %6d, Comparisons %.2lf Swaps %.2lf\n", n, ccBubble / 100, scBubble / 100);
        printf("----\n");
    }

    return 0;
}
