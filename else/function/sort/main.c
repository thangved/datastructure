#include <stdio.h>

void read(int A[], int n)
{
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
}

void swap(int *a, int *b)
{
    *a = *a + *b;
    *b = *a - *b;
    *a = *a - *b;
}

void sort(int A[], int n)
{
    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (A[i] > A[j])
                swap(&A[i], &A[j]);
}


int main()
{
    int A[1000], n;

    scanf("%d", &n);

    // GOI HAM NHAP CHO A[]
    read(A, n);

    // GOI HAM SAP XEP
    sort(A, n);

    return 0;
}