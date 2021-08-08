void copyOddNumbers(int A[], int N, int B[], int *pM)
{
    int j = 0;
    for (int i = 0; i < N; i++)
    {
        if (A[i] % 2 != 0)
            B[j++] = A[i];
    }
    *pM = j;
}

void printList(int A[], int N)
{
    for (int i = 0; i < N; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}
