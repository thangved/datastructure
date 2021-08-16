#include <stdio.h>

// ham doc mang
void read(int A[], int n)
{
    for (int i = 0; i < n; i++)
        scanf("%d", &A[i]);
}

// ham gop
void merge(int A[], int B[], int C[], int n)
{
    int i, j, k;

    i = 0, // index cua A
    j = 0, // index cua B
    k = 0; // index cua C

    while (k < n)
    {
        if (A[i] < B[j])
            C[k++] = A[i++];
        else
            C[k++] = B[j++];
    }
}

// ham in mang
void print(int A[], int n)
{
    for (int i = 0; i < n; i++)
        printf("%d ", A[i]);
}

int main()
{
    int m, n;

    scanf("%d", &m);
    int M[m];
    read(M, m);

    scanf("%d", &n);
    int N[n];
    read(N, n);

    int O[m + n];

    merge(M, N, O, m + n);
    print(O, m + n);

    return 0;
}
