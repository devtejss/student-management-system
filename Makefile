CC = gcc
CFLAGS = -Wall -Wextra -Iinclude

SRC = src/main.c src/student.c
TARGET = app

all: $(TARGET)

$(TARGET): $(SRC)
	$(CC) $(CFLAGS) $(SRC) -o $(TARGET)

clean:
	rm -f $(TARGET)

run: all
	./$(TARGET)
