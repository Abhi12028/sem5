#include<sys/types.h>
#include<stdio.h>
#include<unistd.h>

int main(){
	int pid ,priority;
	pid=fork();
	if(pid==0){
		priority=nice(-20);
		printf("\n\n We have assigned high priority to child process \n\n priority::%d\n\n",priority);
		
	}
		
	else{
		priority=nice(19);
		printf("\n\n We have assigned low priority to child process \n\n priority::%d\n\n",priority);
	}
	return 0;
	
}
