#include <stdio.h>
#include <locale.h> //считывает текст на руском языке

void main()
{
setlocale (LC_ALL, "");
int a,b;
FILE *fpin;
fpin = fopen( "test.txt", "rt" );
if( fpin == NULL )
return;
fscanf(fpin,"%d %d",&a,&b);
int q=1;
while (q!=0)
    {
        printf ("1 - сложение\n");
        printf ("2 - вычитание\n");
        printf ("3 - умножение\n");
        printf ("4 - деление\n");
        printf ("0 - если хотите выйти\n>");
        scanf ("%d", &q);
        switch (q)
        {
        case 1:
            {
                printf("%d\n",a+b);
                break;
            }

        case 2:
            {
            printf("%d\n",a-b);
            break;
            }
        case 3:
            {
            printf("%d\n",a*b);
            break;
            }
        case 4:
            {
            printf("%d\n",a/b);
            break;
            }
            case 0: break;
            default: break;
        }
    }
}
