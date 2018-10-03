#include <stdio.h>
#define MAXLINE 1024
#define N 5
void main( void )
{
FILE *fpin; // входной файл
FILE *fpout; // выходной файл
char line[MAXLINE]; // текущая строка
char *ptr;
int sum=0;
fpin = fopen( "test.txt", "rt" ); // открыть файл для чтения
if( fpin == NULL )
return; // ошибка при открытии файла
fpout = fopen("result.txt", "wt" ); // открыть файл для записи
if( fpout == NULL )
return; // ошибка при открытии файла
while( !feof( fpin ) )// цикл до конца входного файла
{
ptr = fgets( line, MAXLINE, fpin ); // чтение строки
if( ptr == NULL )
break; // файл исчерпан
while( *ptr != '\0' ) // цикл до конца строки
{
if( sum==N )
{
*ptr++ = '\n'; // ставим символ "конец строки"
*ptr = '\0'; // ставим ограничитель строки
break;
}
ptr++; // продвигаем указатель по строке
sum++;
}
fputs( line, fpout ); // запись строки
sum=0;
}
fclose( fpin ); // закрыть входной файл
fclose( fpout ); // закрыть выходной файл
}
