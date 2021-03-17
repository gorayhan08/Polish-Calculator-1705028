#include<stdio.h>
#include<ctype.h>
#include<string.h>

#include"calc.h"

#define MAXVAL 100
#define BUFFSIZE 100
#define NUMBER '0'

int sp = 0;
double stack[MAXVAL];

void push(double f)
{
    if (sp < MAXVAL)
    {
        stack[sp++] = f;
    }
    else
    {
        printf("error: stack full\n");
    }
}

double pop(void)
{
    if (sp > 0)
    {
        return stack[--sp];
    }
    else
    {
        printf("error: stack empty\n");
    }

    return 0.0;
}

void view_head(void)
{
    if (sp)
    {
        printf("stack_head: %g\n", stack[sp - 1]);
    }
    else
    {
        printf("error: stack empty\n");
    }
}

void duplicate(void)
{
    double temp = pop();
    push(temp);
    push(temp);
}

void swap(void)
{
    double temp1 = pop();
    double temp2 = pop();

    push(temp1);
    push(temp2);
}

void clear(void)
{
    do
    {
        stack[sp] = 0.0;
    }
    while (sp--);
}

