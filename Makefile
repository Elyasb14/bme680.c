CC = gcc
CFLAGS = -Wall -g
TARGET = main
SOURCES = src/main.c

build:
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

clean:
	rm -f $(TARGET)
