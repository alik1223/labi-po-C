#include <stdio.h>
#define MAXLINE 1024
#include <windows.h>
void  main ( void )
{
int i=0;
int sum;
int flag=0;
FILE *f1;
char *ptr;
int j;
char line[MAXLINE];
HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
SetConsoleTextAttribute(hConsole, 15);
f1 = fopen( "test.txt", "rt" );
if( f1 == NULL )
return;
while( !feof( f1) )
{
ptr = fgets( line, MAXLINE, f1 );
if( ptr == NULL )
break;
i=0;
while(line[i]!= '\0' )
{
if (line[i]=='"' && flag==1)
{
SetConsoleTextAttribute(hConsole, 11);
for(j;j<=i;j++)
printf("%c",line[j]);
flag=0;
SetConsoleTextAttribute(hConsole, 15);
i++;
}
if (line[i]=='"')
{
    flag=1;
    j=i;
}
if (flag==0)
printf("%c",line[i]);
i++;
}
if (flag==1)
{
    for (j;j<i;j++)
    printf("%c",line[j]);
    flag=0;
}
}
fclose(f1);
}

