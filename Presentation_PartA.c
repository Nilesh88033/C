#include <stdio.h>
#include <math.h>


//Identify a given number is odd, even, prime, palindrome, armstrong


// Function to check if a number is prime
int isPrime(int num) {
    if (num <= 1) {
        return 0; // Not a prime number
    }
    for (int i = 2; i <= sqrt(num); i++) {
        if (num % i == 0) {
            return 0; // Not a prime number
        }
    }
    return 1; // Prime number
}

// Function to check if a number is palindrome
int isPalindrome(int num) {
    int originalNum = num;
    int reversedNum = 0;

    while (num > 0) {
        int digit = num % 10;
        reversedNum = reversedNum * 10 + digit;
        num /= 10;
    }

    return originalNum == reversedNum;
}

// Function to check if a number is Armstrong
int isArmstrong(int num) {
    int originalNum = num;
    int numDigits = 0;
    int sum = 0;

    while (num > 0) {
        numDigits++;
        num /= 10;
    }

    num = originalNum;

    while (num > 0) {
        int digit = num % 10;
        sum += pow(digit, numDigits);
        num /= 10;
    }

    return originalNum == sum;
}

int main() {
    int choice, num;

    do {
        printf("\nMenu:\n");
        printf("1. Check if the number is odd\n");
        printf("2. Check if the number is even\n");
        printf("3. Check if the number is prime\n");
        printf("4. Check if the number is palindrome\n");
        printf("5. Check if the number is Armstrong\n");
        printf("6. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter a number: ");
                scanf("%d", &num);
                if (num % 2 == 1) {
                    printf("%d is odd.\n", num);
                } else {
                    printf("%d is not odd.\n", num);
                }
                break;
            case 2:
                printf("Enter a number: ");
                scanf("%d", &num);
                if (num % 2 == 0) {
                    printf("%d is even.\n", num);
                } else {
                    printf("%d is not even.\n", num);
                }
                break;
            case 3:
                printf("Enter a number: ");
                scanf("%d", &num);
                if (isPrime(num)) {
                    printf("%d is prime.\n", num);
                } else {
                    printf("%d is not prime.\n", num);
                }
                break;
            case 4:
                printf("Enter a number: ");
                scanf("%d", &num);
                if (isPalindrome(num)) {
                    printf("%d is palindrome.\n", num);
                } else {
                    printf("%d is not palindrome.\n", num);
                }
                break;
            case 5:
                printf("Enter a number: ");
                scanf("%d", &num);
                if (isArmstrong(num)) {
                    printf("%d is Armstrong.\n", num);
                } else {
                    printf("%d is not Armstrong.\n", num);
                }
                break;
            case 6:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

    } while (choice != 6);

    return 0;
}
