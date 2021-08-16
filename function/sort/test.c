#include <stdio.h>
int main()
{
    int n;
    scanf("%d", &n);
    int A[1000];
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &A[i]);
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = i + 1; j < n; j++)
        {
            if (A[i] > A[j])
            {
                int max = A[i];
                A[i] = A[j];
                A[j] = max;
            }
        }
    }
    int k = 1, i = 0;
    while (i < n)
    {
        if (A[i] == A[i + 1])
        {
            k++;
            i++;
        }
        else
        {
            printf("%d - %d; ", A[i], k);
            k = 1;
            i++;
        }
    }
    return 0;
}