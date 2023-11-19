#include<stdio.h>
#include <stdlib.h>

node *first =NULL,*last=NULL ,*rfirst =NULL,*rlast=NULL; //readyqueue first header ,  readylast temp node used to traverse
int len=0 ,cputime=0 ;

typedef struct node{
	int at,bt,tat,wt,ct,status;
	struct node* next;
}node;


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
		temp->status=0;
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


int readyq(){
	node *temp;
	temp=(node*)malloc(sizeof(node));
	temp=first;
	int check=0;
	while(temp !=NULL){
		if(cputime==temp->at && temp->status==0){
			if(rfirst==NULL)
				rfirst=temp;
			else
				rlast->next=temp;
			rlast=temp;
			check=1;
		}
	}
	return check;
}

void completion time(){
	node *smallest =(node*)malloc(sizeof(node));
	node *rtemp=(node*)malloc(sizeof(node));
	
	int check =0;
	while(check){
		
		check=readyq();
		rtemp=rfirst;
		smallest =rtemp;
		for(int i=0;i<len;i++){
			if(rtemp->bt > rtemp->next->bt){
				smallest =rtemp->next;
				rtemp=rtemp->next;
			}
		}rtemp=NULL;
		
		
	}
	
	
}

int main()
{
	input();
	displaytime();


}
