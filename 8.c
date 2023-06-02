#include <stdio.h>
#define MAX_PROCESSES 10
#define MAX_RESOURCES 10
int main()
{
    int Max[MAX_PROCESSES][MAX_RESOURCES], alloc[MAX_PROCESSES][MAX_RESOURCES], avail[MAX_RESOURCES];
    int completed[MAX_PROCESSES], safeSequence[MAX_PROCESSES];
    int p, r, i, j, process, count = 0;
    printf("Enter the number of processes: ");
    scanf("%d", &p);
    for (i = 0; i < p; i++)
        completed[i] = 0;
    printf("Enter the number of resources: ");
    scanf("%d", &r);
    printf("Enter the Max Matrix for each process:\n");
    for (i = 0; i < p; i++)
    {
        printf("For process %d: ", i + 1);
        for (j = 0; j < r; j++)
            scanf("%d", &Max[i][j]);
    }
    printf("Enter the allocation for each process:\n");
    for (i = 0; i < p; i++)
    {
        printf("For process %d: ", i + 1);
        for (j = 0; j < r; j++)
            scanf("%d", &alloc[i][j]);
    }
    printf("Enter the Available Resources:\n");
    for (i = 0; i < r; i++)
        scanf("%d", &avail[i]);
    do
    {
        process = -1;
        for (i = 0; i < p; i++)
        {
            if (completed[i] == 0) // If not completed
            {
                process = i;
                for (j = 0; j < r; j++)
                {
                    if (avail[j] < Max[i][j] - alloc[i][j])
                    {
                        process = -1;
                        break;
                    }
                }
            }
            if (process != -1)
                break;
        }
        if (process != -1)
        {
            completed[process] = 1;
            safeSequence[count] = process + 1;
            count++;
            for (j = 0; j < r; j++)
            {
                avail[j] += alloc[process][j];
                alloc[process][j] = 0;
                Max[process][j] = 0;
            }
        }
    } while (count != p && process != -1);
    if (count == p)
    {
        printf("The system is in a safe state!\n");
        printf("Safe Sequence: < ");
        for (i = 0; i < p; i++)
            printf("%d ", safeSequence[i]);
        printf(">\n");
    }
    else
        printf("The system is in an unsafe state!\n");
    return 0;
}
