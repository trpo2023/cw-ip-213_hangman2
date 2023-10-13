CC = gcc
CFLAGS = -Wall -Wextra -pedantic -std=c99
TEST_DIR = test
BIN_DIR = bin
OBJ_DIR = obj

all: $(BIN_DIR)/game

$(BIN_DIR)/game: $(OBJ_DIR)/main.o $(OBJ_DIR)/hangman.o
	mkdir -p $(BIN_DIR)
	$(CC) $(OBJ_DIR)/main.o $(OBJ_DIR)/hangman.o -o $(BIN_DIR)/game 

$(OBJ_DIR)/main.o: main.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CXXFLAGS) -c main.c -o $(OBJ_DIR)/main.o

$(OBJ_DIR)/hangman.o: hangman.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CXXFLAGS) -c hangman.c -o $(OBJ_DIR)/hangman.o

$(OBJ_DIR)/ctest.o: ctest.c
	mkdir -p $(OBJ_DIR)
	$(CC) $(CXXFLAGS) -c ctest.c -o $(OBJ_DIR)/ctest.o

$(BIN_DIR)/tests: $(OBJ_DIR)/ctest.o $(OBJ_DIR)/hangman.o
	mkdir -p $(BIN_DIR)

tests: $(BIN_DIR)/tests

run: $(BIN_DIR)/game
	./$(BIN_DIR)/game

run_tests: $(BIN_DIR)/tests
	./$(BIN_DIR)/tests

clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR) 