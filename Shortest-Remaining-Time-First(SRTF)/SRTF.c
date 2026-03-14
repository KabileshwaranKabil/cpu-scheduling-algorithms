#include<stdio.h>
int main(){
	int n;// number of processes
	int at[20],bt[20],wt[20],tat[20],rt[20];
	
	// input number of processes
	printf("Enter the Number of Processes: ");
	scanf("%d",&n);
	
	// input processes's arrival time and burst time
	for(int i=0;i<n;i++){
		printf("Process %d \n",i+1);
		printf("\tArrival Time: ");
		scanf("%d",&at[i]);
		printf("\tBurst Time: ");
		scanf("%d",&bt[i]);
		
		rt[i]=bt[i];
	}
	rt[n]=9999;
	int smallest;
	int complete=0;// number of processes completed
	int finish_time=0;
	float avg_wt=0,avg_tat=0;
	for(int time=0;complete!=n;time++){
		smallest=n;
		for(int i=0;i<n;i++){
			if(at[i]<=time && rt[i]>0 && rt[i]<rt[smallest]){
				smallest=i;
			}
		}
		rt[smallest]--;
		if(rt[smallest]==0){
			complete++;
			finish_time=time+1;
			tat[smallest]=finish_time-at[smallest];
			wt[smallest]=tat[smallest]-bt[smallest];
			
			avg_tat+=tat[smallest];
			avg_wt+=wt[smallest];
		}
	}
	printf("\n----------- Preemptive SJF ---------------\n");
	printf("Process\tAT\tBT\tWT\tTAT\n");
	for(int i=0;i<n;i++){
		printf("P%d\t%d\t%d\t%d\t%d\n",i+1,at[i],bt[i],wt[i],tat[i]);
	}
	printf("\nAverage Waiting Time: %.2f",avg_wt/n);
	printf("\nAverage Turnaround Time: %.2f\n",avg_tat/n);
}
