#include "text.h"
#include "filesize.h"
#include "readfile.h"
#include "procword.h"

void sorttext(FILE* mf, char* String, int Words[], int Number)
{
    int i, j, Temp;
    for (j = Number - 1; j > 0; j--) {
        for (i = 0; i < j; i++) {
            if (strcmp(&String[Words[i]], &String[Words[i + 1]]) > 0) {
                Temp = Words[i];
                Words[i] = Words[i + 1];
                Words[i + 1] = Temp;
            }
        }
    }
    if (String[i] == '\n' && feof(mf) != 0) {
        for (j = Number - 1; j > 0; j--) {
            for (i = 0; i < j; i++) {
                if (strcmp(&String[Words[i]], &String[Words[i + 1]]) > 0) {
                    Temp = Words[i];
                    Words[i] = Words[i + 1];
                    Words[i + 1] = Temp;
                }
            }
        }
    }
    return;
}