#include <stdio.h>
int main()
{
    int i, j;
    int A[1000], B[1000];

    int n;
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    int m;
    scanf("%d", &m);
    for (j = 0; j < m; j++)
    {
        scanf("%d", &B[j]);
    }

    int C[1000];
    int size = 0;
    i = 0, j = 0;

    while (size < n + m)
    {
        if (A[i] > B[j] || i >= n)
        {
            C[size] = B[j];
            j++;
            size++;
        }
        else
        {
            C[size] = A[i];
            i++;
            size++;
        }
    }
    for (i = 0; i < size; i++)
    {
        printf("%d ", C[i]);
    }
    return 0;
}