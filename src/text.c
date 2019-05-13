#include "text.h"

long int filesize( FILE *mf )
{
  long int save_pos, size_of_file;
 
  save_pos = ftell( mf );
  fseek( mf, 0L, SEEK_END );
  size_of_file = ftell( mf );
  fseek( mf, save_pos, SEEK_SET );
  return( size_of_file );
}

char *readfile(FILE *mf)
{
	char *String = malloc((filesize(mf) + 1) * sizeof(char));

    fread(String, sizeof(char), (filesize(mf) + 1), mf);  
    printf ("Считаны строки:\n %s", String); 
	
	return String;
}

int procword(char *String, int Words[])
{
	int Flag, i, Number;
	
	for (Number = 0,Flag = 1,i = 0; String[i]; i ++)
   {

    if (String[i] == ' ' || String[i] == ':' || String[i] == '.' || String[i] == ',' || String[i] == '-' || String[i] == '\n' || String[i] == '!' || String[i] == '?')
    {
      String[i] = 0;
      Flag = 1;
    }

    else if (Flag)
    {
      Words[Number ++] = i;
      Flag = 0;
    }
  }
  return Number;
}

void sorttext(FILE *mf, char *String, int Words[], int Number)
{
	int i, j, Temp;
	for (j = Number - 1; j > 0; j --){
      for (i = 0; i < j; i ++){
         if (strcmp(&String[Words[i]], &String[Words[i + 1]]) > 0)
         {
         Temp = Words[i];
         Words[i] = Words[i + 1];
         Words[i + 1] = Temp;
         }
      }
   }
   if (String[i] == '\n' && feof(mf) != 0){
      for (j = Number - 1; j > 0; j --){
        for (i = 0; i < j; i ++){
          if (strcmp(&String[Words[i]], &String[Words[i + 1]]) > 0)
          {
            Temp = Words[i];
            Words[i] = Words[i + 1];
            Words[i + 1] = Temp;
          }
        }
      }
   }
	  return;
}