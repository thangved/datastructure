// do dai toi da
#define MaxLength 100;

// kieu phan tu
typedef int ElementType;

// kieu Queue
typedef struct
{
    ElementType Elements[MaxLength];
    int Front, Rear;
}
Queue;
