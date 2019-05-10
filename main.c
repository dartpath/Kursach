#include <stdio.h> 
#include <string.h>
#include <stdlib.h> //Для printf, fgets, fopen, fclose, feof

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

int main (int argc, char *argv[])
{  
   // Переменная, в которую будет помещен указатель на созданный
   // поток данных 
   FILE *mf = fopen (argv[2],"r");
   FILE *s = fopen(argv[1], "w");
   // Переменная, в которую поочередно будут помещаться считываемые строки
   //char str[50000];
   int k = filesize(mf) + 1;
   char *String = readfile(mf);
   int Words[k];
   int Number = procword(String, Words);

   // Открытие файла с режимом доступа «только чтение» и привязка к нему 
   // потока данных
   printf ("Открытие файла: ");

   // Проверка открытия файла
   if (mf == NULL) {printf ("ошибка\n"); return -1;}
   else printf ("выполнено\n");
   
   sorttext(mf, String, Words, Number);
   
     
	//fwrite(String, sizeof(char), k, s);
      /* Вывод результата */
      for (int i = 0; i < Number; i++){
     //   // fprintf(s, "%s\n", &String[Words[i]]);
		     fprintf(s, "%s\n", &String[Words[i]]);
      }  /* End of 'main' function */  

   // Закрываем файл
   printf ("\nЗакрытие файла: ");
   if ( fclose (mf) == EOF) printf ("ошибка\n");
   else printf ("выполнено\n");
   
   printf ("Закрытие файла: ");
   if ( fclose (s) == EOF) printf ("ошибка\n");
   else printf ("выполнено\n");

   return 0;
} 