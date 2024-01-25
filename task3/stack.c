#include <stdio.h>
#include <stdlib.h>

#define INITIAL_CAPACITY 5

// Structure to represent the stack
typedef struct {
    int* array;   // Dynamic array to store stack elements
    int top;      // Index of the top element in the stack
    int capacity; // Capacity of the stack
} Stack;

// Function to initialize a stack
Stack* initializeStack() {
    Stack* stack = (Stack*)malloc(sizeof(Stack)); // Allocate memory for the stack structure
    stack->array = (int*)malloc(INITIAL_CAPACITY * sizeof(int)); // Allocate initial memory for the array
    stack->top = -1; // Initialize top index to -1 (empty stack)
    stack->capacity = INITIAL_CAPACITY; // Set the initial capacity
    return stack;
}

// Function to check if the stack is empty
int isEmpty(Stack* stack) {
    return stack->top == -1; // Stack is empty if top is -1
}

// Function to resize the stack (double the capacity)
void resize(Stack* stack) {
    stack->capacity *= 2;
    stack->array = realloc(stack->array, stack->capacity * sizeof(int)); // Resize the array
}

// Function to push an element onto the stack
void push(Stack* stack, int value) {
    if (stack->top == stack->capacity - 1) { // Check if the stack is full
        resize(stack); // Double the capacity if full
    }
    stack->array[++stack->top] = value; // Increment top and add the value
    printf("Pushed %d onto the stack.\n", value);
}

// Function to pop an element from the stack
int pop(Stack* stack) {
    if (isEmpty(stack)) { // Check if the stack is empty
        printf("Error: Stack underflow\n");
        exit(EXIT_FAILURE);
    }
    printf("Popped %d from the stack.\n", stack->array[stack->top]);
    return stack->array[stack->top--]; // Return and decrement top
}

// Function to peek at the top element without removing it
int peek(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Error: Stack is empty\n");
        exit(EXIT_FAILURE);
    }
    return stack->array[stack->top];
}

// Function to get the current number of elements in the stack
int size(Stack* stack) {
    return stack->top + 1; // Number of elements is top + 1
}

// Function to get the current capacity of the stack
int capacity(Stack* stack) {
    return stack->capacity;
}

// Function to print the elements of the stack
void printStack(Stack* stack) {
    if (isEmpty(stack)) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Stack (LIFO): ");
    for (int i = stack->top; i >= 0; i--) {
        printf("%d ", stack->array[i]);
    }
    printf("\n");
}

// Function to free the memory used by the stack
void freeStack(Stack* stack) {
    free(stack->array);
    free(stack);
}

// Main function
int main() {
    Stack* myStack = initializeStack(); // Initialize the stack
    int choice, value;

    do {
        printf("\nStack Menu:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Print Stack\n");
        printf("5. Check Size\n");
        printf("6. Check Capacity\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");

        // Check if the input is an integer
        if (scanf("%d", &choice) != 1) {
            printf("Invalid input. Please enter a number.\n");
            while (getchar() != '\n');  // Clear the input buffer
            continue;
        }

        switch (choice) {
            case 1:
                printf("Enter the value to push: ");
                // Check if the input is an integer
                if (scanf("%d", &value) != 1) {
                    printf("Invalid input for value. Please enter a number.\n");
                    while (getchar() != '\n');  // Clear the input buffer
                    continue;
                }
                push(myStack, value);
                break;
            case 2:
                pop(myStack);
                break;
            case 3:
                printf("Top element: %d\n", peek(myStack));
                break;
            case 4:
                printStack(myStack);
                break;
            case 5:
                printf("Stack size: %d\n", size(myStack));
                break;
            case 6:
                printf("Stack capacity: %d\n", capacity(myStack));
                break;
            case 7:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }

        // Clear the input buffer
        while (getchar() != '\n');

    } while (choice != 7);

    freeStack(myStack);

    return 0;
}
