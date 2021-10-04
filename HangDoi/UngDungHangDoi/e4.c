#include <stdio.h>
#include <stdlib.h>
#include "PIQueue.c"

// **** Dua thoi gian den cua khach vao hang ****
void lineUp(int letTime, int client, Queue *pQ)
{
    makenullQueue(pQ);
    for (int i = 1; i <= client; i++)
        enQueue(i * letTime, pQ);
}

// **** Dat lai thoi gian cho tung quay ****
void reset(int A[], int n)
{
    for (int i = 0; i < n; i++)
        A[i] = 0;
}

// **** Tinh tong thoi gian cho cua khach ****
int getTotalTime(int tranferTime, Queue *line, int cashiers[], int open)
{
    int totalTime = 0;
    while (!emptyQueue(*line))
    {
        for (int i = 0; i < open; i++)
        {
            if (emptyQueue(*line))
                break;
            if (cashiers[i] < front(*line))
                cashiers[i] = front(*line);
            totalTime += cashiers[i] - front(*line) + tranferTime;
            cashiers[i] += tranferTime;
            deQueue(line);
        }
    }
    return totalTime;
}

int main()
{
    // message template
    char info[] = "So quay: %d; Thoi gian cho trung binh: %.1f\n";
    char success[] = "=> Sieu thi se mo %d quay\n";
    char failed[] = "Voi %d quay hien co, khach phai cho it nhat %.1f giay moi duoc phuc vu.\n";

    int client;      // so khach hang
    int maxCashier;  // so quay toi da
    int tranferTime; // thoi gian giao dich
    int letTime;     // thoi gian khach den
    int maxWaitTime; // thoi gian cho toi da

    scanf(
        "%d%d%d%d%d",
        &client,
        &maxCashier,
        &tranferTime,
        &letTime,
        &maxWaitTime);

    Queue line;
    int cashiers[maxCashier];
    int totalTime;

    for (int open = 1; open <= maxCashier; open++)
    {
        lineUp(letTime, client, &line);
        reset(cashiers, open);

        totalTime = getTotalTime(tranferTime, &line, cashiers, open);

        // **** In thong tin voi tung so luong quay ****
        printf(info, open, (float)(totalTime / client));

        // **** Ket luan neu so quay toi da dap ung yeu cau ****
        if (totalTime / client <= maxWaitTime)
        {
            printf(success, open);
            return 0;
        }
    }

    // **** Ket luan neu failed ****
    printf(failed, maxCashier, (float)(totalTime / client));

    return 0;
}
