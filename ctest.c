#define CTEST_MAIN
#include "ctest.h"
#include "hangman.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, const char **argv) {
int result = ctest_main(argc, argv);
return result;
}

CTEST(string_length, test1) {
char str[] = "hello";
ASSERT_EQUAL(5, string_length(str));
}

CTEST(string_length, test2) {
char str[] = "";
ASSERT_EQUAL(0, string_length(str));
}

CTEST(replace_chars, test1) {
char str[] = "hello";
replace_chars(str, 'l', 'z');
ASSERT_STR("hezzo", str);
}

CTEST(replace_chars, test2) {
char str[] = "hello";
replace_chars(str, 'o', 'a');
ASSERT_STR("hella", str);
}

CTEST(load_random_word, test1) {
char word[MAX_LENGTH];
load_random_word(word);
int len = string_length(word);
ASSERT_TRUE(len > 0 && len <= MAX_LENGTH);
}

CTEST(play_game, test1) {
play_game();
}