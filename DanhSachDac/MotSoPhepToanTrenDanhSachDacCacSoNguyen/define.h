#define MaxLength 300 // So phan tu toi da
#endif

#ifndef ElementType
typedef int ElementType; // Kieu du lieu cua phan tu
#endif

#ifndef Position
typedef int Position; // Position = index + 1
#endif

typedef struct
{
    ElementType Elements[MaxLength];
    Position Last;
} List;