#include "filesize.h"
#include <stdio.h>

long int filesize(FILE* mf)
{
    long int save_pos, size_of_file;

    save_pos = ftell(mf);
    fseek(mf, 0L, SEEK_END);
    size_of_file = ftell(mf);
    fseek(mf, save_pos, SEEK_SET);
    return size_of_file;
}