double sum(double r, int n)
{
    double power = 1;
    for (int i = 1; i <= n + 1; i++)
        power *= r;
    return (power - 1) / (r - 1);
}
int main()
{
    double a = sum(20, 2);
    return 0;
}
