#include "readfile.h"
#include "filesize.h"
#include <stdio.h>
#include <stdlib.h>

char* Reading_text_from_file(FILE* Origin_file)
{
    char* Text = malloc((filesize(Origin_file) + 1) * sizeof(char));

    fread(Text, sizeof(char), (filesize(Origin_file) + 1), Origin_file);
    printf("Считаны строки:\n%s", Text);

    return Text;
}