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

void insertionSort(int arr[], int n)
{
    int i, key, j;
    for (i = 1; i < n; i++) 
    {
        key = arr[i];
        j = i - 1;
 
        /* Move elements of arr[0..i-1], 
           that are greater than key, 
           to one position ahead of 
           their current position */
        while (j >= 0 && arr[j] > key) 
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}


int main(){
	int pid,arr[20],size;
	printf("\n Enter size of array::\n");
	scanf("%d",&size);
	
	ranarray(arr,size);
	disarray(arr,size);
	
	pid=fork();
	
	if(pid==0){
		insertionSort(arr,size);
		printf("\n\n Array sorted by child is::");
		disarray(arr,size);
	}
	else{
		bubbleSort(arr,size);
		printf("\n\n Array sorted by Parent is::");
		disarray(arr,size);
	}
	return 0;
	
}



