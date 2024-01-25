#include <stdio.h>
#include <stdlib.h>


char *intToBinary(int num);

int isValidNumberSystem(int system) {
    return (system == 2 || system == 10 || system == 16);
}

int isValidNumberForSystem(const char *input, int system) {
    if (system == 2) {
        for (int i = 0; input[i] != '\0'; i++) {
            if (input[i] != '0' && input[i] != '1') {
                return 0;
            }
        }
    } else if (system == 10) {
        for (int i = 0; input[i] != '\0'; i++) {
            if (input[i] < '0' || input[i] > '9') {
                return 0;
            }
        }
    } else if (system == 16) {
        for (int i = 0; input[i] != '\0'; i++) {
            if (!((input[i] >= '0' && input[i] <= '9') || (input[i] >= 'A' && input[i] <= 'F') || (input[i] >= 'a' && input[i] <= 'f'))) {
                return 0;
            }
        }
    }

    return 1;
}

void printBinaryFormat(int number) {
    printf("Binary format: 0b%.*s\n", (int)(sizeof(int) * 8), intToBinary(number));
}

void printHexadecimalFormat(int number) {
    printf("Hexadecimal format: 0x%X\n", number);
}

void printNumberFormat(int number, int system) {
    if (system == 2) {
        printBinaryFormat(number);
    } else if (system == 10) {
        printf("Decimal format: %d\n", number);
    } else if (system == 16) {
        printHexadecimalFormat(number);
    }
}

char *intToBinary(int num) {
    static char binary[sizeof(int) * 8 + 1];
    for (int i = sizeof(int) * 8 - 1; i >= 0; --i) {
        binary[sizeof(int) * 8 - 1 - i] = ((num >> i) & 1) ? '1' : '0';
    }
    binary[sizeof(int) * 8] = '\0';
    return binary;
}

int convertToDecimal(const char *input, int system) {
    return strtol(input, NULL, system);
}

int performBitwiseOperation(int operation, int num1, int num2) {
    switch (operation) {
        case 1:
            printf("Result of AND: ");
            return num1 & num2;
        case 2:
            printf("Result of OR: ");
            return num1 | num2;
        case 3:
            printf("Result of XOR: ");
            return num1 ^ num2;
        case 4:
            printf("Result of NOR: ");
            return ~(num1 | num2);
        case 5:
            printf("Result of Left Shift: ");
            return num1 << num2;
        case 6:
            printf("Result of Right Shift: ");
            return num1 >> num2;
        default:
            return 0;
    }
}

int getNumberSystemFromUser(const char *prompt) {
    int system;
    char inputBuffer[100];

    do {
        printf("%s", prompt);
        scanf("%s", inputBuffer);

        if (sscanf(inputBuffer, "%d", &system) != 1 || !isValidNumberSystem(system)) {
            printf("Invalid number system. Please enter a correct number system.\n");
        }

    } while (!isValidNumberSystem(system));

    return system;
}

void bitwiseCalculator() {
    int inputSystem, outputSystem;

    inputSystem = getNumberSystemFromUser("Enter the input number system (2 for binary, 10 for decimal, 16 for hexadecimal): ");
    outputSystem = getNumberSystemFromUser("Enter the output number system (2 for binary, 10 for decimal, 16 for hexadecimal): ");

    do {
        char firstNumberBuffer[100], secondNumberBuffer[100];
        int firstNumber, secondNumber;

        do {
            printf("Enter the first number: ");
            scanf("%s", firstNumberBuffer);

            if (!isValidNumberForSystem(firstNumberBuffer, inputSystem)) {
                printf("Invalid number for the selected input system. Please enter a correct number.\n");
            } else {
                firstNumber = convertToDecimal(firstNumberBuffer, inputSystem);
                printNumberFormat(firstNumber, inputSystem);
            }

        } while (!isValidNumberForSystem(firstNumberBuffer, inputSystem));

        do {
            printf("Enter the second number: ");
            scanf("%s", secondNumberBuffer);

            if (!isValidNumberForSystem(secondNumberBuffer, inputSystem)) {
                printf("Invalid number for the selected input system. Please enter a correct number.\n");
            } else {
                secondNumber = convertToDecimal(secondNumberBuffer, inputSystem);
                printNumberFormat(secondNumber, inputSystem);
            }

        } while (!isValidNumberForSystem(secondNumberBuffer, inputSystem));

        int operation;
        int result;

        do {
            printf("\nBitwise operation menu:\n");
            printf("1. AND\n");
            printf("2. OR\n");
            printf("3. XOR\n");
            printf("4. NOR\n");
            printf("5. Left Shift\n");
            printf("6. Right Shift\n");
            printf("7. Replay program\n");
            printf("8. Exit\n");

            printf("Enter your choice: ");
            scanf("%d", &operation);

            if (operation >= 1 && operation <= 6) {
                result = performBitwiseOperation(operation, firstNumber, secondNumber);
                printNumberFormat(result, outputSystem);
            } else if (operation == 7) {
                printf("Replaying program...\n");
                break;
            } else if (operation == 8) {
                printf("Thank you for using bitwise calc. Exiting...\n");
                return;
            } else {
                printf("Invalid choice. Please enter a valid option.\n");
            }

        } while (1);

    } while (1);
}

int main() {
    printf("WELCOME TO THE BITWISE CALCULATOR\n");

    bitwiseCalculator();

    return 0;
}
