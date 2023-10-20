CC = gcc
CFLAGS = -c -Wall
MAIN_BUILD = main.o hangman.o
TEST_BUILD = test/main1.o test/ctest.o test/hangman.o

main: $(MAIN_BUILD)
	$(CC) $^ -o $@
	./main

test: $(TEST_BUILD)
	$(CC) $^ -o $@
	./test

%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

test/%.o: %.cpp
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f * * * | grep -v .keep