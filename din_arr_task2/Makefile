CC = gcc
CFLAGS = -Wall -Wextra -std=c11
DEBUG_FLAGS = -g
OPTIMIZATION_FLAGS = -O3

all: din

din: din.c
	$(CC) $(CFLAGS) $(DEBUG_FLAGS) $(OPTIMIZATION_FLAGS) $^ -o $@

clean:
	rm -f din

