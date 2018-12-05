#include <stdio.h>
#define MAXLINE 1024
#include <windows.h>
void  main ( void )
{
int c;
FILE *f1;
char *ptr;
int s=0;
char line[MAXLINE];
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole, 15);
f1 = fopen( "test.txt", "rt" );
if( f1 == NULL )
return;
 while ((c = fgetc(f1))!=EOF)
{

    if (c=='"')
    {
    s++;
    if (s%2!=0)
    SetConsoleTextAttribute(hConsole, 11);
    if (s%2==0)
    {
        printf("%c",c);
        SetConsoleTextAttribute(hConsole, 15);
        continue;
    }
    }
     printf("%c",c);
}
fclose(f1);
}
