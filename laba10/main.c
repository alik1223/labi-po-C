#include <stdio.h>
#define MAXLINE 1024
void main( void )
{
int i;
int j;
int I=4;
int C=5;
int F=6;
int D=7;
int flag=0;
int flag1=0;
int flag2=1;
char Int[1000]={'i','n','t',':'};
char Char[1000]={'c','h','a','r',':'};
char Float[1000]={'f','l','o','a','t',':'};
char Double[1000]={'d','o','u','b','l','e',':'};
FILE *fpin;
FILE *fpout;
char *ptr;
char line[MAXLINE];
fpin = fopen( "test.txt", "rt" );
if( fpin == NULL )
return;
fpout = fopen("result.txt", "wt" );
if( fpout == NULL )
return;
while( !feof( fpin ) )
{
ptr = fgets( line, MAXLINE, fpin );
if( ptr == NULL )
break;
for (i=0;i<MAXLINE;i++)
if (line[i]=='{')
    flag1=1;
else
    if (line[i]=='}') flag1=0;
if (flag1==1)
{
for (i=0;i<3;i++)
j=0;
for (i=0;i<3;i++)
{
    if (line[i]==Int[j])
    flag=1;
    else
    {
        flag=0;
        break;
    }
    j++;
}
j=0;
if (flag==1)
while (line[i]!='\0')
{
if (line[i]=='=')
flag2=0;
if (line[i]==';')
    flag2=1;
if (line[i]==',')
{
    Int[I]=' ';
    I++;
    flag2=1;
}
else
    if (flag2==1)
    if (line[i]!=';' && line[i]!='\n' &&  (line[i]>='a' && line[i]<='z' || line[i]>='A' && line[i]<='Z'||  line[i]==' ' || line[i]>='0' && line[i]<='9'))
    {
     Int[I]=line[i];
     I++;
    }
i++;
}
else
{
  j=0;
for (i=0;i<4;i++)
{
    if (line[i]==Char[j])
    flag=1;
    else
    {
        flag=0;
        break;
    }
    j++;
}
j=0;
if (flag==1)
while (line[i]!='\0')
{
if (line[i]=='=')
flag2=0;
if (line[i]==';')
flag2=1;
if (line[i]==',')
{
   Char[C]=' ';
    C++;
    flag2=1;
}
else
if (flag2==1)
 if (line[i]!=';' && line[i]!='\n' && (line[i]>='a' && line[i]<='z' || line[i]>='A' && line[i]<='Z'||  line[i]==' ' || line[i]>='0' && line[i]<='9'))
 {
      Char[C]=line[i];
      C++;
 }
i++;
}
else
{
 j=0;
for (i=0;i<5;i++)
{
    if (line[i]==Float[j])
    flag=1;
    else
    {
        flag=0;
        break;
    }
    j++;
}
if (flag==1)
while (line[i]!='\0')
{
if (line[i]=='=')
flag2=0;
if (line[i]==';')
flag2=1;
if (line[i]==',')
{
   Float[F]=' ';
    F++;
    flag2=1;
}
else
    if(flag2==1)
 if (line[i]!=';' && line[i]!='\n' && (line[i]>='a' && line[i]<='z' || line[i]>='A' && line[i]<='Z' ||  line[i]==' ' || line[i]>='0' && line[i]<='9'))
 {
      Float[F]=line[i];
      F++;
 }
i++;
}
else
{
	 j=0;
for (i=0;i<6;i++)
{
    if (line[i]==Double[j])
    flag=1;
    else
    {
        flag=0;
        break;
    }
    j++;
}
if (flag==1)
while (line[i]!='\0')
{
if (line[i]=='=')
flag2=0;
if (line[i]==';')
flag2=1;
if (line[i]==',')
{
    Double[D]=' ';
    D++;
    flag2=1;
}
else
if (flag2==1)
 if (line[i]!=';' && line[i]!='\n'&& (line[i]>='a' && line[i]<='z' || line[i]>='A' && line[i]<='Z' ||  line[i]==' ' || line[i]>='0' && line[i]<='9'))
 {
Double[D]=line[i];
D++;
 }
i++;
}
}
}
}
}
}
fclose(fpin);
fclose(fpout);
if (I!=4)
{
for (i=0;i<I;i++)
    printf("%c",Int[i]);
if (C!=5 || F!=6 || D!=7)
printf("\n");
}
if (C!=5)
{
for (i=0;i<C;i++)
    printf("%c",Char[i]);
if (F!=6 || D!=7)
printf("\n");
}
if (F!=6)
{
for (i=0;i<F;i++)
    printf("%c",Float[i]);
if (D!=7)
printf("\n");
}
if (D!=7)
{
for (i=0;i<D;i++)
    printf("%c",Double[i]);
}
}
