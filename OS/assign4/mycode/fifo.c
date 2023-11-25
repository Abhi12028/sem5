#include<stdio.h>
#include<stdlib.h>


int nf,pagefault,lrs=0, rs[20],fr[20],time=0;

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
	//printf("First ==%d",rs[-1]);
	
}
void framedisplay(){
	int i;
	printf("\n");
	for(i=0;i<nf;i++)
		printf("%d\t",fr[i]);
	
}

int searchpage(int rs)
{	
	int i;
	for (i = 0; i < nf; i++)
		if (rs == fr[i])
			return 1;
	return -1;
}

void fifo(){
	int i,j,k=0;
	for(i=0;i<lrs;i++){
		j=searchpage(rs[i]);
		if(j == -1){
			fr[k]=rs[i];
			pagefault++;
		}
		framedisplay();
		k=(k+1)%nf;
	}
	
	printf("\nTotal Number Page Fault::[%d]",pagefault);
	
}


int main()
{
	input();
	display();
	fifo();
	return 0;
}



