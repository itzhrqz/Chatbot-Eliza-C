CC = gcc
CFLAGS_SUB = -Wall -O3
TARGET = eliza


all:
	$(CC) $(CFLAGS_SUB) main.c -o $(TARGET)

clean:
	rm -f $(TARGET)
