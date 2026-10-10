#include <stdio.h>
int main() {
    int n, i, time = 0, completed = 0;
    int at[20], bt [20], ct[20], tat[20], wt[20];
    int visited[20] = {0};
   printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++) {
        printf("Enter Arrival Time of P%d: ", i + 1);
        scanf("%d", &at[i]);

        printf("Enter Burst Time of P%d: ", i + 1);
        scanf("%d", &bt[i]);
    }
while(completed < n) {
        int idx = -1;
        int minBT = 9999;

        for(i = 0; i < n; i++) {
            if(at[i] <= time && visited[i] == 0 && bt[i] < minBT) {
                minBT = bt[i];
                idx = i;
            }
        }

        if(idx == -1) {
            time++;


 } else {
            ct[idx] = time + bt[idx];
            time = ct[idx];
            tat[idx] = ct[idx] - at[idx];
            wt[idx] = tat[idx] - bt[idx];
            visited[idx] = 1;
            completed++;
        }
    }

    float avgWT = 0, avgTAT = 0;

    printf("\nProcess\tAT\tBT\tCT\tWT\tTAT\n");

    for(i = 0; i < n; i++) {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], ct[i], wt[i], tat[i]);
        avgWT += wt[i];
        avgTAT += tat[i];
    }

    printf("\nAverage Waiting Time = %.2f", avgWT / n);

  printf("\nAverage Turnaround Time = %.2f\n", avgTAT / n);
    return 0;
}

