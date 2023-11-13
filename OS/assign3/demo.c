#include<stdio.h>
#include<stdlib.h>

typedef struct process{
	int AT,BT,CT,TAT,WT,status; //statusshow is process 1=executed or 0=not
}process;

typedef struct readyQueue{
	int AT,BT,status,position; //statusshow is process 1=executed or 0=not
}readyQueue;// i value is position of process in pcb

int timer=4; //global cpu timer counter


void AcceptArrivalTime(process *pro, readyQueue *ready,int size){
	int num;
	printf("\n");
	for(int i=0;i<size;i++){
		pro[i].CT=0;
		pro[i].TAT=0;
		pro[i].WT=0;
		pro[i].status=0;
		
		ready[i].AT=0;
		ready[i].BT=0;
		ready[i].status=0;
		ready[i].position=0;
		
		scanf("%d",&pro[i].AT);
		ready[i].AT=pro[i].AT;
		
	}
}
void AcceptBurstTime(process *pro,readyQueue *ready,int size){
	int num;
	printf("\n");
	for(int i=0;i<size;i++){
		scanf("%d",&pro[i].BT);
		ready[i].BT=pro[i].BT;
		
	}
}
void displaytime(process *pro,int size){
	int num ,totalTAT=0,totalWT=0;
	float avgTAT=0,avgWT=0;
	printf("Process\tAT\tBT\tCT\tTAT\tWT\tStatus\n");
	for(int i=0;i<size;i++){
		printf("P%d\t%d\t%d\t%d\t%d\t%d\t%d\n",i,pro[i].AT,pro[i].BT,pro[i].CT,pro[i].TAT,pro[i].WT,pro[i].status);
		totalTAT=totalTAT+pro[i].TAT;
		totalWT=totalWT+pro[i].WT;
	}
	avgTAT=(float)totalTAT/size;
	avgWT=(float)totalWT/size;
	printf("\naAverage Turnaround Time:%.2f",avgTAT);
	printf("\naAverage Waiting Time:%.2f\n",avgWT);
}



readyQueue* lowestNum(readyQueue* ready, int max ){
	readyQueue *min;
	min = (readyQueue*)malloc(sizeof(readyQueue));
	 min->BT= ready[0].BT;
	
	for(int i=0;i<max;i++){
		if(ready==NULL){
			return NULL ;
		}
		else if(min->BT>ready[i].BT){
			min=&ready[i];
			ready[i].AT= 0;
			ready[i].BT= 0;
			ready[i].status = 0;
			ready[i].position=0;
		}
		else;
	}
	return min;
}

int termination(process* pro, int size){
	for(int i=0;i<size;i++){
		if(pro[i].status==0)
			return 0;
	}
	return 1;
}

//void swap(int)

void readyState(readyQueue *ready ,process* pro, int size , int iteration){
	
	int temp=0;
	for(int i=0;i<size-1;i++){
		for(int j=0;j< size-1-i;j++){
			if(ready[j].AT >ready[j+1].AT){
				//swap(ready[j].AT ,ready[j+1].AT);
				temp = ready[j].AT;
				ready[j].AT = ready[j+1].AT;
				ready[j+1].AT = temp;
				
				temp = ready[j].BT;
				ready[j].BT = ready[j+1].BT;
				ready[j+1].BT = temp;
				
				
			}
			/*else if(ready[j].AT = ready[j+1].AT){
				//swapWithCheck(ready[j].BT ,ready[j+1].BT);
				if(ready[j].BT > ready[j+1].BT){
					temp = ready[j].BT;
					ready[j].BT = ready[j+1].BT;
					ready[j+1].BT = temp;
				}
				else{
					temp = ready[j+1].BT;
					ready[j+1].BT = ready[j].BT;
					ready[j].BT = temp;
				}
						
			}
			else;*/
			
		}
	}
}

void completiontime(process* pro, readyQueue* ready,int size){
	/*int timer=0,i=0;
	readyQueue *min =NULL;
	min = (readyQueue*)malloc(sizeof(readyQueue));
	
	while(1){
		readyState(ready,pro,size);
		
		if(ready[i].AT <= timer && ready[i].status == 0){
			min = lowestNum(ready, size );
			pro[i].CT= timer+ pro[min->position].BT;
			timer=pro[i].CT;
			i++;
		}
		else{
			timer++;
		}
		if(termination(pro,size)==1){
			break;
		}
		
	}
	printf("\n");*/
	
	//printf("Hello World\n");
	
	for(int i=0;i<size;i++){
		readyState(ready ,pro,size,i);
		if(ready[i].status == 0)
			pro[i].CT= ready[i].BT + timer;
		timer++;
	}
	
	
	
	
	
}


int main(){
	
  	int max;
  	printf("Enter number of processes to execute:");
	scanf("%d",&max);
	
	process pro[max];// initiating process and readyqueue
	readyQueue ready[max];
	
	printf("\nAccepting arrival time:\n");
  	AcceptArrivalTime(pro,ready,max);
  	printf("\nAccepting Burst time:\n");
  	AcceptBurstTime(pro,ready,max);
  	
  	//displaytime(pro,max);
  	
  	
  	//readyState(ready,pro,max);
  	
	//completiontime( pro,ready, max);
  	displaytime(pro,max);
  	printf("AT\tBT\n");
  	for(int i=0;i<max;i++){
		printf("%d\t%d\n",ready[i].AT,ready[i].BT);
	}
  	readyState(ready ,pro, max ,0);
  	printf("\n\nAT\tBT\n");
  	for(int i=0;i<max;i++){
		printf("%d\t%d\n",ready[i].AT,ready[i].BT);
	}

}

