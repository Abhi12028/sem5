#include<stdio.h>
#include<stdlib.h>

struct frame{
	int value,cnt;
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
		printf("%d\t",frame[i].value);
	
}

int searchpage(int fr){
	int i=0;
	for(i=0;i<nf;i++)
		if(fr==frame[i].value){
			return i;
		}
	return -1;
}

int getlru(){
	int min =99,i,val;
	for(i=0;i<nf;i++)
		if(frame[i].cnt <min){
			min=frame[i].cnt;
			val=i;
		}
	return val;
	
}

void lru(){
	int i,k=0,j;
	for(i=0;i<lrs;i++){
		j=searchpage(rs[i]);
		if(j==-1){
			frame[k].value=rs[i];
			frame[k].cnt=time;
			time++;
			k++;
			pagefault++;
			if(k==nf)
				break;
		}
		else{
			frame[j].cnt=time;
			time++;	
		}
		framedisplay();
	}
	
	while(i<lrs){
		j=searchpage(rs[i]);
		if(j==-1){
			k=getlru();
			frame[k].value=rs[i];
			frame[k].cnt=time;
			time++;
			i++;
			pagefault++;
		}
		else{
			frame[j].cnt=time;
			time++;	i++;
		}
		framedisplay();
	}
	printf("\nTotal Number Page Fault::[%d]",pagefault);
}


int main()
{
	input();
	display();
	lru();
	return 0;
}

