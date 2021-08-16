// int sum(int r, int n)
// {
//     int s, power;
//     s = 0;
//     for (int i = 0; i <= n; i++)
//     {
//         power = 1;
//         for (int j = 0; j <= i; j++)
//             power *= r;
//         s += power;
//     }
//     return s;
// }

int sum(int r, int n)
{
    int power = 1;
    for (int i = 0; i <= n + 1; i++)
        power *= r;
    return ((power - 1)) / (r - 1);
}