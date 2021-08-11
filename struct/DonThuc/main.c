struct DonThuc
{
    double he_so;
    int bac;
};

// struct DaThuc
// {
//     DonThuc A[100];
//     int so_luong;
// };

void inDonThuc(struct DonThuc donThuc)
{
    printf("%.2fx^%d", donThuc.he_so, donThuc.bac);
}
