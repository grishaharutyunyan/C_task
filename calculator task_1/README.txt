Picsart Academy
Grisha Harutyunyan 

char *intToBinary(int num): Converts an integer to its binary representation.

int isValidNumberSystem(int system): Checks if a given number system is valid.

int isValidNumberForSystem(const char *input, int system): Validates a number for a specified number system.

void printBinaryFormat(int number): Prints the binary format of a number.

void printHexadecimalFormat(int number): Prints the hexadecimal format of a number.

void printNumberFormat(int number, int system): Prints the number in the specified format based on the number system.

int convertToDecimal(const char *input, int system): Converts a string representation to its decimal equivalent.

int performBitwiseOperation(int operation, int num1, int num2): Performs a bitwise operation on two numbers.

int getNumberSystemFromUser(const char *prompt): Prompts the user to enter a valid number system.

void bitwiseCalculator(): The main function guiding the user through bitwise operations.

Main Function (main):
Displays a welcome message.
Calls the bitwiseCalculator function.
intToBinary Function:

Converts an integer to its binary representation using a static buffer.

Returns a pointer to the binary representation.

isValidNumberSystem Function:

Checks if a given number system is valid (2 for binary, 10 for decimal, 16 for hexadecimal).
Returns 1 if valid, 0 otherwise.

isValidNumberForSystem Function:
Checks if a given input string is a valid number in the specified number system.
Returns 1 if valid, 0 otherwise.

Printing Functions (printBinaryFormat, printHexadecimalFormat, printNumberFormat):
Display the binary, hexadecimal, or decimal format of a given number.

convertToDecimal Function:
Converts a string representation of a number to its decimal equivalent using the strtol function.

performBitwiseOperation Function:
Performs the selected bitwise operation on two numbers based on the user's choice.
Returns the result of the operation.

getNumberSystemFromUser Function:
Prompts the user to enter a valid number system (2 for binary, 10 for decimal, 16 for hexadecimal).
Returns the selected number system.

bitwiseCalculator Function:
Guides the user through the bitwise calculator.
Allows the user to select input and output number systems, enter two numbers, and perform bitwise operations.
Provides a menu for bitwise operations and handles user input.



User Manual
Number System Selection:
The program prompts you to enter the input and output number systems (2 for binary, 10 for decimal, 16 for hexadecimal).
Number Entry:
Enter the first and second numbers in the chosen input number system.
Bitwise Operations:
Choose a bitwise operation from the menu:
1: AND
2: OR
3: XOR
4: NOR
5: Left Shift
6: Right Shift
7: Replay program
8: Exit
Result Display:
The program displays the result of the selected bitwise operation in the chosen output number system.
Replaying and Exiting:
Choose option 7 to replay the program and option 8 to exit.



