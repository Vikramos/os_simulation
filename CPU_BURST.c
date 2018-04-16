#include<stdio.h>
int main()
{
    int bt[20],p[20],wt[20],tat[20],i,j,n,total=0,pos,temp;
    float avg_wt,avg_tat;
    FILE *fptr;
    int num[5];
    fptr = fopen("CPU_BURST.txt", "r");
    if (fptr == NULL)
  {
        printf("Can't open file for reading.\n");
    }
    else
    {
        fscanf(fptr, "%d", &num[0]);
        fscanf(fptr, "%d", &num[1]);
        fscanf(fptr, "%d", &num[2]);
        fscanf(fptr, "%d", &num[3]);
        fscanf(fptr, "%d", &num[4]);
	
        fclose(fptr);
    }
printf("\nProcess        BurstTime");
 for(i=0;i<5;i++)
 {
 	bt[i]=num[i];
 	printf("\nP%d \t\t %3d",i+1,bt[i]);	
 }

    //sorting burst time in ascending order using selection sort
    for(i=0;i<5;i++)
    {
    //	printf("2");
        pos=i;
        for(j=i+1;j<5;j++)
        {
            if(bt[j]<bt[pos])
                pos=j;
        }
 
        temp=bt[i];
        bt[i]=bt[pos];
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];
        p[pos]=temp;
    }
    wt[0]=0;            //waiting time for first process will be zero
 
    //calculate waiting time
    for(i=1;i<5;i++)
    { 
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
    avg_wt=(float)total/5;      //average waiting time
    total=0;
    printf("\n\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<5;i++)
    { 
        tat[i]=bt[i]+wt[i];     //calculate turnaround time
        total+=tat[i];
        printf("\nP%d\t\t %d\t\t  %d\t\t\t%d",i+1,bt[i],wt[i],tat[i]);
    }
 
    avg_tat=(float)total/5;     //average turnaround time
    printf("\n\nAverage Waiting Time=%.2f",avg_wt);
    printf("\nAverage Turnaround Time=%.2f\n",avg_tat);
}

