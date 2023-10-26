#include <stdio.h>

// Function to move a single disk from one rod to another and count swaps
void moveDisk(int disk, char from_rod, char to_rod, int *swaps) {
    printf("Move disk %d from rod %c to rod %c\n", disk, from_rod, to_rod);
    (*swaps)++;
}

// Recursive function to solve the Tower of Hanoi problem and count swaps
void towerOfHanoi(int n, char source_rod, char destination_rod, char auxiliary_rod, int *swaps) {
    // Base case: If there is only one disk, move it directly from source to destination
    if (n == 1) {
        moveDisk(1, source_rod, destination_rod, swaps);
        return;
    }

    // Move the top (n-1) disks from the source rod to the auxiliary rod using the destination rod as the auxiliary
    towerOfHanoi(n - 1, source_rod, auxiliary_rod, destination_rod, swaps);

    // Move the nth disk from the source rod to the destination rod
    moveDisk(n, source_rod, destination_rod, swaps);

    // Move the (n-1) disks from the auxiliary rod to the destination rod using the source rod as the auxiliary
    towerOfHanoi(n - 1, auxiliary_rod, destination_rod, source_rod, swaps);
}

int main() {
    int n;
    printf("Enter the number of disks: ");
    scanf("%d", &n); // Input the number of disks

    int swaps = 0; // Variable to count the number of swaps
    towerOfHanoi(n, 'A', 'C', 'B', &swaps); // 'A', 'B', and 'C' represent the names of the rods

    printf("Total number of disk swaps: %d\n", swaps);

    return 0;
}
