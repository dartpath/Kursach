#include "alphsort.h"
#include "filesize.h"
#include "readfile.h"
#include "removepunct.h"

int remove_punctuation_with_word_counting(char *Origin_text, int Word_start_numbers[])
{
    int Beginning_of_the_word, i, Word_count = 0;

    for (Word_count = 0, Beginning_of_the_word = 1, i = 0; Origin_text[i]; i++) {
        if (Origin_text[i] == ' ' || Origin_text[i] == ':' || Origin_text[i] == '.'
            || Origin_text[i] == ',' || Origin_text[i] == '-' || Origin_text[i] == '\n'
            || Origin_text[i] == '!' || Origin_text[i] == '?' || Origin_text[i] == ';'
            || Origin_text[i] == '"' || Origin_text[i] == '(' || Origin_text[i] == ')'
            || Origin_text[i] == '"') {
            Origin_text[i] = 0;
            Beginning_of_the_word = 1;
        }

        else if (Beginning_of_the_word) {
            Word_start_numbers[Word_count++] = i;
            Beginning_of_the_word = 0;
        }
    }
    return Word_count;
}