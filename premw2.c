#include<stdio.h>

int main()
{
    int n, i, time = 0, completed = 0;
    int at[20], bt[20], rt[20], pr[20];
    int ct[20], tat[20], wt[20];
    int index, minPriority;
    float avgWT = 0, avgTAT = 0;

    printf("Enter number of processes: ");
    scanf("%d", &n);

    for(i = 0; i < n; i++)
    {
        printf("Enter Arrival Time, Burst Time and Priority of P%d: ", i + 1);
        scanf("%d%d%d", &at[i], &bt[i], &pr[i]);
        rt[i] = bt[i];
    }

    while(completed < n)
    {
        index = -1;
        minPriority = 9999;

        for(i = 0; i < n; i++)
        {
            if(at[i] <= time && rt[i] > 0)
            {
                if(pr[i] < minPriority)
                {
                    minPriority = pr[i];
                    index = i;
                }
            }
        }

        if(index == -1)
        {
            time++;
        }
        else
        {
            rt[index]--;
            time++;

            if(rt[index] == 0)
            {
                completed++;
                ct[index] = time;
                tat[index] = ct[index] - at[index];
                wt[index] = tat[index] - bt[index];

                avgTAT += tat[index];
                avgWT += wt[index];
            }
        }
    }

    printf("\n---------------------------------------------------------------\n");



 printf("Process\tAT\tBT\tPR\tCT\tTAT\tWT\n");
    printf("---------------------------------------------------------------\n");

    for(i = 0; i < n; i++)
    {
        printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",
               i + 1, at[i], bt[i], pr[i],
               ct[i], tat[i], wt[i]);
    }

    printf("---------------------------------------------------------------\n");
    printf("Average Waiting Time = %.2f\n", avgWT / n);
    printf("Average Turnaround Time = %.2f\n", avgTAT / n);
    return 0;
}

