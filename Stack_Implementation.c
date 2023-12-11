#include <stdio.h>
#include <stdlib.h>

// Define maximum size of the stack
#define MAX_SIZE 100

// Structure to represent the stack
struct Stack {
    int items[MAX_SIZE];
    int top;
};

// Function to initialize an empty stack
void initialize(struct Stack* stack) {
    stack->top = -1;
}

// Function to check if the stack is empty
int isEmpty(struct Stack* stack) {
    return (stack->top == -1);
}

// Function to check if the stack is full
int isFull(struct Stack* stack, int n) {
    return (stack->top == n - 1);
}

// Function to push an element onto the stack
void push(struct Stack* stack, int value, int n) {
    if (isFull(stack, n)) {
        printf("Stack Overflow: Cannot push element onto a full stack.\n");
    } else {
        stack->items[++stack->top] = value;
        printf("%d pushed onto the stack.\n", value);
    }
}

// Function to pop an element from the stack
void pop(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack Underflow: Cannot pop element from an empty stack.\n");
    } else {
        printf("Popped element: %d\n", stack->items[stack->top--]);
    }
}

// Function to display the elements of the stack
void display(struct Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
    } else {
        printf("Stack elements: ");
        for (int i = 0; i <= stack->top; ++i) {
            printf("%d ", stack->items[i]);
        }
        printf("\n");
    }
}

int main() {
    struct Stack stack;
    int choice, value, n;

    printf("Enter the size of the stack: ");
    scanf("%d", &n);

    // Check if the provided size is within the valid range
    if (n <= 0 || n > MAX_SIZE) {
        printf("Invalid stack size. Please provide a size between 1 and %d.\n", MAX_SIZE);
        return 1;
    }

    initialize(&stack);

    do {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");

        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the element to push: ");
                scanf("%d", &value);
                push(&stack, value, n);
                break;
            case 2:
                pop(&stack);
                break;
            case 3:
                display(&stack);
                break;
            case 4:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 4);

    return 0;
}
