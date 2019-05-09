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

int main ()
{  
   // Переменная, в которую будет помещен указатель на созданный
   // поток данных 
   FILE *mf = fopen ("tekst.txt","r");
   FILE *s = fopen("test.txt", "w");
   // Переменная, в которую поочередно будут помещаться считываемые строки
   //char str[50000];
   int k = filesize(mf) + 1;
   char String[k];
   int Words[k];
   int Number;
   int i, j, Temp;
   int Flag; //Признак окончания слова.

   //Указатель, в который будет помещен адрес массива, в который считана 
   // строка, или NULL если достигнут коней файла или произошла ошибка
   char *estr;

   // Открытие файла с режимом доступа «только чтение» и привязка к нему 
   // потока данных
   printf ("Открытие файла: ");

   // Проверка открытия файла
   if (mf == NULL) {printf ("ошибка\n"); return -1;}
   else printf ("выполнено\n");

   printf ("Считаны строки:\n");

   //Чтение (построчно) данных из файла в бесконечном цикле
   while (1)
   {
      // Чтение одной строки  из файла
      estr = fgets (String,sizeof(String),mf);

      //Проверка на конец файла или ошибку чтения
      if (estr == NULL)
      {
         // Проверяем, что именно произошло: кончился файл
         // или это ошибка чтения
         if ( feof (mf) != 0)
         {  
            //Если файл закончился, выводим сообщение о завершении 
            //чтения и выходим из бесконечного цикла
            printf ("\nЧтение файла закончено\n");
            break;
         }
         else
         {
            //Если при чтении произошла ошибка, выводим сообщение 
            //об ошибке и выходим из бесконечного цикла
            printf ("\nОшибка чтения из файла\n");
            break;
         }
      }
      //Если файл не закончился, и не было ошибки чтения 
      //выводим считанную строку  на экран
      printf ("     %s",String);
   }
   
   /* Предварительная обработка */
  for (Number = 0, Flag = 1, i = 0; String[i]; i ++)
  {
     /*Все пробелы заменяем на символ конца строки */
    if (String[i] == ' ' || String[i] == ':' || String[i] == '.' || String[i] == ',' || String[i] == '-')
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
      /* Вывод результата */
      for (i = 0; i < Number; i++){
         fprintf(s, "%s\n", &String[Words[i]]);
      }  /* End of 'main' function */  

   // Закрываем файл
   printf ("Закрытие файла: ");
   if ( fclose (mf) == EOF) printf ("ошибка\n");
   else printf ("выполнено\n");

   return 0;
} 