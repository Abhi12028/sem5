#include <stdio.h>
#include <stdlib.h>
int frame[20], rs[20];
int nf, lrs = 0, i, j, k = 0, rs1 = 0;
int pagefault = 0;
void accept()
{
	printf("\nEnter total number of frames : ");
	scanf("%d", &nf); //nf =NUmber of Frame
	printf("\nEnter reference string (And enter -1 for end ): ");
	while(rs1 != -1)//here enter -1 for breaaking the loop
	{	
		scanf("%d", &rs1);
		if(rs1 != -1)
			rs[lrs++] = rs1; //lrs=lenght of reference string
	}
}
void display()
{
	printf("\nTotal Number of Frames : %d", nf);
	printf("\nReferences String :");
	for (i = 0; i < lrs; i++)
		printf("%d\t", rs[i]);
	printf("\nLenght of Reference String : %d", lrs);
}

void displayfifo(int frame[])
{
	printf("\n");
	for (i = 0; i < nf; i++)
		printf("%d\t", frame[i]);
	printf("\n");
}
int searchpage(int rs)
{
	for (i = 0; i < nf; i++)
		if (rs == frame[i])
			return 1;
	return -1;
}

void fifo()
{
	int i;
	for (i = 0; i < lrs; i++)
	{
		j = searchpage(rs[i]);
		if (j == -1)
		{
			frame[k] = rs[i];
			pagefault++;
		}
		displayfifo(frame);
		k = (k + 1) % nf;
	}
	printf("\nTotal no of page fault: %d\n", pagefault);
}

void main()
{
	accept();
	display();
	fifo();
}

