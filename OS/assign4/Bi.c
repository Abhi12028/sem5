#include<stdio.h>
#include<stdbool.h>
bool isPagelnFrame(int key,int frame[],int numOfFrames)
{
	int i;
	for(i=0;i<numOfFrames;i++)
	{
		if(frame[i]==key)
		 return true;
	}
	return false;
}
int predictPageToReplace(int pages[],int numPages,int frame[],int numOfFrames,int index)
{
	printf("Index=%d",index);
	int result=-1,farthest=index,i;
	for(i=0;i<numOfFrames;i++)
	{
		int j;
		for(j=index;j<numPages;j++)
		{
			if(frame[i]==pages[j])
			{
				if(j>farthest)
				{
					farthest=j;
					result=i;
				}
				break;
			}
		}
		if(j==numPages)
		return i;
	}
	return(result==-1)?0:result;
}
void optimalPageReplacement(int pages[],int numPages,int numOfFrames)
{
	int frame[numOfFrames],hit=0,index=0,i;
	for(i=0;i<numPages;i++)
	{
		if(isPagelnFrame(pages[i],frame,numOfFrames))
		{
			hit++;
			continue;
		}
		if(index<numOfFrames)
			frame[index++]=pages[i];
		else
		{
			int j=predictPageToReplace(pages,numPages,frame,numOfFrames,i+1);
			frame[j]=pages[i];
		}
	}
	printf("the total no of page hit is %d\n",hit);
	printf("the total number of page fault is %d\n",(numPages-hit));
}
int main()
{
	int pages[]={1,2,3,4,2,3,1,4,2,4,1,3};
	int numPages=sizeof(pages)/sizeof(pages[0]);
	int numOfFrames=3;
	optimalPageReplacement(pages,numPages,numOfFrames);
	return 0;
}

