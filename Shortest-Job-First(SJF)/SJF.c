#include<stdio.h>
int main(){
	int n;
	int bt[20],tat[20],p[20],wt[20];
	float avg_wt=0,avg_tat=0;
	
	printf("Number of Processes: ");
	scanf("%d",&n);
	
	printf("Enter Burst Time For Each Process: \n");
	for(int i=0;i<n;i++){
		printf("P%d : ",i+1);
		scanf("%d",&bt[i]);
		p[i]=i+1;
	}
	
	// sort according to burst time.
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(bt[i]>bt[j]){
				
				int temp=bt[i];
				bt[i]=bt[j];
				bt[j]=temp;
				
				temp=p[i];
				p[i]=p[j];
				p[j]=temp;
			}
		}
	}
	
	wt[0]=0;
	for(int i=1;i<n;i++){
		wt[i]=wt[i-1]+bt[i-1];
	}
	
	for(int i=0;i<n;i++){
		tat[i]=bt[i]+wt[i];
	}
	
	printf("\n---------------SJF Scheduling---------------\n");
	printf("Process\tBurst\tWaiting\tTurnAround\n");
	for(int i=0;i<n;i++){
		printf("P%d\t%d\t%d\t%d\n",p[i],bt[i],wt[i],tat[i]);
		avg_wt+=wt[i];
		avg_tat+=tat[i];
	}
	
	avg_wt/=n;
	avg_tat/=n;
	printf("\nAverage Waiting Time : %.2f\n",avg_wt);
	printf("Average Turn Around Time : %.2f\n",avg_tat);
	return 0;
}
