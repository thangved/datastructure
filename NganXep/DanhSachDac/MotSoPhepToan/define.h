#ifndef Stack
#include <stdio.h>
#include <stdlib.h>

#define MaxLength 128
typedef int ElementType;

typedef struct
{
    ElementType Elements[MaxLength];
    int Top_idx;
} Stack;
#endif