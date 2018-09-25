#include <stdio.h>
#include <conio.h>
#define YES 1
#define NO 0
#define MAXLINE 1000
void process_line( char buffer[] );
void main( void )
{
char line[MAXLINE];
gets( line );
process_line( line );
puts( line );
}
void process_line( char buffer[] )
{
char *buf_ptr;
char *end;
char *begin;
char c;
int flag;
int sum=0;
flag = NO;
buf_ptr = buffer;
begin = buffer;
end = buffer;
do
{
c = *buf_ptr;
if( c == ' ' || c == '.' || c == ',' || c == '\n' || c == '\0')
{
if( flag == YES )
{
end = buf_ptr - 1;
if( sum%2!=0)
{
char *src = end + 1;
char *dst = begin;
while( (*dst++ = *src++ ) != '\0' );
buf_ptr = begin;
}
}
flag = NO;
sum=0;
}
else
{
if( flag == NO )
begin = buf_ptr;
flag = YES;
if (c>='a' && c<='z' || c>='A' && c<='Z')
{
sum++;
}
}
buf_ptr++;
}
while( c != '\0' );
getch();
}




