# Setting up the compiler
CC = gcc
CFLAGS = -g -Wall -Wextra -Werror -pedantic

# The build target executable
TARGET = revbomb

all: $(TARGET)

$(TARGET): $(TARGET).c
	$(CC) $(CFLAGS) -o $(TARGET) $(TARGET).c

clean:
	rm $(TARGET)
