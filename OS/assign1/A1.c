#include<sys/types.h>
#include<sys/wait.h>
#include<stdio.h>
#include<unistd.h>

int main(){
	int pid ;
	pid=fork();
	if(pid==0)
		printf("\n I am child process \n i got process id :: %d\n\n",getpid());
	else{
		//wait();
		// study wait system call
		printf("\n i am parent process \n  and mine is %d",getpid());
	}
	return 0;
	
}
