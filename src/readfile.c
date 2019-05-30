#include "text.h"
#include "filesize.h"
#include "readfile.h"
#include "procword.h"

char* readfile(FILE* mf)
{
    char* String = malloc((filesize(mf) + 1) * sizeof(char));

    fread(String, sizeof(char), (filesize(mf) + 1), mf);
    printf("Считаны строки:%s\n", String);
    printf("\n");

    return String;
}