#include<stdio.h>
int main()
{
    int n,i,time=0,remain,quantum;
    int bt[10],rt[10],wt[10],tat[10];
    printf("enter the number of processes:");
    scanf("%d",&n);
    remain=n;
    for(i=0;i<n;i++)
    {
        printf("burst time p%d:",i+1);
        scanf("%d",&bt[i]);
        rt[i]=bt[i];
    }
    printf("enter the time quantum:");
    scanf("%d",&quantum);
    while(remain!=0)
    {
        for(i=0;i<n;i++)
        {
            if(rt[i]>0)
            {
              if(rt[i]<=quantum)
              {
                  time+=rt[i];
                  rt[i]=0;
                  tat[i]=time;
                  wt[i]=tat[i]-bt[i];
                  remain--;
              }
              else
              {
                  rt[i]-=quantum;
                  time+=quantum;
              }
            }
        }
    }
    printf("\np\tBt\tWt\tTAT\n");
    for(i=0;i<n;i++)
        printf("p%d\t%d\t%d\t%d\n",i+1,bt[i],wt[i],tat[i]);
    return 0;
}
