#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<unistd.h>

int main(){
	int pid ;
	pid=fork();
	if(pid==0)
		printf("\n I am child process \n i have no child hence 	i got process id :: %d\n\n",pid);
	else{
		//wait();
		// study wait system call
		printf("\n i am parent process \n the process id of my 	child is %d \n and mine is %d",pid,getpid());
	}
	return 0;
	
}
