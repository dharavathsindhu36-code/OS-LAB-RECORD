#include <stdio.h>

void firstFit(int blockSize[], int m, int processSize[], int n)
{
    int allocation[n];
    int block[m];
    int i, j;

    for (i = 0; i < n; i++)
        allocation[i] = -1;

    for (i = 0; i < m; i++)
        block[i] = blockSize[i];

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (block[j] >= processSize[i])
            {
                allocation[i] = j;
                block[j] -= processSize[i];
                break;
            }
        }
    }

    printf("\nFIRST FIT\n");
    printf("Process\tSize\tPartition\n");

    for (i = 0; i < n; i++)
    {
        if (allocation[i] != -1)
            printf("P%d\t%d\t%d\n",
                   i + 1, processSize[i], allocation[i] + 1);
        else
            printf("P%d\t%d\tNot Allocated\n",
                   i + 1, processSize[i]);
    }
}

void bestFit(int blockSize[], int m, int processSize[], int n)
{
    int allocation[n];
    int block[m];
    int i, j, best;

    for (i = 0; i < n; i++)
        allocation[i] = -1;

    for (i = 0; i < m; i++)
        block[i] = blockSize[i];

    for (i = 0; i < n; i++)
    {
        best = -1;

        for (j = 0; j < m; j++)
        {
            if (block[j] >= processSize[i])
            {
                if (best == -1 || block[j] < block[best])
                    best = j;
            }
        }

        if (best != -1)
        {
            allocation[i] = best;
            block[best] -= processSize[i];
        }
    }

    printf("\nBEST FIT\n");
    printf("Process\tSize\tPartition\n");

    for (i = 0; i < n; i++)
    {
        if (allocation[i] != -1)
            printf("P%d\t%d\t%d\n",
                   i + 1, processSize[i], allocation[i] + 1);
        else
            printf("P%d\t%d\tNot Allocated\n",
                   i + 1, processSize[i]);
    }
}

void worstFit(int blockSize[], int m, int processSize[], int n)
{
    int allocation[n];
    int block[m];
    int i, j, worst;

    for (i = 0; i < n; i++)
        allocation[i] = -1;

    for (i = 0; i < m; i++)
        block[i] = blockSize[i];

    for (i = 0; i < n; i++)
    {
        worst = -1;

        for (j = 0; j < m; j++)
        {
            if (block[j] >= processSize[i])
            {
                if (worst == -1 || block[j] > block[worst])
                    worst = j;
            }
        }

        if (worst != -1)
        {
            allocation[i] = worst;
            block[worst] -= processSize[i];
        }
    }

    printf("\nWORST FIT\n");
    printf("Process\tSize\tPartition\n");

    for (i = 0; i < n; i++)
    {
        if (allocation[i] != -1)
            printf("P%d\t%d\t%d\n",
                   i + 1, processSize[i], allocation[i] + 1);
        else
            printf("P%d\t%d\tNot Allocated\n",
                   i + 1, processSize[i]);
    }
}

int main()
{
    int m, n, i;

    printf("Enter number of memory partitions: ");
    scanf("%d", &m);

    int blockSize[m];

    printf("Enter size of each partition:\n");
    for (i = 0; i < m; i++)
        scanf("%d", &blockSize[i]);

    printf("Enter number of processes: ");
    scanf("%d", &n);

    int processSize[n];

    printf("Enter size of each process:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &processSize[i]);

    firstFit(blockSize, m, processSize, n);
    bestFit(blockSize, m, processSize, n);
    worstFit(blockSize, m, processSize, n);

    return 0;
}
