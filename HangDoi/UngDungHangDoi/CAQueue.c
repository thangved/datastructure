#include <stdlib.h>

typedef int ElementType;

struct Node
{
    ElementType Element;
    struct Node *Next;
};

typedef struct Node *Position;

typedef struct
{
    Position Front, Rear;
} Queue;

void makenullQueue(Queue *pS)
{
    pS->Front = (Position)malloc(sizeof(struct Node));
    pS->Front->Next = NULL;
    pS->Rear = pS->Front;
}
int emptyQueue(Queue Q)
{
    return Q.Front == Q.Rear;
}
ElementType front(Queue Q)
{
    return Q.Front->Next->Element;
}
void deQueue(Queue *pQ)
{
    pQ->Front = pQ->Front->Next;
}
void enQueue(ElementType x, Queue *pQ)
{
    pQ->Rear->Next = (Position)malloc(sizeof(struct Node));
    pQ->Rear = pQ->Rear->Next;
    pQ->Rear->Element = x;
    pQ->Rear->Next = NULL;
}