#include "text.h"
#include "filesize.h"
#include "readfile.h"
#include "procword.h"

int procword(char* String, int Words[])
{
    int Flag, i, Number;

    for (Number = 0, Flag = 1, i = 0; String[i]; i++) {
        if (String[i] == ' ' || String[i] == ':' || String[i] == '.'
            || String[i] == ',' || String[i] == '-' || String[i] == '\n'
            || String[i] == '!' || String[i] == '?' || String[i] == ';'
            || String[i] == '"' || String[i] == '(' || String[i] == ')'
            || String[i] == '"') {
            String[i] = 0;
            Flag = 1;
        }

        else if (Flag) {
            Words[Number++] = i;
            Flag = 0;
        }
    }
    return Number;
}