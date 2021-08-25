#include <stdlib.h>
#include <stdio.h>

void Insert(int x, int p, int A[], int *pn)
{
    if (sizeof(A) / sizeof(int) == *pn)
    {
    }
    else
    {
        for (int i = *pn; i > p; i--)
            A[i] = A[i - 1];

        A[p] = x;
        *pn = *pn + 1;
    }
}

int main(int argc, char const *argv[])
{
    int n = 7;
    int A[] = {1, 2, 3, 4, 5, 6, 7};

    Insert(0, 0, A, &n);

    for (int i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }

    return 1;
}
