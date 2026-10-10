#include <stdio.h>

int main()
{
    int n, m;
    int allocation[20][20], maximum[20][20], need[20][20];
    int available[20], work[20], finish[20];
    int safeSequence[20];
    int i, j, k, count = 0, found;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    printf("Enter number of resources: ");
    scanf("%d", &m);

    printf("\nEnter Allocation Matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            scanf("%d", &allocation[i][j]);
    }

    printf("\nEnter Maximum Matrix:\n");
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            scanf("%d", &maximum[i][j]);
    }

    printf("\nEnter Available Resources:\n");
    for (i = 0; i < m; i++)
        scanf("%d", &available[i]);

    /* Calculate Need Matrix */
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
            need[i][j] = maximum[i][j] - allocation[i][j];
    }

    /* Initialize Work and Finish */
    for (i = 0; i < m; i++)
        work[i] = available[i];

    for (i = 0; i < n; i++)
        finish[i] = 0;

    /* Find Safe Sequence */
    while (count < n)
    {
        found = 0;

        for (i = 0; i < n; i++)
        {
            if (finish[i] == 0)
            {
                for (j = 0; j < m; j++)
                {
                    if (need[i][j] > work[j])
                        break;
                }

                if (j == m)
                {
                    for (k = 0; k < m; k++)
                        work[k] += allocation[i][k];

                    safeSequence[count++] = i;
                    finish[i] = 1;
                    found = 1;
                }
            }
        }

        if (found == 0)
        {
            printf("\nSystem is in an UNSAFE state.\n");
            return 0;
        }
    }

    printf("\nSystem is in a SAFE state.\n");
    printf("Safe Sequence: ");

    for (i = 0; i < n; i++)
    {
        printf("P%d", safeSequence[i]);

        if (i != n - 1)
            printf(" -> ");
    }

    printf("\n");

    return 0;
}

