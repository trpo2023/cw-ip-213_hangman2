CC = gcc
CFLAGS = -Wall -Wextra

hangman: hangman.o main.o ctest.o
    $(CC) $(CFLAGS) $^ -o $@

hangman.o: hangman.c hangman.h
    $(CC) $(CFLAGS) -c $< -o $@

main.o: main.c hangman.h
    $(CC) $(CFLAGS) -c $< -o $@

ctest.o: ctest.c hangman.h
    $(CC) $(CFLAGS) -c $< -o $@

clean:
    rm -f hangman hangman.o main.o ctest.o