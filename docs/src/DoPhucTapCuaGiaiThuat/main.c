void sort(int A[])
{
    int length = sizeof(A) / sizeof(int);

    for (int i = 0; i < length; i++)
        for (int j = i + 1; i < length; i++)
            if (A[i] > A[j])
            {
                int t = A[i];
                A[i] = A[j];
                A[j] = t;
            }
}