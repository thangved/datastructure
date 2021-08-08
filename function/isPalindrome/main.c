
int reverse(int n)
{
    int r = 0;
    while (n != 0)
    {
        r = n % 10 + r * 10;
        n /= 10;
    }
    return r;
}

int isPalindrome(int n)
{
    return n == reverse(n);
}
