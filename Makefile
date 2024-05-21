# Compiler
CC = gcc

# Compiler flags
CFLAGS = -Wall -g

# Target executable
TARGET = main

# Source files
SOURCES = src/main.c

# Build the target
$(TARGET): $(SOURCES)
	$(CC) $(CFLAGS) $(SOURCES) -o $(TARGET)

# Clean up
clean:
	rm -f $(TARGET)
