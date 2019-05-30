#ifndef ALPHSORT_H
#define ALPHSORT_H

#include <stdio.h>
#include <string.h>

void Sorting_text_alphabetically(
        FILE* Origin_file,
        char* Clean_text,
        int Word_start_numbers[],
        int Number_of_words);

#endif