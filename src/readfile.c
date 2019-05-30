#include "alphsort.h"
#include "filesize.h"
#include "readfile.h"

char *Reading_text_from_file(FILE *Origin_file)
{
    char *Text = malloc((filesize(Origin_file) + 1) * sizeof(char));

    fread(Text, sizeof(char), (filesize(Origin_file) + 1), Origin_file);
    printf("Считаны строки:%s\n", Text);
    printf("\n");

    return Text;
}