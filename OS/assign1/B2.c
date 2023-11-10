#include<stdio.h>
#include<unistd.h>

int main(){
	
	int pid, ppid;
	pid = fork();
	ppid =getppid();
	printf("Current ID:%d Parent ID:%d\n",pid,getppid());
	
	if(pid== 0){
		sleep(2);
		printf("\n Child process is created \n Process ID child : %d\n",pid);
		ppid=getppid();
		if(ppid ==1){
			printf("Parent process is terminated now and\n child process is orphan\n");
		}
		else{
			printf("Parent is still excuting ppid is %d\n",ppid);
		}
	}
	else{
		printf("Parent is excuting first \n ID is :%d\n\n",getpid());
	}
	return 0;
}
