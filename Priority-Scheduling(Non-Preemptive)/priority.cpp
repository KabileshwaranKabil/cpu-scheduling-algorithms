#include<stdio.h>
struct Process{
	int pid;
	int burst;
	int priority;
	int waiting;
	int turnaround;
};
int main(){
	int n;
	float avg_wt=0,avg_tat=0;
	
	printf("Number of Processes: ");
	scanf("%d",&n);
	
	struct Process p[n];
	for(int i=0;i<n;i++){
		p[i].pid=i+1;
		printf("Burst Time for P%d: ",p[i].pid);
		scanf("%d",&p[i].burst);
		printf("Priority for P%d: ",p[i].pid);
		scanf("%d",&p[i].priority);
	}
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(p[i].priority>p[j].priority){
				struct Process temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
	p[0].waiting=0;
	for(int i=1;i<n;i++){
		p[i].waiting=p[i-1].waiting+p[i-1].burst;
	}
	for(int i=0;i<n;i++){
		p[i].turnaround=p[i].waiting+p[i].burst;
		avg_wt+=p[i].waiting;
		avg_tat+=p[i].turnaround;
	}
	printf("\n******************* Priority Scheduling **********************\n");
	printf("Process\tBurst\tPriority\tWaiting\tTurnaround\n");
	for(int i=0;i<n;i++){
		printf("P%d\t%d\t%d\t%d\t%d\n",p[i].pid,p[i].burst,p[i].priority,p[i].waiting,p[i].turnaround);
	}
	printf("\tGantt Chart\n| ");
	for(int i=0;i<n;i++){
		printf("P%d | ",p[i].pid);
	}
	int time=0;
	printf("\n0");
	for(int i=0;i<n;i++){
		time+=p[i].burst;
		printf("   %d",time);
	}
	
	printf("\nAverage Waiting Time: %.2f",avg_wt/n);
	printf("\nAverage Turnaround Time: %.2f\n",avg_tat/n);
	return 0;
}
