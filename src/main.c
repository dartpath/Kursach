#include "text.h"

int main (int argc, char *argv[])
{  
   // Переменная, в которую будет помещен указатель на созданный
   // поток данных 
   FILE *rfile = fopen (argv[2],"r");
   FILE *wfile = fopen(argv[1], "w");
   
   // Открытие файла с режимом доступа «только чтение» и привязка к нему 
   // потока данных
   printf ("Открытие файла: ");

   // Проверка открытия файла
   if (rfile == NULL) {printf ("ошибка\n"); return -1;}
   else printf ("выполнено\n");
   
   // Переменная, в которую поочередно будут помещаться считываемые строки
   //char str[50000];
   int k = filesize(rfile) + 1;
   char *String = readfile(rfile);
   int Words[k];
   int Number = procword(String, Words);


   
   sorttext(rfile, String, Words, Number);
   
      /* Вывод результата */
      for (int i = 0; i < Number; i++){
		     fprintf(wfile, "%s\n", &String[Words[i]]);
      }

   // Закрываем файл
   printf ("\nЗакрытие файла: ");
   if ( fclose (rfile) == EOF) printf ("ошибка\n");
   else printf ("выполнено\n");
   
   printf ("Закрытие файла: ");
   if ( fclose (wfile) == EOF) printf ("ошибка\n");
   else printf ("выполнено\n");

   return 0;
} 