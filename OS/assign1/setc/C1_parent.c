#include<stdio.h>
#include<stdlib.h>
#include <stdbool.h>
#include<time.h>
#include <unistd.h> 

void disarray(int arr[] , int size){
	printf("\n Printing Array::...");
	for(int i=0;i<size;i++)
		printf("  %d",arr[i]);
	printf("\n");
}

void ranarray(int arr[] , int size){
	srand(time(0));
	printf("\n\n Accepting Array::...\n Enter\n");
	for(int i=0;i<size;i++)
		//scanf("%d",&arr[i]);
		arr[i]=rand()%10;
}

void swap(int* xp, int* yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}
 
// An optimized version of Bubble Sort
void bubbleSort(int arr[], int n)
{
    int i, j;
    bool swapped;
    for (i = 0; i < n - 1; i++) {
        swapped = false;
        for (j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(&arr[j], &arr[j + 1]);
                swapped = true;
            }
        }
 
        // If no two elements were swapped by inner loop,
        // then break
        if (swapped == false)
            break;
    }
}



int main(){
	int pid,*arr[20],size,num;
	printf("\n Enter size of array::\n");
	scanf("%d",&size);
	
	ranarray(arr,size);
	disarray(arr,size);
	
	
	pid=fork();
	
	if(pid==0){
		printf("CHILD PROCESS---------\n");
		char* args[] = {"",NULL};
		
		execve(args[0],arr,NULL);
	}
	else{
		printf("\nParent process has sorted array"); 
		bubblesort(arr,size);
		disarray(arr,size);
	}
	
	
	return 0;
	
}



