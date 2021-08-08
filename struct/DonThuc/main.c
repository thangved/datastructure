typedef struct
{
    double he_so;
    int bac;
} DonThuc;

struct DaThuc
{
    DonThuc A[100];
    int so_luong;
};

void inDonThuc(DonThuc donThuc)
{
    printf("%.2fx^%d", donThuc.he_so, donThuc.bac);
}
