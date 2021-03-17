#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include"calc.h"
#define BUFFSIZE 100

int bufp = 0;
char buf[BUFFSIZE];

int getch()
{
    return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
    if (bufp >= BUFFSIZE)
    {
        printf("ungetch: too many characters\n");
    }
    else
    {
        buf[bufp++] = c;
    }
}

