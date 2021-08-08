
// int a = 10
/*
    int *p = &a;
    *p = 5;
*/

// int a = 10;
// int *p = &a;

int a = 5;
int *p = &a;
int *q = &a;

int main(int argc, char const *argv[])
{
    int a = 10;
    int *p = &a;

    *p = 5;
    int *q = p;
    *q = 6;

    return 0;
}
