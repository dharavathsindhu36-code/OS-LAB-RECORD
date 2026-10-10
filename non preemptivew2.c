#include<stdio.h>
int main()
{
int n,i,j,temp;
int bt[10],pr[10],p[10],wt[10],tat[10];
printf("enter number of processes:");
scanf("%d",&n);
for(i=0;i<n;i++)
{
    p[i]=+1;
    printf("burst time p%d:",i+1);
    scanf("%d",&bt[i]);
}
for(i=0;i<n;i++)
{
    for(j=i+1;j<n;j++)
    {
        if(pr[i]>pr[j])
        {
            temp=pr[i];
            pr[i]=pr[j];
            pr[j]=temp;

            temp=bt[i];
            bt[i]=bt[j];
            bt[j]=temp;

            temp=p[i];
            p[i]=p[j];
            p[j]=temp;
        }
    }
}
wt[0]=0;
for(i=1;i<n;i++)
    wt[i]=wt[i-1]+bt[i-1];
printf("\np\tBT\tPR\tWT\tTAT\n");
for(i=0;i<n;i++)
{
    tat[i]=wt[i]+bt[i];
    printf("p%d\t%d\t%d\t%d\t%d\n");
}
return 0;
}
