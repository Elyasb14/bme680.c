CC = gcc
CFLAGS = -Wall -g -Wextra -Wformat=2
TARGET = main
SOURCES = src/main.c

build:
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

run:
	./$(TARGET)

clean:
	rm -f $(TARGET)
