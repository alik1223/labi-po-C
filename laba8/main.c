#include <stdio.h>
void main(void)
{
    char line[100];
    int i;
    int start; // позиция начала слова
    int stop; // позиция конца слова
    int flag; // признак слова
    int sum;//число букв в слове
    int k;
    int j;
    char c;
    flag=0;
    start = 0;
    stop = 0;
    i=0;
    k=0;
    sum=0;
    gets(line);
do
    {
    c=line[i];
    if( c==' ' || c=='.' || c==',' || c=='\n' || c=='\0')
    {
        if (flag==1) // найден первый разделить после слова
        {

            stop=i-1;
            if (sum%2!=0)
            {
            k = start;
            for(j = stop+1; line[j] !='\0'; j++)// удаление слова (перенос оставшейся  части строки)
            {
                line[k]=line[j];
                k++;
            }
            line[k]='\0';
            i=start; //начать обработку строки с  перенесённого фрагмента
            }
        }
        flag=0;
        sum=0;
    }
    else
    {
      if (flag==0)
      {
      start=i; // запомнить позицию начала слова
      }
      sum++;
      flag=1;
    }
    i++;
    }
    while( c!= '\0' );
 puts(line);
}






