#include <stdio.h>
#include <string.h>
#include "Stack.h"

int mucUutien(char op)
{
    if (op == '+' || op == '-')
        return 1;
    else if (op == '*' || op == '/')
        return 2;
}

int isNumber(char c)
{
    return c >= '0' && c <= '9';
}

int isAb(char c)
{
    return c >= 'a' && c <= 'z';
}

void pushChar(char c, char *s)
{
    s[strlen(s) + 1] = '\0';
    s[strlen(s)] = c;
}

void chuyenHauto(char *trungto, char *hauto)
{
    hauto[0] = '\0';
    Stack S;
    makenullStack(&S);

    for (int i = 0; i < strlen(trungto); i++)
    {
        if (isNumber(trungto[i]) || isAb(trungto[i]))
            pushChar(trungto[i], hauto);
        else if (trungto[i] == '(')
            push('(', &S);
        else if (trungto[i] == ')')
        {
            while (top(S) != '(')
            {
                pushChar(top(S), hauto);
                pop(&S);
            }
            pop(&S);
        }
        else if (trungto[i] == ' ')
        {
        }
        else
        {
            while (!emptyStack(S) && top(S) != '(' && mucUutien(trungto[i]) <= mucUutien(top(S)))
            {
                pushChar(top(S), hauto);
                pop(&S);
            }
            push(trungto[i], &S);
        }
    }
    while (!emptyStack(S))
    {
        pushChar(top(S), hauto);
        pop(&S);
    }
}

int main()
{
    char inExp[50], posExp[50];
    fgets(inExp, 50, stdin);
    if (inExp[strlen(inExp) - 1] == '\n')
    {
        inExp[strlen(inExp) - 1] = '\0';
    }
    chuyenHauto(inExp, posExp);
    printf("%s", posExp);
    return 0;
}
