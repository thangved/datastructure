double sum(double r, int n)
{
    double s, power;
    s = 0;
    for (int i = 0; i <= n; i++)
    {
        power = 1;
        for (int j = 1; j <= i; j++)
            power *= r;
        s += power;
    }
    return s;
}
