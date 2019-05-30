#define CTEST_MAIN
#define CTEST_COLOR_OK

#include <stdio.h>
#include <alphsort.h>
#include <filesize.h>
#include <readfile.h>
#include <removepunct.h>
#include <ctest.h>

int main(int argc, const char** argv)
{
    return ctest_main(argc, argv);
}

CTEST(file_size_test, filesize_sorted_file)
{
    // Given
    FILE* test = fopen("test/test_1.txt", "r");
    // When
    const long int result = filesize(test);
    fclose(test);
    // Then
    const long int expected = 81;
    ASSERT_EQUAL(expected, result);
}

CTEST(file_size_test, filesize_unsorted_file)
{
    // Given
    FILE* test = fopen("test/test_2.txt", "r");
    // When
    const long int result = filesize(test);
    fclose(test);
    // Then
    const long int expected = 71;
    ASSERT_EQUAL(expected, result);
}

CTEST(file_size_test, filesize_empty_file)
{
    // Given
    FILE* test = fopen("test/empty.txt", "r");
    // When
    const long int result = filesize(test);
    fclose(test);
    // Then
    const long int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(read_test, sorted_file)
{
    // Given
    FILE* Origin_file = fopen("test/test_1.txt", "r");
    // When
    const char* result = Reading_text_from_file(Origin_file);
    fclose(Origin_file);
    // Then
    const char expected[] = "0\n1\n10\n12\n123\n2\n3\n321\nA\nB\nC\na\nabc\nb\nbac\nbb\nc\nА\nБ\nВ\nа\nаа\nабв\nб\nбав\nв\0";

    ASSERT_STR(expected, result);
}

CTEST(read_test, unsorted_file)
{
    // Given
    FILE* Origin_file = fopen("test/test_2.txt", "r");
    // When
    const char* result = Reading_text_from_file(Origin_file);
    fclose(Origin_file);
    // Then
    const char expected[] = "Z\nW\nP J K \nB C A \n10 9 8 7 6 \n3 2 1 6 7 1\nЯ я А а Б б\nВ в Г\nг\0";

    ASSERT_STR(expected, result);
}

CTEST(read_test, empty_file)
{
    // Given
    FILE* Origin_file = fopen("test/empty.txt", "r");
    // When
    const char* result = Reading_text_from_file(Origin_file);
    fclose(Origin_file);
    // Then
    const char expected[] = "\0";

    ASSERT_STR(expected, result);
}

CTEST(word_counting_test, sorted_counting)
{
    // Given
    FILE* Origin_file = fopen("test/test_1.txt", "r");
    char* Text = Reading_text_from_file(Origin_file);
    int Word_start_numbers[filesize(Origin_file) + 1];
    // When
    const int result = remove_punctuation_with_word_counting(Text, Word_start_numbers);
    fclose(Origin_file);
    // Then
    const int expected = 26;
    ASSERT_EQUAL(expected, result);
}

CTEST(word_counting_test, unsorted_counting)
{
    // Given
    FILE* Origin_file = fopen("test/test_2.txt", "r");
    char* Text = Reading_text_from_file(Origin_file);
    int Word_start_numbers[filesize(Origin_file) + 1];
    // When
    const int result = remove_punctuation_with_word_counting(Text, Word_start_numbers);
    fclose(Origin_file);
    // Then
    const int expected = 29;
    ASSERT_EQUAL(expected, result);
}

CTEST(word_counting_test, counting_empty_file)
{
    // Given
    FILE* Origin_file = fopen("test/empty.txt", "r");
    char* Text = Reading_text_from_file(Origin_file);
    int Word_start_numbers[filesize(Origin_file) + 1];
    // When
    const int result = remove_punctuation_with_word_counting(Text, Word_start_numbers);
    fclose(Origin_file);
    // Then
    const int expected = 0;
    ASSERT_EQUAL(expected, result);
}

CTEST(word_counting_test, remove_punctuation_counting)
{
    // Given
    FILE* Origin_file = fopen("test/test_3.txt", "r");
    char* Text = Reading_text_from_file(Origin_file);
    int Word_start_numbers[filesize(Origin_file) + 1];
    // When
    const int result = remove_punctuation_with_word_counting(Text, Word_start_numbers);
    fclose(Origin_file);
    // Then
    const int expected = 2;
    ASSERT_EQUAL(expected, result);
}

CTEST(word_counting_test, comparison_default_result_count_word)
{
    // Given
    FILE* Origin_file = fopen("test/test_2.txt", "r");
    FILE* Result_file = fopen("test/result.txt", "w");
    char* Text = Reading_text_from_file(Origin_file);
    int Word_start_numbers[filesize(Origin_file) + 1];
    int Word_count = remove_punctuation_with_word_counting(Text, Word_start_numbers);
    // When
    Sorting_text_alphabetically(Origin_file, Text, Word_start_numbers, Word_count);

    fprintf(Result_file, "%s", &Text[Word_start_numbers[0]]);
    for (int i = 1; i < Word_count; i++) {
        fprintf(Result_file, "\n%s", &Text[Word_start_numbers[i]]);
    }
    fclose(Result_file);
    Result_file = fopen("test/result.txt", "r");
    Text = Reading_text_from_file(Result_file);
    int Rez_word_start_numbers[filesize(Result_file) + 1];
    int result = remove_punctuation_with_word_counting(Text, Rez_word_start_numbers);
    fclose(Origin_file);
    fclose(Result_file);
    // Then
    ASSERT_EQUAL(Word_count, result);
}

CTEST(sorting_test, check_sort)
{
    // Given
    FILE* Origin_file = fopen("test/test_2.txt", "r");
    FILE* Expected_file = fopen("test/expected.txt", "r");
    FILE* Result_file = fopen("test/result.txt", "w");

    char* Origin_text = Reading_text_from_file(Origin_file);
    char* Expected_text = Reading_text_from_file(Expected_file);
    char* Result_text;

    int Word_start_numbers[filesize(Origin_file) + 1];
    int Word_count = remove_punctuation_with_word_counting(
            Origin_text, Word_start_numbers);
    // When
    Sorting_text_alphabetically(
            Origin_file, Origin_text, Word_start_numbers, Word_count);

    fprintf(Result_file, "%s", &Origin_text[Word_start_numbers[0]]);
    for (int i = 1; i < Word_count; i++) {
        fprintf(Result_file, "\n%s", &Origin_text[Word_start_numbers[i]]);
    }
    fclose(Result_file);
    Result_file = fopen("test/result.txt", "r");
    Result_text = Reading_text_from_file(Result_file);

    fclose(Origin_file);
    fclose(Result_file);
    fclose(Expected_file);
    // Then
    ASSERT_STR(Expected_text, Result_text);
}





