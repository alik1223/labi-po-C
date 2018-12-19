#include <stdio.h>
#include <locale.h>
float number()
{
  int res = 0;
  for (;;)
  {
    char c = getchar();
    if (c >= '0' && c <= '9')
      res = res * 10 + c - '0';
    else
    {
      ungetc(c,stdin);
      return res;
    }
  }
}

float expr();

float skobki()
{
  char c = getchar();
  if (c == '(')
  {
    float x = expr();
    getchar();
    return x;
  }
  else
  {
    ungetc(c,stdin);
    return number();
  }
}


float factor()
{
  float x = skobki();
  for (;;)
  {
    char c =getchar();
    switch (c)
    {
    case '*':
      x *= skobki();
      break;
    case '/':
      x /= skobki();
      break;
    default:
     ungetc(c,stdin);
      return x;
    }
  }
}
float expr()
{
  float x = factor();
  for (;;)
  {
    char c = getchar();
    switch (c)
    {
    case '+':
      x += factor();
      break;
    case '-':
      x -= factor();
      break;
    default:
    ungetc(c,stdin);
      return x;
    }
  }
}
int main()
{
    setlocale(LC_ALL, "Rus");
    printf("Vvedite viragenie: ");
    float res=expr();
    printf("Result: %f",res);

}
