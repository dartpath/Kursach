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
   int Number;
   int i, j, Temp;
   int Flag; //Признак окончания слова.

   // Открытие файла с режимом доступа «только чтение» и привязка к нему 
   // потока данных
   printf ("Открытие файла: ");

   // Проверка открытия файла
   if (mf == NULL) {printf ("ошибка\n"); return -1;}
   else printf ("выполнено\n");

   /* Предварительная обработка */
  for (Number = 0, Flag = 1, i = 0; String[i]; i ++)
  {
     /*Все пробелы заменяем на символ конца строки */
    if (String[i] == ' ' || String[i] == ':' || String[i] == '.' || String[i] == ',' || String[i] == '-' || String[i] == '\n')
    {
      String[i] = 0;
      Flag = 1;
    }
    /* Позиции первых после пробелов символов записываем в массив */
    else if (Flag)
    {
      Words[Number ++] = i;
      Flag = 0;
    }
  }

  /* Сортировка */
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
	//fwrite(String, sizeof(char), k, s);
      /* Вывод результата */
      for (i = 0; i < Number; i++){
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