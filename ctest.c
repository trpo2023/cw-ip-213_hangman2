#include "ctest.h"
#include "hangman.h"

CTEST(string_length, returns_correct_length)
{
    char* str = "Hello, World!";
    int result = string_length(str);
    int expected = 13;
    ASSERT_EQUAL(expected, result);
}

CTEST(string_length, returns_zero_for_empty_string)
{
    char* str = "";
    int result = string_length(str);
    int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(replace_chars, replaces_correct_chars)
{
    char str[] = "Hello, World!";
    replace_chars(str, 'l', 'z');
    char* expected = "Hezzo, Worzd!";
    ASSERT_STR(expected, str);
}

CTEST(load_random_word, returns_valid_word)
{
    char word[MAX_LENGTH];
    load_random_word(word);
    int length = string_length(word) - 1;
    ASSERT_GREATER(length, 0);
}

CTEST(load_random_word, returns_unique_words)
{
    char word1[MAX_LENGTH];
    char word2[MAX_LENGTH];
    load_random_word(word1);
    load_random_word(word2);
    int result = strcmp(word1, word2);
    ASSERT_NOT_EQUAL(0, result);
}

CTEST(play_game_wrapper, returns_valid_result)
{
    const char* expected_win = "Вы победили!";
    const char* expected_lose = "Вы проиграли.";

    char word[MAX_LENGTH] = "hello";
    char guessed[word_length];
    memset(guessed, '-', string_length(word)-1);
    int num_tries = 0;

    freopen("/dev/null", "w", stdout);
    play_game_wrapper(word, guessed, num_tries, "h\ne\nl\nl\no\n");
    fclose(stdout);

    int result_win = strstr(guessed, expected_win) != NULL;
    int result_lose = strstr(guessed, expected_lose) != NULL;

    ASSERT_EQUAL(1, result_win);
    ASSERT_EQUAL(0, result_lose);
}