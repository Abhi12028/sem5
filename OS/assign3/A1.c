#include<stdio.h>

void Acceptime(int *arr,int size){
	int num;
	for(int i=0;i<size;i++){
		scanf("%d",&num);
		arr[i]=num;
		printf("\v");
	}
}
void displaytime(int *arr,int size){
	int num;
	for(int i=0;i<size;i++){
		printf("%d\t",arr[i]);
	}
	printf("\n");
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
  	displaytime(AT,max);
  	printf("\nAccepting Burst time:\n");
  	Acceptime(BT,max);
  	displaytime(BT,max);
  	
  	printf("\nPrinting Completion time:\n");
  	completiontime(AT,BT,CT,max);
  	displaytime(CT,max);
  	
  	for(int i=0;i<max;i++){
  		TAT[i] = CT[i] - AT[i];
  		WT[i] = TAT[i] - BT[i];
  	}
  	
  	printf("\nPrinting Turnaround time:\n");
  	displaytime(TAT,max);
  	printf("\nPrinting Waiting time:\n");
  	displaytime(WT,max);
  		
}
