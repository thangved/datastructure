void getMax(float A[], int N, float *pMaxValue, int *pMaxPos)
{
    *pMaxValue = -100000;

    for (int i = 0; i < N; i++)
        if (*pMaxValue < A[i])
        {
            *pMaxPos = i;
            *pMaxValue = A[i];
        }
}
