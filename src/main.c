#include "text.h"

int main(int argc, char* argv[])
{
    FILE* rfile = fopen(argv[2], "r");

    printf("Открытие файла для чтения: ");
    if (rfile == NULL) {
        printf("ошибка\n");
        return -1;
    } else
        printf("выполнено\n");

    char* String = readfile(rfile);

    printf("\nЗакрытие файла для чтения: ");
    if (fclose(rfile) == EOF)
        printf("ошибка\n");
    else
        printf("выполнено\n");

    FILE* wfile = fopen(argv[1], "w");

    printf("Открытие файла для записи: ");
    if (wfile == NULL) {
        printf("ошибка\n");
        return -1;
    } else
        printf("выполнено\n");

    int Words[filesize(rfile) + 1];
    int Number = procword(String, Words);
    sorttext(rfile, String, Words, Number);

    for (int i = 0; i < Number; i++) {
        fprintf(wfile, "%s\n", &String[Words[i]]);
    }

    printf("Закрытие файла для записи: ");
    if (fclose(wfile) == EOF)
        printf("ошибка\n");
    else
        printf("выполнено\n");

    return 0;
}