#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//sjf premitive

struct tabq{
	int at,bt,tbt,ct;
	char pname[20];
}tab[20];

struct queue{
	int start , end;
	char pname[20];
}seq[100],seq1[100];

int lenght,timeq,k=0 ,time=0 ,prev;


void input(){
	printf("Enter the number of Process::");
	scanf("%d",&lenght);
	
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
	for(i=0;i<lenght;i++)	
		if(tab[i].at <=time && tab[i].tbt!=0)
			return 1;
	return 0;

}

int getmin(){
	int i,min=99 ,position;
	for(i=0;i<lenght;i++){
		if(tab[i].at <=time && tab[i].tbt!=0 && tab[i].tbt < min){
			min=tab[i].tbt;
			position=i;
		}
	}
	return position;
}

void processinput(){
	int finish=0 ,i,j;
	
	while(finish !=lenght){
		if(arrived(time)){
			i=getmin();
			time++;
			tab[i].tbt--;
			inputdisplay();
			seq[k].start=prev;
			seq[k].end=time;
			strcpy(seq[k++].pname,tab[i].pname);
			tab[i].ct=time;
			prev=time;
			if(tab[i].tbt==0){
				finish++;
			}
		}
		else{
			time++;
			seq[k].start=prev;
			seq[k].end=time;
			strcpy(seq[k++].pname,"**");
			prev=time;
		}
	}	
	
}

void ganntchart(){
	int i,j=1;
	seq1[0]=seq[0];
	for(i=0;i<k;i++){
		if(strcmp(seq1[j-1].pname,seq[i].pname)==0){
			seq1[j-1].end=seq[i].end;
		}
		else
			seq1[j++]=seq[i];
	}
	for(i=0;i<j;i++)
        	printf("\n\n%d\t%s\t%d",
        		seq1[i].start,
        		seq1[i].pname,
        		seq1[i].end);
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
