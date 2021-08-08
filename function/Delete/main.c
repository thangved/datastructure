void Delete(int p, int A[], int *pn)
{
    *pn = *pn - 1;
    for (int i = p; i < *pn; i++)
        A[i] = A[i + 1];
}
