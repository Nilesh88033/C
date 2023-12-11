#include <stdio.h>

// Function to move a disk from source peg to destination peg
void moveDisk(char source, char destination, int diskNumber) { 
    printf("Move disk %d from %c to %c\n", diskNumber, source, destination);
}

// Function to solve Tower of Hanoi with n disks
void towerOfHanoi(int n, char source, char auxiliary, char destination) {
    if (n == 1) {
        moveDisk(source, destination, 1);
        return;
    }

    // Move (n-1) disks from source to auxiliary peg using destination peg
    towerOfHanoi(n - 1, source, destination, auxiliary);

    // Move the nth disk from source to destination peg
    moveDisk(source, destination, n);

    // Move (n-1) disks from auxiliary peg to destination peg using source peg
    towerOfHanoi(n - 1, auxiliary, source, destination);
}

int main() {
    int n;

    // Get the number of disks from the user
    printf("Enter the number of disks: ");
    scanf("%d", &n);

    // Check if the number of disks is valid
    if (n <= 0) {
        printf("Invalid number of disks. Please enter a positive integer.\n");
        return 1;
    }

    // Call the towerOfHanoi function to solve the problem
    printf("\nTower of Hanoi Solution:\n");
    towerOfHanoi(n, 'A', 'B', 'C');

    return 0;
}
