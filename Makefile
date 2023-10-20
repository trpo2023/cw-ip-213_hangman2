CC = gcc
CFLAGS = -c -Wall
MAIN_BUILD = main.o hangman.o
TEST_BUILD = test/main.o test/ctest.o hangman.o

main: $(MAIN_BUILD)
	$(CC) $^ -o $@
	./main

test: $(TEST_BUILD)
	$(CC) $^ -o $@
	./test

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f * * * | grep -v .keep