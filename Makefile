CC = gcc
CFLAGS = -c -Wall
MAIN_BUILD = main.o hangman.o
TEST_BUILD = test/main1.o test/ctest.o hangman.o

main: $(MAIN_BUILD)
	$(CC) $^ -o $@
	./main

test: $(TEST_BUILD)
	$(CC) $^ -o $@
	./test

%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

test/%.o: %.c
	$(CC) $(CFLAGS) $< -o $@

clean:
	rm -f * * * | grep -v .keep