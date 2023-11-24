#include<stdio.h>
#include<string.h>

struct Input
{
    char pname[10];
    int  bt,at,ct,tbt;
}tab[5];

struct Sequence
{
    int start,end;
    char pname[10];
}seq[100],seq1[20];

int finish,time,n,k,prev;

void getinput()
{
    int i;
    printf("\nEnter No.of Processes:");
    scanf("%d",&n);
    for(i=0;i<n;i++)
    {
        printf("Process name:");
        scanf("%s",tab[i].pname);
        printf("Burst time:");
        scanf("%d",&tab[i].bt);
        printf("Arrival time:");
        scanf("%d",&tab[i].at);
        tab[i].tbt = tab[i].bt;
    }
}

void printinput()
{
    int i;

    printf("\n\n\nProcess\tBT\tAT");
    for(i=0;i<n;i++)
        printf("\n%s\t%d\t%d",tab[i].pname,tab[i].tbt,tab[i].at);
    //getch();
}

void bubble()
{
    struct Input t;
    int i,j;
    for(i=0;i<n;i++)
        for(j=0;j< (n-1)-i;j++)
            if(tab[j].at>tab[j+1].at)
            {
                t = tab[j];
                tab[j] = tab[j+1];
                tab[j+1] = t;
            }
}

int arrived(int t){
	int i;
	for (i=0;i<n;i++)
		if(tab[i].at<=t && tab[i].tbt !=0)
			return 1;
	return 0;
		
}

int getmin(int t){
	int i,position,min=100;
	for(i=0;i<n;i++){
		if(tab[i].at<=t && tab[i].tbt!=0 && tab[i].tbt < min){
			min=tab[i].tbt;
			position=i;
		}
	}
	return position;
}

void processinput(){
	int finish =k =0;
	int i ,j;
	while(finish !=n){
		if(arrived(time)){
			
			i = getmin(time);
			time++;
			tab[i].tbt--;
			printinput();//for debuggung purpose
			tab[i].ct=time;
			seq[k].start=prev;
			seq[k].end=time;
			strcpy(seq[k].pname,tab[i].pname);
			k++;
			prev=time;
			if(tab[i].tbt==0){
				finish++;
			}	
		}
		else{
			time++;
			seq[k].start=prev;
			seq[k].end=time;
			strcpy(seq[k].pname,"**");
			k++;
			prev=time;
		}
	}
}

void printoutput(){
	float avgtat=0,avgwt=0;
	
	printf("\n\nProcess\tAT\tBT\tCT\tTAT\tWT\n");
	for(int i=0;i<n;i++){
		printf("%s\t%d\t%d\t%d\t%d\t%d\t\n",
			tab[i].pname,
			tab[i].at,
			tab[i].bt,
			tab[i].ct,
			tab[i].ct-tab[i].at,
			tab[i].ct-tab[i].at-tab[i].bt);
		
		avgtat += tab[i].ct-tab[i].at;
		avgwt +=  tab[i].ct-tab[i].at-tab[i].bt;	
	}
	printf("Average TurnARoundTime::%.3f",avgtat/=n);
	printf("Average WatingTime::%.3f",avgwt/=n);	
	
}

void ganntchart(){
	int i,j=1;
	seq1[0]=seq[0];
	printf("\n******************************GANNT CHART******************************\n");
	for(i=1;i<k;i++){
		if(strcmp(seq1[j-1].pname,seq[i].pname)==0){
			seq[j-1].end=seq[i].end;
		}
		else{
			seq1[j++]=seq[i];
		}
	}
	for(i=0;i<j;i++)
        	printf("\n\n%d\t%s\t%d",
        		seq1[i].start,
        		seq1[i].pname,
        		seq1[i].end);
}

int main(){
	getinput();
	printinput();
	bubble();
	printf("\nInput after Sorting\n*************************************\n");
	printinput();
	
	processinput();
	printoutput();
	
	ganntchart();
	


}

