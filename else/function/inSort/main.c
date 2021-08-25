#include <stdio.h>
int isSort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++)
        if (A[i] > A[i + 1])
            return 0;

    return 1;
}

int main()
{
    
}
