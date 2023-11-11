#include<stdio.h>

void Acceptime(int *arr,int size){
	int num;
	for(int i=0;i<size;i++){
		
		scanf("%d",&num);
		arr[i]=num;
		printf("\v");
	}
}
void displaytime(int *AT,int *BT,int *CT,int *TAT,int *WT,int size){
	int num ,totalTAT=0,totalWT=0;
	float avgTAT=0,avgWT=0;
	printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
	for(int i=0;i<size;i++){
		printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i,AT[i],BT[i],CT[i],TAT[i],WT[i]);
		totalTAT=totalTAT+TAT[i];
		totalWT=totalWT+WT[i];
	}
	avgTAT=(float)totalTAT/size;
	avgWT=(float)totalWT/size;
	printf("\naAverage Turnaround Time:%.2f",avgTAT);
	printf("\naAverage Waiting Time:%.2f\n",avgWT);
}

void completiontime(int *AT,int *BT,int *CT,int size){
	int timer=0;
	for(int i=0;i<size;i++){
		if(AT[i] <= timer){
			CT[i]=timer+BT[i];
			timer=CT[i];
		}
		else{
			timer=AT[i];
			i--;
		}
		
	}
	printf("\n");
}



int main(){
	int max;
	printf("Enter number of processes to execute:");
	scanf("%d",&max);
	
	int AT[max],BT[max],TAT[max],WT[max],CT[max],avgWT,avgTAT;
	
  	printf("\nAccepting arrival time:\n");
  	Acceptime(AT,max);
  	printf("\nAccepting Burst time:\n");
  	Acceptime(BT,max);
  	
  	printf("\nPrinting Completion time:\n");
  	completiontime(AT,BT,CT,max);
  	
  	for(int i=0;i<max;i++){
  		TAT[i] = CT[i] - AT[i];
  		WT[i] = TAT[i] - BT[i];
  	}
  	
  	displaytime(AT,BT,CT,TAT,WT,max);
  	
  	
}
