#include<stdio.h>
#include<string.h>
#include<ctype.h>
#include"calc.h"

#define NUMBER '0'

int getop(char s[])
{
    int i = 0, c;

    while ((s[0] = c = getch()) == ' ' || c == '\t')
        ;

    s[1] = '\0';

    if (!isdigit(c) && c != '.' && c != '-')
    {
        return c;
    }

    if (c == '-')
    {
        int next = getch();
        if (!isdigit(next) && next != '.')
        {
            return next;
        }

        s[i] = c;
        ungetch(c = next);
    }
    else
    {
        c = getch();
    }

    if (isdigit(c))
    {
        while (isdigit(s[++i] = c = getch()))
            ;
    }

    if (c == '.')
    {
        while (isdigit(s[++i] = c = getch()))
            ;
    }

    if (c != EOF)
    {
        ungetch(c);
    }

    return NUMBER;
}

