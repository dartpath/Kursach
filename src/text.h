#ifndef TEXT_H
#define TEXT_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

long int filesize( FILE *mf );
char *readfile(FILE *mf);
int procword(char *String, int Words[]);
void sorttext(FILE *mf, char *String, int Words[], int Number);

#endif