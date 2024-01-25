#include <stdio.h>
#include <stdlib.h>

// Define the dynamic array structure
typedef struct {
    int* array;
    size_t size;
    size_t capacity;
} DynamicArray;

// avelacnel capacity
void initializeArray(DynamicArray* arr, size_t initialCapacity) {
    arr->array = (int*)malloc(initialCapacity * sizeof(int));
    if (arr->array == NULL) {
        fprintf(stderr, "Memory allocation failed\n");
        exit(EXIT_FAILURE);
    }
    arr->size = 0;
    arr->capacity = initialCapacity;
}

// resize arr
void resizeArray(DynamicArray* arr) {
    if (arr->size == arr->capacity) {
        arr->capacity *= 2;
    } else if (arr->size < arr->capacity / 4 && arr->capacity > 2) {
        arr->capacity /= 2;
    }

    arr->array = (int*)realloc(arr->array, arr->capacity * sizeof(int));
    if (arr->array == NULL) {
        fprintf(stderr, "Memory reallocation failed\n");
        exit(EXIT_FAILURE);
    }
}

// arr verjic heto avelacnel
void insertElement(DynamicArray* arr, int value) {
    if (arr->size == arr->capacity) {
        resizeArray(arr);
    }
    arr->array[arr->size++] = value;
}

// avelacnel indexov
void insertAtIndex(DynamicArray* arr, size_t index, int value) {
    if (index <= arr->size) {
        if (arr->size == arr->capacity) {
            resizeArray(arr);
        }

        for (size_t i = arr->size; i > index; --i) {
            arr->array[i] = arr->array[i - 1];
        }

        arr->array[index] = value;
        arr->size++;
    } else {
        fprintf(stderr, "Index out of bounds\n");
    }
}

// jnjel indexov
void removeByIndex(DynamicArray* arr, size_t index) {
    if (index < arr->size) {
        for (size_t i = index; i < arr->size - 1; ++i) {
            arr->array[i] = arr->array[i + 1];
        }
        arr->size--;

        
        resizeArray(arr);
    } else {
        fprintf(stderr, "Index out of bounds\n");
    }
}

// jnjel indexov
void removeByValue(DynamicArray* arr, int value) {
    size_t i = 0;
    while (i < arr->size && arr->array[i] != value) {
        i++;
    }
    if (i < arr->size) {
        removeByIndex(arr, i);
    }
}

// hasaneliutyun indexov
int getElement(DynamicArray* arr, size_t index) {
    if (index < arr->size) {
        return arr->array[index];
    } else {
        fprintf(stderr, "Index out of bounds\n");
        exit(EXIT_FAILURE);
    }
}

//size
size_t getSize(DynamicArray* arr) {
    return arr->size;
}

// length
size_t getCapacity(DynamicArray* arr) {
    return arr->capacity;
}

// azatel hishoxutyuny
void freeArray(DynamicArray* arr) {
    free(arr->array);
    arr->array = NULL;
    arr->size = 0;
    arr->capacity = 0;
}

// sort bubble-i logicov
void sortArray(DynamicArray* arr) {
    for (size_t i = 0; i < arr->size - 1; ++i) {
        for (size_t j = 0; j < arr->size - i - 1; ++j) {
            if (arr->array[j] > arr->array[j + 1]) {
                int temp = arr->array[j];
                arr->array[j] = arr->array[j + 1];
                arr->array[j + 1] = temp;
            }
        }
    }
}

// menu
void displayMenu() {
    printf("\nMenu:\n");
    printf("1. Initialize Array\n");
    printf("2. Push Element\n");
    printf("3. Delete Element by Index\n");
    printf("4. Delete Element by Value\n");
    printf("5. Access Element by Index\n");
    printf("6. Get Current Size\n");
    printf("7. Get Capacity\n");
    printf("8. Sort Array\n");
    printf("9. Display Array\n");
    printf("10. Exit\n");
    printf("Enter your choice: ");
}

// operations
void performOperation(DynamicArray* arr, int choice) {
    int value;
    size_t index;
    switch (choice) {
        case 1:
            printf("Enter the initial capacity: ");
            scanf("%lu", &index);
            initializeArray(arr, index);
            printf("Array initialized with capacity %lu\n", index);
            break;
        case 2:
            printf("Enter the element to push: ");
            scanf("%d", &value);
            insertElement(arr, value);
            printf("Element %d pushed to the array.\n", value);
            break;
        case 3:
            printf("Enter the index to delete: ");
            scanf("%lu", &index);
            removeByIndex(arr, index);
            printf("Element at index %lu deleted.\n", index);
            break;
        case 4:
            printf("Enter the value to delete: ");
            scanf("%d", &value);
            removeByValue(arr, value);
            printf("Element %d deleted from the array.\n", value);
            break;
        case 5:
            printf("Enter the index to access: ");
            scanf("%lu", &index);
            printf("Element at index %lu: %d\n", index, getElement(arr, index));
            break;
        case 6:
            printf("Current size of the array: %zu\n", getSize(arr));
            break;
        case 7:
            printf("Capacity of the array: %zu\n", getCapacity(arr));
            break;
        case 8:
            sortArray(arr);
            printf("Array sorted.\n");
            break;
        case 9:
            printf("Current array: ");
            for (size_t i = 0; i < getSize(arr); ++i) {
                printf("%d ", getElement(arr, i));
            }
            printf("\n");
            break;
        case 10:
            printf("Exiting the program.\n");
            freeArray(arr);
            exit(EXIT_SUCCESS);
        default:
            printf("Invalid choice. Please enter a number between 1 and 10.\n");
    }
}

int main() {
    DynamicArray myArray;

    int choice;
    do {
        displayMenu();
        scanf("%d", &choice);
        performOperation(&myArray, choice);
    } while (1);

    return 0;
}
