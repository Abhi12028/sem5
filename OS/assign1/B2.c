#include<stdio.h>
#include<unistd.h>

int main(){
	
	int pid, ppid;
	pid = fork();
	ppid =getppid();
	printf("Current ID:%d Parent ID:%d\n",getpid(),getppid());
	
	if(pid<0)
		printf("fork failed\n");
	
	else if(pid==0){
        //child process
        	printf("\nI am child process : %d and my parent id : %d\n",getpid(),getppid());
        //wait(NULL);
        	sleep(1);
       		printf("\nI am child process : %d and my parent id : %d\n",getpid(),getppid());
    }
    	else{
        //parent process
       		printf("\nI am Parent process : %d and my parent id : %d\n",getpid(),getppid());
    	}
	return 0;
}
