CC = gcc
CFLAGS = -std=c17 -Wall -Wextra -Wpedantic -g -O0

all:
	$(CC) $(CFLAGS) src/main.c -o tinyhex

clean:
	rm -f tinyhex
