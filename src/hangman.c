#include "hangman.h"

void display_hangman(int tries) {
    printf("Рисуем виселицу...\n\n");
    if (tries == 0) {
        printf("  +---+\n");
        printf("      |\n");
        printf("      |\n");
        printf("      |\n");
        printf("      |\n");
        printf("      |\n");
    } else if (tries == 1) {
        printf("  +---+\n");
        printf("  |   |\n");
        printf("      |\n");
        printf("      |\n");
        printf("      |\n");
        printf("      |\n");
    } else if (tries == 2) {
        printf("  +---+\n");
        printf("  |   |\n");
        printf("  O   |\n");
        printf("      |\n");
        printf("      |\n");
        printf("      |\n");
    } else if (tries == 3) {
        printf("  +---+\n");
        printf("  |   |\n");
        printf("  O   |\n");
        printf("  |   |\n");
        printf("      |\n");
        printf("      |\n");
    } else if (tries == 4) {
        printf("  +---+\n");
        printf("  |   |\n");
        printf("  O   |\n");
        printf(" /|   |\n");
        printf("      |\n");
        printf("      |\n");
    } else if (tries == 5) {
        printf("  +---+\n");
        printf("  |   |\n");
        printf("  O   |\n");
        printf(" /|\\  |\n");
        printf("      |\n");
        printf("      |\n");
    } else {
        printf("  +---+\n");
        printf("  |   |\n");
        printf("  O   |\n");
        printf(" /|\\  |\n");
        printf(" / \\  |\n");
        printf("      |\n");
    }
    printf("\n");
}

int string_length(char* string) {
    int length = 0;
    while (*string != '\0') {
        length++;
        string++;
    }
    return length;
}

void replace_chars(char* string, char find, char replace) {
    while (*string != '\0') {
        if (*string == find) {
            *string = replace;
        }
        string++;
    }
}

void load_random_word(char* word) {
    FILE* file = fopen("../words.txt", "r");

    if (file == NULL) {
        printf("Ошибка загрузки файла со словами.\n");
        exit(EXIT_FAILURE);
    }
    int num_words = 0;
    while (fgets(word, MAX_LENGTH, file) != NULL) {
        num_words++;
    }
    rewind(file);
    srand(time(NULL));
    int random_index = rand() % num_words;

    for (int i = 0; i < random_index; i++) {
        fgets(word, MAX_LENGTH, file);
    }
    fclose(file);
}

void play_game() {
    char word[MAX_LENGTH];
    load_random_word(word);
    int word_length = string_length(word) - 1;
    char guessed[word_length];
    memset(guessed, '-', word_length);
    int num_tries = 0;
    printf("Добро пожаловать в игру в виселицу!\n");
    printf("У вас есть %d попыток, чтобы отгадать слово: ", MAX_TRIES);
    printf("%s\n", guessed);
    while (num_tries < MAX_TRIES) {
        char guess;
        printf("Введите букву: ");
        scanf(" %c", &guess);
        int correct_guess = 0;
        for (int i = 0; i < word_length; i++) {
            if (word[i] == guess) {
                guessed[i] = guess;
                correct_guess = 1;
            }
        }
        if (!correct_guess) {
            num_tries++;
            display_hangman(num_tries);
            printf("Неверно! Осталось %d попыток.\n", MAX_TRIES - num_tries);
        } else if (correct_guess == 0) {
            printf("Недопустимый ввод. Попробуйте еще раз.\n");
        } else {
            printf("Верно! %s\n", guessed);
        }
        if (strcmp(word, guessed) == 0) {
            printf("Вы победили! Загаданное слово было \"%s\".\n", word);
            return;
        }
    }
    printf("Вы проиграли. Загаданное слово было \"%s\".\n", word);
}
