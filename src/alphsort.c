#include "alphsort.h"
#include "filesize.h"
#include "readfile.h"
#include "removepunct.h"

void Sorting_text_alphabetically(FILE *Origin_file, char *Clean_text, int Word_start_numbers[], int Number_of_words)
{
    int i, j, Temp;
    for (j = Number_of_words - 1; j > 0; j--) {
        for (i = 0; i < j; i++) {
            if (strcmp(&Clean_text[Word_start_numbers[i]], &Clean_text[Word_start_numbers[i + 1]]) > 0) {
                Temp = Word_start_numbers[i];
                Word_start_numbers[i] = Word_start_numbers[i + 1];
                Word_start_numbers[i + 1] = Temp;
            }
        }
    }
    if (Clean_text[i] == '\n' && feof(Origin_file) != 0) {
        for (j = Number_of_words - 1; j > 0; j--) {
            for (i = 0; i < j; i++) {
                if (strcmp(&Clean_text[Word_start_numbers[i]], &Clean_text[Word_start_numbers[i + 1]]) > 0) {
                    Temp = Word_start_numbers[i];
                    Word_start_numbers[i] = Word_start_numbers[i + 1];
                    Word_start_numbers[i + 1] = Temp;
                }
            }
        }
    }
    return;
}