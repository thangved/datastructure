double power(double x, int n);
long long factorial(int n);

// hàm tính e^x
double exp(double x, int n)
{
    double e = 1; //giá trị khởi tạo ứng với n == 0
    for (int i = 1; i <= n; i++)
        e += (double)power(x, i) / factorial(i);
    return e;
}

// hàm tính lũy thừa và giai thừa
double power(double x, int n)
{
    double p = 1;
    for (int i = 1; i <= n; i++)
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