# Directories
SRC_DIR = src
INCLUDE_DIR = include
BUILD_DIR = build
BIN_DIR = bin

# Compiler and flags
CC = gcc
CFLAGS = -I$(INCLUDE_DIR)

# Files
TARGET = $(BIN_DIR)/program
SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJECTS = $(patsubst $(SRC_DIR)/%.c,$(BUILD_DIR)/%.o,$(SOURCES))

# Rules
all: directories $(TARGET)

directories:
	mkdir -p $(BUILD_DIR) $(BIN_DIR)

$(TARGET): $(OBJECTS)
	$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/main.o: $(SRC_DIR)/main.c $(INCLUDE_DIR)/employee.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/employee.o: $(SRC_DIR)/employee.c $(INCLUDE_DIR)/employee.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR)/utils.o: $(SRC_DIR)/utils.c $(INCLUDE_DIR)/utils.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(BUILD_DIR)/* $(BIN_DIR)/*

.PHONY: all clean directories