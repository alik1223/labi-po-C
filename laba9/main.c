#include <stdio.h>
void main(void)
{
    char line[100];
    int i;
    int start; // ������� ������ �����
    int stop; // ������� ����� �����
    int flag; // ������� �����
    int sum;//����� ���� � �����
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
        if (flag==1) // ������ ������ ��������� ����� �����
        {

            stop=i-1;
            if (sum%2!=0)
            {
            k = start;
            for(j = stop+1; line[j] !='\0'; j++)// �������� ����� (������� ����������  ����� ������)
            {
                line[k]=line[j];
                k++;
            }
            line[k]='\0';
            i=start; //������ ��������� ������ �  ������������ ���������
            }
        }
        flag=0;
        sum=0;
    }
    else
    {
      if (flag==0)
      {
      start=i; // ��������� ������� ������ �����
      }
      sum++;
      flag=1;
    }
    i++;
    }
    while( c!= '\0' );
 puts(line);
}






