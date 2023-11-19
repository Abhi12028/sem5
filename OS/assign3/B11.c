#include<stdio.h>
#include <stdlib.h>

typedef struct node{
	int at,bt,tat,wt,ct,status;
	struct node* next;
}node;

node *first =NULL,*last=NULL;
int len=0;
void input(){
	node *temp;
	int at,bt;
	printf("Enter no of process: ");
	scanf("%d",&len);
	for(int i=0;i<len;i++){
		temp=(node*)malloc(sizeof(node));
		printf("At %d: ",i);
		scanf("%d",&at);
		printf("Bt %d: ",i);
		scanf("%d",&bt);
		
		temp->at=at;
		temp->bt=bt;
		temp->wt=0;
		temp->tat=0;
		temp->next=NULL;
		
		if(first==NULL)
			first=temp;
		else
			last->next=temp;
		last=temp;
	}
}

void displaytime(){
	int i=0 ,totalTAT=0,totalWT=0;
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp=first;
	float avgTAT=0,avgWT=0;
	printf("Process\tAT\tBT\tCT\tTAT\tWT\n");
	while(temp!=NULL){
	
		printf("P%d\t%d\t%d\t%d\t%d\t%d\n",i,temp->at,temp->bt,temp->ct,temp->tat,temp->wt);
		totalTAT=totalTAT+temp->tat;
		totalWT=totalWT+temp->wt;
		temp=temp->next;
		i++;
	}
	avgTAT=(float)totalTAT/len;
	avgWT=(float)totalWT/len;
	printf("\naAverage Turnaround Time:%.2f",avgTAT);
	printf("\naAverage Waiting Time:%.2f\n",avgWT);
}

void swap(node *temp1 , node *temp2){
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp=temp1;
	temp1=temp2;
	temp2=temp;
	
}

void readyq(){
	for(int i=0;i<len;i++){
		for(int j=0;j<len;j++){
			
		}
	}
}


int main()
{
	input();
	displaytime();


}
