#include <stdio.h>

// Function to print the current permutation
void printPermutation(int n, int permutation[]) {
    for (int i = 0; i < n; i++) {
        printf("%d ", permutation[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Enter an integer n (1 <= n <= 8): ");
    scanf("%d", &n);

    if (n < 1 || n > 8) {
        printf("Invalid input. n must be between 1 and 8.\n");
        return 1;
    }

    int permutation[8];
    int factorial = 1;

    // Initialize the permutation array and calculate n factorial
    for (int i = 1; i <= n; i++) {
        permutation[i - 1] = i;
        factorial *= i;
    }

    for (int count = 0; count < factorial; count++) {
        printPermutation(n, permutation);

        int i = n - 1;
        while (i > 0 && permutation[i - 1] > permutation[i]) {
            i--;
        }

        if (i == 0) {
            break; // All permutations have been generated
        }

        int j = n - 1;
        while (permutation[j] < permutation[i - 1]) {
            j--;
        }

        // Swap permutation[i-1] and permutation[j]
        int temp = permutation[i - 1];
        permutation[i - 1] = permutation[j];
        permutation[j] = temp;

        // Reverse the elements from i to n-1
        int left = i;
        int right = n - 1;
        while (left < right) {
            temp = permutation[left];
            permutation[left] = permutation[right];
            permutation[right] = temp;
            left++;
            right--;
        }
    }

    return 0;
}
