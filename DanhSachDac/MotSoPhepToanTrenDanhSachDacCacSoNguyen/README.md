# MỘT SỐ PHÉP TOÁN TRÊN DANH SÁCH ĐẶC CÁC SỐ NGUYÊN

## CÁC PHÉP TOÁN CƠ BẢN

### copyEvenNumbers

> Hàm chép số chẵn.

```c
void copyEvenNumbers(List list1, List *pList2)
{
    pList2->Last = 0;
    for (int i = 0; i < list1.Last; i++)
        if (list1.Elements[i] % 2 == 0)
        {
            pList2->Elements[pList2->Last] = list1.Elements[i];
            pList2->Last++;
        }
}
```
