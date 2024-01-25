CC = gcc
CFLAGS = -Wall -Wextra -std=c99

TARGET = stack_program
SRC = stack.c

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) -o $(TARGET) $(SRC)

.PHONY: clean

clean:
	rm -f $(TARGET)
