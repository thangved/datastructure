#include <stdio.h>
#include <stdlib.h>

#define MaxLength 300 // So phan tu toi da

typedef int ElementType; // Kieu du lieu cua phan tu

typedef int Position; // Position = index + 1

typedef struct
{
    ElementType Elements[MaxLength];
    Position Last;
} List;