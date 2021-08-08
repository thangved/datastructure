void Insert(int x, int p, int A[], int *pn)
{
    for (int i = *pn; i >= p && i > 0; i--)
        A[i] = A[i - 1];

    A[p] = x;

    *pn = *pn + 1;
}
