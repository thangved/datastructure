
char lowCase(char c)
{
    if (c >= 'A' && c <= 'Z')
        return c + 32;

    return c;
}

int main()
{
    char c = 'A';
    c = lowCase(c);

    return 0;
}
