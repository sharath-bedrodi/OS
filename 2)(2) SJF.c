#include <stdio.h>

int main() {
    int bt[20], p[20], wt[20], tat[20], i, j, n, totwt = 0, tottat = 0, pos, temp;
    float avgwt, avgtat;

    printf("Enter the number of processes:");
    scanf("%d", &n);

    printf("\nEnter Burst Time:\n");
    for (i = 0; i < n; i++) {
        printf("p%d:", i);
        scanf("%d", &bt[i]);
        p[i] = i;
    }

    for (i = 0; i < n; i++) {
        pos = i;
        for (j = i + 1; j < n; j++) {
            if (bt[j] < bt[pos])
                pos = j;
        }

        temp = bt[i];
        bt[i] = bt[pos];
        bt[pos] = temp;

        temp = p[i];
        p[i] = p[pos];
        p[pos] = temp;
    }

    wt[0] = 0;
    for (i = 1; i < n; i++) {
        wt[i] = 0;
        for (j = 0; j < i; j++) {
            wt[i] += bt[j];
        }
    }

    tottat = 0;
    printf("\nProcess\tBurst Time\tWaiting Time\tTurnaround Time");
    for (i = 0; i < n; i++) {
        tat[i] = bt[i] + wt[i];
        tottat += tat[i];
        totwt += wt[i];
        printf("\np%d\t\t%d\t\t%d\t\t\t%d", p[i], bt[i], wt[i], tat[i]);
    }

    avgwt = (float)totwt / n;
    avgtat = (float)tottat / n;
    printf("\n\nAverage Waiting Time = %f", avgwt);
    printf("\nAverage Turnaround Time = %f\n", avgtat);

    return 0;
}
