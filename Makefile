CC = gcc
CFLAGS = -Wall -Wextra

main: main.o hangman.o
    $(CC) $(CFLAGS) -o main main.o hangman.o

main.o: main.c hangman.h
    $(CC) $(CFLAGS) -c main.c

hangman.o: hangman.c hangman.h
    $(CC) $(CFLAGS) -c hangman.c

clean:
    rm -f main main.o hangman.o