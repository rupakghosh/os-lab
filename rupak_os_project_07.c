 #include<stdio.h>
 #include<conio.h>
int bt[20],p[20],wt[20],tat[20],pr[20],i,j,n,total=0,pos,temp,avg_wt,avg_tat; 

struct structure_of_process{
	int id;
	int arrivaltime;
	int bursttime;
	char terminate;
	int rt; //response time
	int ct; // completion time
	int tat;// turn around time
	int wt; // waiting time
};
 struct structure_of_process proc[20]; // declaration of structure
 int total;
 
 int cputime;

int main()
{
	
    entry_details();
    priority_preemption();   // calling all the functions inside main function
    round_robin_s();
    
	return 0;
}

void entry_details()
{
	
	
	

	printf("\tEnter Following Details : ");
	printf("\n.....................................................................................\n");
    printf("\nEnter Total Number of Processes: \n");
    scanf("%d",&n);
	
	printf("\nProvide  Burst Time and Priority : \n");
    for(i=0;i<n;i++)
    {
       printf("\n For Fixed Premempted priority : \n");
	    printf("\nP[%d]\n",i+1);
        printf("Enter Process Burst Time:");
        scanf("%d",&bt[i]);
        printf("Enter Process Priority:");
        scanf("%d",&pr[i]);
        p[i]=i+1;           //contain process number
    }
}
void priority_preemption()
{
       for(i=0;i<n;i++) // Iterate 
    {
        pos=i;
        for(j=i+1;j<n;j++)
        {
            if(pr[j]<pr[pos])  // checking Condition
                pos=j;
        }
 
        temp=pr[i];
        pr[i]=pr[pos];  // Swapping takes place (context switching)
        pr[pos]=temp;
 
        temp=bt[i];
        bt[i]=bt[pos];  // Swapping takes place (context switching)
        bt[pos]=temp;
 
        temp=p[i];
        p[i]=p[pos];   // Swapping takes place (context switching)
        p[pos]=temp;
    }
 
    wt[0]=0;	//waiting time    for   first    process is zero
 
    //calculate  the waiting time
    for(i=1;i<n;i++)
    {
        wt[i]=0;
        for(j=0;j<i;j++)
            wt[i]+=bt[j];
 
        total+=wt[i];
    }
 
    avg_wt=total/n;      //average waiting time
    total=0;
 
    printf("\nProcess\t    Burst Time    \tWaiting Time\tTurnaround Time");
    for(i=0;i<n;i++)
    {
        tat[i]=bt[i]+wt[i];     //calculate the  turnaround time
        total+=tat[i];
        printf("\nP[%d]\t\t  %d\t\t    %d\t\t\t%d",p[i],bt[i],wt[i],tat[i]);
    }
 
    avg_tat=total/n;     // calculate average turnaround time
    printf("\n\nAverage Waiting Time=%d",avg_wt);
    printf("\nAverage Turnaround Time=%d\n",avg_tat);
}
void round_robin_s()  // function to implement round robin Algorithm
{
	printf("\n.............................................................\n");
	printf("\n For Round Robin : \n");
	int time_slices,process_id[10],need[10],waiting_time1[10],turn_around_t1[10],i1,j1,n2,n1;
    int burst_time1[10],flag[10],total_turnaround_t1=0,total_wt=0;
    float avg_wt,avg_tat;
    printf("\nEnter the number of Processes \n");
    scanf("%d",&n);
    n1=n;
    printf("\n Enter the Time Quanta:  \n");
    scanf("%d",&time_slices);
    for(i=1;i<=n;i++)
    {
        printf("\n Enter the process ID:\n");
        scanf("%d",&process_id[i]);
        printf("\n Enter the Burst Time for the process: \n");
        scanf("%d",&burst_time1[i]);
        need[i]=bt[i];
    }
    for(i=1;i<=n;i++)
    {
        flag[i]=1;
        waiting_time1[i]=0;
    }
    while(n!=0)
    {
        for(i=1;i<=n;i++)
        {
            if(need[i]>=time_slices)  //checking time quanta value to give CPU idle
            {
                for(j=1;j<=n;j++)
                {
                    if((i!=j)&&(flag[i]==1)&&(need[j]!=0))
                    waiting_time1[j]+=time_slices;
                }
                need[i]=need[i]-time_slices;
                if(need[i]==0)
                {
                    flag[i]=0;
                    n--;
                }
            }
            else
            {
                for(j=1;j<=n;j++)
                {
                    if((i!=j)&&(flag[i]==1)&&(need[j]!=0))
                    waiting_time1[j]+=need[i];
                }
                need[i]=0;
                n--;
                flag[i]=0;
            }
        }
    }
    for(i=1;i<=n1;i++)
    {
        turn_around_t1[i]=waiting_time1[i]+burst_time1[i];
        total_wt=total_wt+waiting_time1[i];
        total_turnaround_t1=total_turnaround_t1+turn_around_t1[i];
    }
    avg_wt=(float)total_wt/n1;
    avg_tat=(float)total_turnaround_t1/n1;
    printf("\n\n Process \t Process ID  \t BurstTime \t Waiting Time \t TurnaroundTime \n ");
    for(i=1;i<=n1;i++)
    {
        printf("\n %5d \t %5d \t\t  %5d  \t\t  %5d  \t\t  %5d \n", i,process_id[i],burst_time1[i],waiting_time1[i],turn_around_t1[i]);
    }
    printf("\n The average Waiting Time is: %f",avg_wt);
    printf("\n The average Turn around Time is: %f",avg_tat);
}


