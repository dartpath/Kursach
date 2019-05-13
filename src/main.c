#include "text.h"

int main(int argc, char* argv[])
{
    FILE* rfile = fopen(argv[2], "r");
    FILE* wfile = fopen(argv[1], "w");

    printf("Открытие файла для чтения: ");
    if (rfile == NULL) {
        printf("ошибка\n");
        return -1;
    } else
        printf("выполнено\n");

    printf("Открытие файла для записи: ");
    if (wfile == NULL) {
        printf("ошибка\n");
        return -1;
    } else
        printf("выполнено\n");

    char* String = readfile(rfile);
    int Words[filesize(rfile) + 1];
    int Number = procword(String, Words);
    sorttext(rfile, String, Words, Number);

    fprintf(wfile, "%s", &String[Words[0]]);
    for (int i = 1; i < Number; i++) {
        fprintf(wfile, "\n%s", &String[Words[i]]);
    }

    printf("\nЗакрытие файла для чтения: ");
    if (fclose(rfile) == EOF)
        printf("ошибка\n");
    else
        printf("выполнено\n");

    printf("Закрытие файла для записи: ");
    if (fclose(wfile) == EOF)
        printf("ошибка\n");
    else
        printf("выполнено\n");

    return 0;
}