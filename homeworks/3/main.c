int power(int x, int n);
long long factorial(int n);

// hàm tính e^x
double exp(int x, int n)
{
    double e = 1;
    for (int i = 1; i <= n; i++)
        e += (double)power(x, i) / factorial(i);
    return e;
}

// hàm tính lũy thừa và giai thừa
int power(int x, int n)
{
    int p = 1;
    for (int i = 0; i <= n; i++)
    {
        p *= x;
    }
    return p;
}
long long factorial(int n)
{
    long long f = 1;
    for (int i = 2; i <= n; i++)
        f *= i;
    return f;
}