#include <stdio.h>

int main()
{
    int seconds, minutes, hours;

    scanf("%dh%dm%ds", &hours, &minutes, &seconds);

    seconds = seconds + minutes * 60 + hours * 3600;

    printf("So giay: %d\n", seconds);

    return 0;
}
