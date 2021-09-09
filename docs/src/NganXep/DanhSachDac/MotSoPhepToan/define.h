#ifndef Stack
#include <stdio.h>
#include <stdlib.h>

#define MaxLength 100
#define M MaxLength
#define SoPhanTu M
typedef int ElementType;

typedef struct
{
    ElementType Elements[MaxLength], DuLieu[SoPhanTu];
    int Top_idx, Dinh;
} Stack;

typedef Stack NganXep;
#endif