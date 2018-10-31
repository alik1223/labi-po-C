#include <stdio.h>
void main()
{
int a,b;
FILE *fpin;
fpin = fopen( "test.txt", "rt" );
if( fpin == NULL )
return;
fscanf(fpin,"%d %d",&a,&b);
int q=1;
while (q!=0)
    {
        printf ("1 +\n");
        printf ("2 -\n");
        printf ("3 *\n");
        printf ("4 /\n");
        printf ("0 - vixod\n>");
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
