#ifndef HANGMAN_H
#define HANGMAN_H

void display_hangman(int tries);
int string_length(char* string);
void replace_chars(char* string, char find, char replace);
void load_random_word(char* word);
void play_game();

#endif