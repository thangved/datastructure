#define maxLength 100

typedef struct
{
    double he_so;
    int bac;
} DonThuc;

typedef DonThuc ElementType;
typedef int Position;

typedef struct
{
    ElementType A[maxLength];
    Position so_luong;
} DaThuc;