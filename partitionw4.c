#include <stdio.h>

void firstFit(int partitions[], int n, int processes[], int m) {
    int allocation[m];

    for (int i = 0; i < m; i++)
        allocation[i] = -1;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            if (partitions[j] >= processes[i]) {
                allocation[i] = j;
                partitions[j] = 0;   // Partition allocated
                break;
            }
        }
    }

    printf("\n--- First Fit Allocation ---\n");
    printf("Process\tSize\tPartition\n");

    for (int i = 0; i < m; i++) {
        if (allocation[i] != -1)
            printf("P%d\t%d\t%d\n", i + 1, processes[i],
                   allocation[i] + 1);
        else
            printf("P%d\t%d\tNot Allocated\n", i + 1, processes[i]);
    }
}

void bestFit(int partitions[], int n, int processes[], int m) {
    int allocation[m];

    for (int i = 0; i < m; i++)
        allocation[i] = -1;

    for (int i = 0; i < m; i++) {
        int best = -1;

        for (int j = 0; j < n; j++) {
            if (partitions[j] >= processes[i]) {
                if (best == -1 || partitions[j] < partitions[best])
                    best = j;
            }
        }

        if (best != -1) {
            allocation[i] = best;
            partitions[best] = 0;
        }
    }

    printf("\n--- Best Fit Allocation ---\n");
    printf("Process\tSize\tPartition\n");

    for (int i = 0; i < m; i++) {
        if (allocation[i] != -1)
            printf("P%d\t%d\t%d\n", i + 1, processes[i],
                   allocation[i] + 1);
        else
            printf("P%d\t%d\tNot Allocated\n", i + 1, processes[i]);
    }
}

void worstFit(int partitions[], int n, int processes[], int m) {
    int allocation[m];

    for (int i = 0; i < m; i++)
        allocation[i] = -1;

    for (int i = 0; i < m; i++) {
        int worst = -1;

        for (int j = 0; j < n; j++) {
            if (partitions[j] >= processes[i]) {
                if (worst == -1 || partitions[j] > partitions[worst])
                    worst = j;
            }
        }

        if (worst != -1) {
            allocation[i] = worst;
            partitions[worst] = 0;
        }
    }

    printf("\n--- Worst Fit Allocation ---\n");
    printf("Process\tSize\tPartition\n");

    for (int i = 0; i < m; i++) {
        if (allocation[i] != -1)
            printf("P%d\t%d\t%d\n", i + 1, processes[i],
                   allocation[i] + 1);
        else
            printf("P%d\t%d\tNot Allocated\n", i + 1, processes[i]);
    }
}

int main() {
    int n, m, choice;

    printf("Enter number of memory partitions: ");
    scanf("%d", &n);

    int partitions[n], original[n];

    printf("Enter sizes of memory partitions:\n");
    for (int i = 0; i < n; i++) {
        printf("Partition %d: ", i + 1);
        scanf("%d", &partitions[i]);
        original[i] = partitions[i];
    }

    printf("\nEnter number of processes: ");
    scanf("%d", &m);

    int processes[m];

    printf("Enter sizes of processes:\n");
    for (int i = 0; i < m; i++) {
        printf("Process %d: ", i + 1);
        scanf("%d", &processes[i]);
    }

    printf("\n1. First Fit");
    printf("\n2. Best Fit");
    printf("\n3. Worst Fit");
    printf("\nEnter your choice: ");
    scanf("%d", &choice);

    switch (choice) {
        case 1:
            firstFit(partitions, n, processes, m);
            break;

        case 2:
            bestFit(partitions, n, processes, m);
            break;

        case 3:
            worstFit(partitions, n, processes, m);
            break;

        default:
            printf("Invalid choice!\n");
    }

    return 0;
}

