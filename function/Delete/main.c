void Delete(int p, int arr[], int *n)
{
    for (p = p; p < *n; p++)
    {
        arr[p] = arr[p + 1];
    }
    *n = *n - 1;
}

int main()
{
    int n = 4;
    int A[] = {1, 2, 3, 4};
    Delete(1, A, &n);

    return 0;
}