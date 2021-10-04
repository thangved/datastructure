typedef int ElementType;

#define MaxLength 100

typedef struct
{
    ElementType Elements[MaxLength];
    int Top_idx;
} Stack;

void makenullStack(Stack *pS)
{
    pS->Top_idx = MaxLength;
}

int emptyStack(Stack S)
{
    return S.Top_idx == MaxLength;
}

ElementType top(Stack S)
{
    return S.Elements[S.Top_idx];
}

void pop(Stack *pS)
{
    pS->Top_idx++;
}

void push(ElementType x, Stack *pS)
{
    pS->Top_idx--;
    pS->Elements[pS->Top_idx] = x;
}
