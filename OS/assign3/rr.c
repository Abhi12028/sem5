#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct tabq{
	int at,bt,tbt,ct;
	char pname[20];
}tab[20];

struct queue{
	int start , end;
	char pname[20];
}seq[100],seq1[100];

int lenght,timeq,k=0;


void input(){
	printf("Enter the number of Process::");
	scanf("%d",&lenght);
	
	printf("Enter time Quantam::");
	scanf("%d",&timeq);
	
	for(int i=0;i<lenght;i++){
		printf("\nEnter Process Name::");
		scanf("%s",tab[i].pname);
		printf("Enter Burst time::");
		scanf("%d",&tab[i].bt);
		printf("Enter Arrival time::");
		scanf("%d",&tab[i].at);
		tab[i].tbt=tab[i].bt;
	}
}

void inputdisplay(){
	int i;
	printf("\nProcess\tAT\tBT\n");
	for(i=0;i<lenght;i++)
		printf("%s\t%d\t%d\n",tab[i].pname , tab[i].at , tab[i].bt);
	printf("\n");
}

void bubblesort(){
	int i,j;
	struct tabq temp;
	for(i=0;i<lenght;i++){
		for(j=0;j<lenght-1-i;j++){
			if(tab[j].at > tab[j+1].at){
				temp=tab[j];
				tab[j]=tab[j+1];
				tab[j+1]=temp;
			}
			
		}
	}
}

void outputdisplay(){
	int i;
	float avgwt,avgtat;
	printf("\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
	for(i =0;i<lenght;i++){
		printf("%s\t%d\t%d\t%d\t%d\t%d\n",
			tab[i].pname,
			tab[i].at,
			tab[i].bt,
			tab[i].ct,
			tab[i].ct-tab[i].at,
			tab[i].ct-tab[i].at-tab[i].bt
			);
		avgtat +=tab[i].ct-tab[i].at;
		avgwt +=tab[i].ct-tab[i].at -tab[i].bt;
	}

    printf("\n\nAverage TAT = %f",avgtat/lenght);
    printf("\n\nAverage WT = %f",avgwt/lenght);
    getchar();
	
}

int arrived(int time){
	int i;
	for(i=0;i<lenght;i++){
		if(tab[i].at <= time && tab[i].tbt !=0)
			return 1;
	}
	return 0;
}

void processinput(){
	int i,j,finish=0;
	int time=tab[0].at,prev=0;
	while(finish !=lenght){
		if(arrived(time)){
			if(tab[i].tbt!=0){
				for(int q=0;q<timeq;q++){
					time++;
					tab[i].tbt--;
					inputdisplay();
					seq[k].start=prev;
					seq[k].end=time;
					strcpy(seq[k++].pname,tab[i].pname);
					prev=time;
					tab[i].ct=time;
					if(tab[i].tbt ==0){
						finish++;
						break;
					}
				}
			}
		}
		else{
			time++;
			seq[k].start=prev;
			seq[k].end=time;
			strcpy(seq[k++].pname,"**");
			prev=time;
		}
		if(time < tab[(i+1)%lenght].at)
			i=0;
		else
			i=(i+1)%lenght;
		
				
	}	
	
}

void ganntchart(){
	int i ,j=1;
	seq1[0]=seq[0];
	for(i=0;i<k;i++){
		//printf("\n\n%d\t%s\t%d",seq[i].start,seq[i].pname,seq[i].end);
		if(strcmp(seq1[j-1].pname,seq[i].pname)==0){
			seq1[j-1].end=seq[i].end;
		}
		else{
			seq1[j++]=seq[i];	
		}
	}
	printf("\n***************Gannt chart**************");
	for(i=0;i<j;i++)
        	printf("\n\n%d\t%s\t%d",seq1[i].start,seq1[i].pname,seq1[i].end);
    	//getchar();
}

int main(){
	input();
	inputdisplay();
	bubblesort();
	printf("After Sorting Process\n");
	inputdisplay();
	processinput();
	outputdisplay();
	ganntchart();
	
	
}
