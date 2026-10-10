#include <stdio.h>

int main() {
    int n, at[10], bt[10], rt[10], ct[10], tat[10], wt[10];
    int i, time = 0, complete = 0, min, shortest;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("AT BT of P%d: ", i + 1);
        scanf("%d%d", &at[i], &bt[i]);
        rt[i] = bt[i];
    }

    while(complete < n) {
        min = 9999;
        shortest = -1;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && rt[i] > 0 && rt[i] < min) {
                min = rt[i];
                shortest = i;
            }
        }

        if(shortest == -1) {
            time++;
            continue;
        }

        rt[shortest]--;
        time++;

        if(rt[shortest] == 0) {
            complete++;
            ct[shortest] = time;
            tat[shortest] = ct[shortest] - at[shortest];
            wt[shortest] = tat[shortest] - bt[shortest];
        }
    }

    printf("\nP\tAT\tBT\tCT\tTAT\tWT\n");
    for(i = 0; i < n; i++)
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], ct[i], tat[i], wt[i]);

    return 0;
}
