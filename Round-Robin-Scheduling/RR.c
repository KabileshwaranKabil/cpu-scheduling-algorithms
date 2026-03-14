#include<stdio.h>
int main(){
	int n,timeQuantum;
	int bt[10],rt[10],wt[10],tat[10];
	float avg_wt=0,avg_tat=0;
	
	printf("Enter Number of Processes: ");
	scanf("%d",&n);
	for(int i=0;i<n;i++){
		printf("Burst Time for P%d: ",i+1);
		scanf("%d",&bt[i]);
		rt[i]=bt[i];
	}
	printf("Enter the Time Quantum: ");
	scanf("%d",&timeQuantum);
	
	int time=0;
	int done;
	printf("\nGantt Chart: \n|");
	do{
 	   done=1;
 	   for(int i=0;i<n;i++){
		   if(rt[i]>0){
                done=0;
                printf(" P%d |",i+1);
                if(rt[i]>timeQuantum){
  			 		time+=timeQuantum;
		            rt[i]-=timeQuantum;  
                }else{
                	time+=rt[i];
                	wt[i]=time-bt[i];
                	rt[i]=0;
				}
		   }
		}
	}while(!done);
	time=0;
	for(int i=0;i<n;i++){
		rt[i]=bt[i];
	}
	printf("\n0");
	do{
		done=1;
		for(int i=0;i<n;i++){
			if(rt[i]>0){
				done=0;
				if(rt[i]>timeQuantum){
					time+=timeQuantum;
					rt[i]-=timeQuantum;
				}else{
					time+=rt[i];
					rt[i]=0;
				}
				printf("     %d",time);
			}
		}
	}while(!done);
	for(int i=0;i<n;i++){
		tat[i]=wt[i]+bt[i];
		avg_wt+=wt[i];
		avg_tat+=tat[i];
	}
	printf("\nProcess\tBurst\tWaiting\tTurnaround\n");
	for(int i=0;i<n;i++){
		printf("P%d\t%d\t%d\t%d\n",i+1,bt[i],wt[i],tat[i]);
	}
	printf("\nAverage Waiting Time: %.2f",avg_wt/n);
	printf("\nAverage Turnaround Time: %.2f",avg_tat/n);
	return 0;
}
