#include<stdio.h>
int main(){
	int bt[20],wt[20],tat[20];
	int n;
	float avg_wt=0,avg_tat=0;
	
	printf("Number of Processes : ");
	scanf("%d",&n);
	
	// Burst Time for Each process.
	printf("\nEnter Burst Time for Following Each Process: \n");
	for(int i=0;i<n;i++){
		printf("P%d: ",i+1);
		scanf("%d",&bt[i]);
	}
	
	// calculate Waiting time for each process
	wt[0]=0; // 1st process doesn't waits in FCFS 
	for(int i=1;i<n;i++){
		wt[i]=wt[i-1]+bt[i-1];
	}
	
	// calculate Turn around time for each process
	for(int i=0;i<n;i++){
		tat[i]=wt[i]+bt[i];
	}
	
	printf("\n------------------FCFS Scheduling------------------\n");
	printf("Process\tBurst\tWaiting\tTurnaround\n");
	for(int i=0;i<n;i++){
		printf("P%d \t%d \t%d \t%d \n",i+1,bt[i],wt[i],tat[i]);
		avg_wt+=wt[i];
		avg_tat+=tat[i];
	}
	avg_wt/=n;
	avg_tat/=n;
	printf("\nAverage Waiting Time : %.2f\n",avg_wt);
	printf("Average Turn Around Time : %.2f\n",avg_tat);
}
