#include<stdio.h>
#include<stdlib.h>

struct frame{
	int value,freq,cnt;
}frame[20];
int nf,pagefault,lrs=0, rs[20],time=0;

void input(){
	int temp;
	printf("Enter number of frame:: ");
	scanf("%d",&nf);
	
	printf("Enter reference String :: ");
	while(temp != -1){
		scanf("%d",&temp);
		if(temp != -1)
			rs[lrs++]=temp;
	}
}
void display(){
	int i=0;
	printf("\n\nNumber of Frame ::[%d]",nf);
	printf("\nReference String of size [%d] is :: ",lrs);
	while(i<lrs)
		printf("%d  ",rs[i++]);
	printf("First ==%d",rs[-1]);
	
}
void framedisplay(){
	int i;
	printf("\n");
	for(i=0;i<nf;i++)
		printf("%d[%d]  ",frame[i].value,frame[i].freq);
	
}

int searchpage(int fr){
	int i=0;
	for(i=0;i<nf;i++)
		if(fr==frame[i].value){
			return i;
		}
	return -1;
}

int getmfu(){
	int i,val=0,tcnt =0,at[10][10] ,mini=100;
	for(i=1;i<nf;i++){
		if(frame[i].freq >= frame[val].freq){
			val=i;
			//at[tcnt][0]=i;
			//at[tcnt][1]=frame[i].cnt;
			tcnt++;
		}
	} 
	return val;
	/*for(i=0;i<tcnt;i++){
		if(at[i][1]<mini){
			mini=at[i][1];
			val=at[i][0];
		}
	}
	return val;*/
}

void mfu(){
	int i,j,k;
	for(i=0,k=0;k<nf && i <lrs;i++){
		j=searchpage(rs[i]);
		if(j == -1){
			frame[k].value=rs[i];
			frame[k].freq=1;
			frame[k].cnt=time;
			time++;
			k++;
			pagefault++;
		}
		else{
			frame[j].freq++;
			frame[j].cnt=time;
			time++;
		}
		framedisplay();
	}
	while(i<lrs){
		j=searchpage(rs[i]);
		if(j == -1){
			k=getmfu();
			frame[k].value=rs[i];
			frame[k].freq=1;
			frame[k].cnt=time;
			time++;
			pagefault++;
			i++;
		}
		else{
			frame[j].freq++;
			frame[j].cnt=time;
			time++;
			i++;
		}
		framedisplay();
	}
	
	printf("\nTotal Number Page Fault::[%d]",pagefault);
	
}


int main()
{
	input();
	display();
	mfu();
	return 0;
}

