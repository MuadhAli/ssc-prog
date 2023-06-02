#include<stdio.h>

void rr(int n, int tq, int at[], int bt[]) {
    int rt[10], wt[10], tat[10], rem = n, t = 0, i, flag = 0, twt = 0, ttat = 0;
    for (i = 0; i < n; i++) rt[i] = bt[i];
    printf("\nProcess\t| Turnaround Time | Waiting Time\n");
    while (rem != 0) {
        for (i = 0; i < n; i++) {
            if (rt[i] > 0) {
                if (rt[i] <= tq) { t += rt[i]; rt[i] = 0; flag = 1; }
                else { rt[i] -= tq; t += tq; }
                if (rt[i] == 0 && flag == 1) {
                    rem--; printf("P[%d]\t|\t%d\t|\t%d\n", i + 1, t - at[i], t - at[i] - bt[i]);
                    twt += t - at[i] - bt[i]; ttat += t - at[i]; flag = 0;
                }
            }
        }
    }
    printf("\nAverage Waiting Time: %.2f\n", (float) twt / n);
    printf("Average Turnaround Time: %.2f\n", (float) ttat / n);
}

void srtf(int n, int at[], int bt[]) {
    int rt[10], wt[10], tat[10], i, s, t = 0, rem = n, swt = 0, stat = 0;
    for (i = 0; i < n; i++) rt[i] = bt[i];
    rt[9] = 9999;
    printf("\nProcess\t| Turnaround Time | Waiting Time\n");
    while (rem != 0) {
        s = 9;
        for (i = 0; i < n; i++) {
            if (at[i] <= t && rt[i] < rt[s] && rt[i] > 0) s = i;
        }
        rt[s]--;
        if (rt[s] == 0) {
            rem--;
            printf("P[%d]\t|\t%d\t|\t%d\n", s + 1, t + 1 - at[s], t + 1 - bt[s] - at[s]);
            swt += t + 1 - bt[s] - at[s];
            stat += t + 1 - at[s];
        }
        t++;
    }
    printf("\nAverage Waiting Time: %.2f\n", (float) swt / n);
    printf("Average Turnaround Time: %.2f\n", (float) stat / n);
}
int main() {
    int c, n, at[10], bt[10], tq; // Declare tq here
    printf("Enter choice:\n1. Round Robin\n2. SRTF\n");
    scanf("%d", &c);
    printf("Enter number of processes: ");
    scanf("%d", &n);
    for (int i = 0; i < n; i++) {
        printf("Arrival time for P%d: ", i + 1);
        scanf("%d", &at[i]);
        printf("Burst time for P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }
    switch (c) {
        case 1:
            printf("Enter Time Quantum: ");
            scanf("%d", &tq);
            rr(n, tq, at, bt);
            break;
        case 2:
            srtf(n, at, bt);
            break;
        default:
            printf("Invalid choice\n");
            break;
    }
    return 0;
}