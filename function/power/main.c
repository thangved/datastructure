double power(float a, int n)
{
    return n == 0 ? 1 : a * power(a, n - 1);
}
