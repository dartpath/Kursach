#include <stdio.h>
#include "../src/alphsort.h"
#include "../src/filesize.h"
#include "../src/readfile.h"
#include "../src/removepunct.h"
#include "ctest.h"
#define CTEST_MAIN
//CTEST(alphabet_suite, remove_punctuation)
//{
//    FILE Origin_file = fopen("text_1.txt", "r");
//    FILE Expected_file = fopen("test_1.txt", "r");
//
//   char* Origin_text = Reading_text_from_file(Origin_file);
//    char* Expected_text = Reading_text_from_file(Result_file);
//
//    int Word_start_numbers[filesize(Origin_file) + 1];
//    int Word_count = remove_punctuation_with_word_counting(
//            Origin_text, Word_start_numbers);
//
//    ASSERT_STR(Expected_text, Origin_text);
//}

CTEST(alphabet_suite, alphabet_sort)
{
    FILE Origin_file = fopen("text_2.txt", "r");
    FILE Expected_file = fopen("test_2_exp.txt", "r");
    FILE Result_file = fopen("test_2_res.txt", "a");

    char* Origin_text = Reading_text_from_file(Origin_file);
    char* Expected_text = Reading_text_from_file(Expected_file);
    char* Result_text;

    int Word_start_numbers[filesize(Origin_file) + 1];
    int Word_count = remove_punctuation_with_word_counting(
            Origin_text, Word_start_numbers);

    Sorting_text_alphabetically(
            Origin_file, Origin_text, Word_start_numbers, Word_count);

    fprintf(Result_file, "%s", &Origin_text[Word_start_numbers[0]]);
    for (int i = 1; i < Word_count; i++) {
        fprintf(Result_file, "\n%s", &Origin_text[Word_start_numbers[i]]);
    }

    Result_text = Reading_text_from_file(Origin_file);

    ASSERT_STR(Expected_text, Result_text);
}

int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}