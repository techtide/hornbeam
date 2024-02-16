CC = gcc
CFLAGS = -Wall -Wextra
TARGET = hornbeam

SRC_DIR = .
BUILD_DIR = build
OBJ_DIR = $(BUILD_DIR)/obj
BIN_DIR = $(BUILD_DIR)/bin

SRCS = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c,$(OBJ_DIR)/%.o,$(SRCS))

.PHONY: all clean

all: $(TARGET)

$(TARGET): $(OBJS) | $(BIN_DIR)
    $(CC) $(CFLAGS) $^ -o $(BIN_DIR)/$@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
    $(CC) $(CFLAGS) -c $< -o $@

$(OBJ_DIR):
    mkdir -p $(OBJ_DIR)

$(BIN_DIR):
    mkdir -p $(BIN_DIR)

clean:
    rm -rf $(BUILD_DIR)