#include "alphsort.h"
#include "filesize.h"
#include "readfile.h"
#include "removepunct.h"
#include <stdio.h>

int main(int argc, char* argv[])
{
    if (argc != 3) {
        printf("Введено неверное количество аргументов! (Введите 2 "
               "аргумента)\nПервый аргумент: Путь к отсортированному "
               "файлу\nВторой аргумент: Путь к исходному файлу\n");
        return 0;
    }

    FILE* Origin_file = fopen(argv[2], "r");
    FILE* Result_file = fopen(argv[1], "w");

    printf("Открытие файла для чтения: ");
    if (Origin_file == NULL) {
        printf("ошибка\n");
        return -1;
    } else
        printf("выполнено\n");

    printf("Открытие файла для записи: ");
    if (Result_file == NULL) {
        printf("ошибка\n");
        return -1;
    } else
        printf("выполнено\n");

    printf("Считывание текста: ");
    char* Text = Reading_text_from_file(Origin_file);
    printf("выполнено\n");

    printf("Очистка текста: ");
    int Word_start_numbers[filesize(Origin_file) + 1];
    int Word_count
            = remove_punctuation_with_word_counting(Text, Word_start_numbers);
    printf("выполнено\n");

    printf("Сортировка текста: ");
    Sorting_text_alphabetically(
            Origin_file, Text, Word_start_numbers, Word_count);
    printf("выполнено\n");

    printf("Запись в файл: ");
    fprintf(Result_file, "%s", &Text[Word_start_numbers[0]]);
    for (int i = 1; i < Word_count; i++) {
        fprintf(Result_file, "\n%s", &Text[Word_start_numbers[i]]);
    }
    printf("выполнено\n");

    printf("Закрытие файла для чтения: ");
    if (fclose(Origin_file) == EOF)
        printf("ошибка\n");
    else
        printf("выполнено\n");

    printf("Закрытие файла для записи: ");
    if (fclose(Result_file) == EOF)
        printf("ошибка\n");
    else
        printf("выполнено\n");

    return 0;
}