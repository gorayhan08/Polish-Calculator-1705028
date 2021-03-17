#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <math.h>

#include"calc.h"

#define MAXOP 100
#define NUMBER '0'

int main(void)
{
    int type;
    double op2;
    char s[MAXOP];

    while ((type = getop(s)) != EOF)
    {
        switch (type)
        {
        case NUMBER:
            push(atof(s));
            break;

        case '+':
            push(pop() + pop());
            break;

        case '-':
            op2 = pop();
            push(pop() - op2);
            break;

        case '*':
            push(pop() * pop());
            break;

        case '/':
            op2 = pop();

            if (op2 != 0.0)
            {
                push(pop() / op2);
            }
            else
            {
                printf("error: zero divisor\n");
            }

            break;

        case '%':
            op2 = pop();

            if (op2 != 0.0)
            {
                push((int)pop() % (int)op2);
            }
            else
            {
                printf("error: zero divisor\n");
            }
            break;

        case '^':
            op2 = pop();
            push(pow(pop(), op2));
            break;

        case '~':
            push(sin(pop()));
            break;

        case 'e':
            push(exp(pop()));
            break;

        case 'h':
            view_head();
            break;

        case 'd':
            duplicate();
            break;

        case 's':
            swap();
            break;

        case 'c':
            clear();
            break;

        case '\n':
            printf("result: %.8g\n", pop());
            break;

        default:
            printf("error: unknown command %s\n", s);
            break;
        }
    }

    return 0;
}
