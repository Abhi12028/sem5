#include<stdio.h>
#include<stdlib.h>

struct frame{
	int value,count;
}fr[20];

int rs[20],nf,lrs ;

void input()
{
	int rs1=0;
	printf("\nEnter total number of frames : ");
	scanf("%d",&nf);
	printf("\nEnter reference string :");
	while(rs1!=-1)
	{
		scanf("%d",&rs1);
		if(rs1!=-1)
			rs[lrs++]=rs1;
	}
}
void display()
{
	int i;
	printf("\nTotal Number of Frames : %d",nf);
	printf("\nReferences String :");
	for(i=0;i<lrs;i++)
		printf("%d\t",rs[i]);
	printf("\nLenght of Reference String : %d\n",lrs);
}

int searchPageLRU(int page){
	for(int i=0;i<nf;i++){
		if(page==fr[i].value)
			return i;
	}
	return -1;
}

int getlru(){
	int min=999,i,val;
	for(i=0;i<nf;i++){
		if(fr[i].count < min){
			min=fr[i].count;
			val=i;
		}
	}
	return val;
}

void lru(){
	int j,i,k,d ,time=1 ,pagefault=0;
	for(i=0,k=0;i<lrs;i++){
		j=searchPageLRU(rs[i]);
		//printf("j value :%d\n",j);
		if(j == -1){
			fr[k].value=rs[i];
			fr[k].count=time;
			time++;
			k++;
			pagefault++;
			if(k==nf)
				break;
		}
		else{
			fr[j].count=time;
			time++;
		}
		for(d=0;d<nf;d++)
			printf("%d\t",fr[d].value);
		printf("\n");
	}	
	
	while(i<lrs){
		j=searchPageLRU(rs[i]);
		//printf("j  new value :%d\n",j);
		if(j == -1){
			k=getlru();
			fr[k].value=rs[i];
			fr[k].count=time;
			time++;
			i++;
			pagefault++;
		}
		else{
			fr[j].count=time;
			time++; i++;
		}
		for(d=0;d<nf;d++)
			printf("%d\t",fr[d].value);
		printf("\n");
		
	}
	printf("\nTotal no of page fault : %d\n",pagefault);
	
}

int main(){
	input();
	display();
	lru();
}
