#include <stdio.h>
#define MAXLINE 1024
#define N 5
void main( void )
{
FILE *fpin; // ������� ����
FILE *fpout; // �������� ����
char line[MAXLINE]; // ������� ������
char *ptr;
int sum=0;
fpin = fopen( "test.txt", "rt" ); // ������� ���� ��� ������
if( fpin == NULL )
return; // ������ ��� �������� �����
fpout = fopen("result.txt", "wt" ); // ������� ���� ��� ������
if( fpout == NULL )
return; // ������ ��� �������� �����
while( !feof( fpin ) )// ���� �� ����� �������� �����
{
ptr = fgets( line, MAXLINE, fpin ); // ������ ������
if( ptr == NULL )
break; // ���� ��������
while( *ptr != '\0' ) // ���� �� ����� ������
{
if( sum==N )
{
*ptr++ = '\n'; // ������ ������ "����� ������"
*ptr = '\0'; // ������ ������������ ������
break;
}
ptr++; // ���������� ��������� �� ������
sum++;
}
fputs( line, fpout ); // ������ ������
sum=0;
}
fclose( fpin ); // ������� ������� ����
fclose( fpout ); // ������� �������� ����
}
