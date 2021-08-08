
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
    void *p;
    int a = 5, b = 2;
    p = &a;

    b = *((int *)p);

    return 0;
}
