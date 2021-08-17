double exp(double x, int n)
{
    double e = 1, //giá trị khởi tạo ứng với n == 0
        a = 1;    //a_0
    for (int i = 1; i <= n; i++)
    {
        a *= x / i; //a_n = a_(n-1) * x/n
        e += a;
    }
    return e;
}
int main(int argc, char const *argv[])
{
    double a = exp(1.2, 2);
    return 0;
}
