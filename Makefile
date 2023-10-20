CC = gcc
CFLAGS = -c -Wall
SRC_DIR = src
TEST_DIR = test
BUILD_DIR = build
BIN_DIR = bin
MAIN_BUILD = build/src/main.o build/src/hangman.o
TEST_BUILD = build/test/main.o build/test/ctest.o build/test/hangman.o

main: $(BIN_DIR)/main

test: $(BIN_DIR)/test

$(BIN_DIR)/main: $(MAIN_BUILD)
	$(CC) $^ -o $@
	./$(BIN_DIR)/main

$(BIN_DIR)/test: $(TEST_BUILD)
	$(CC) $^ -o $@
	./$(BIN_DIR)/test

$(BUILD_DIR)/$(SRC_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) $< -o $@

$(BUILD_DIR)/$(TEST_DIR)/%.o: $(TEST_DIR)/%.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f $(BUILD_DIR)/$(TEST_DIR)/* $(BUILD_DIR)/$(SRC_DIR)/* $(BIN_DIR)/* | grep -v .keep