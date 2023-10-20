#ifndef HANGMAN_H
#define HANGMAN_H
#define MAX_LENGTH 20
#define MAX_TRIES 6
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

void display_hangman(int tries);
int string_length(char* string);
void replace_chars(char* string, char find, char replace);
void load_random_word(char* word);
void play_game();

#endif