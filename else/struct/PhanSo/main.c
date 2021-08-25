
struct PhanSo
{
    int TuSo, MauSo;
};

struct PhanSo nhapPhanSo()
{
    struct PhanSo a;
    scanf("%d%d", &a.TuSo, &a.MauSo);
    return a;
}

void inPhanSo(struct PhanSo a)
{
    printf("%d/%d", a.TuSo, a.MauSo);
}
