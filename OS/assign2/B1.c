#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 1024

void dirfunction(char fname[], char token){
		char newcmd[max];
		switch(token){
			case 'f':
				char cmd[]="ls ";
				printf("Printing file in directory:\n");
				//printf("%s\n",strcat(cmd ,fname));
				system("cd");
				system(strcat(cmd,fname));
				break;
			case 'n':
				printf("Printing numnber of file and subdirectory in directory:\n ");
				system("ls -q | wc -l");
				break;
			case 'i':
				printf("Printing inode of file in directory:\n");
				system("ls -i");
				break;
			}
	return;
}

int main(){
	char cmd[max],token, fname[max];
	int i=0 ,j=0,count=0; 
	while(cmd){
		printf("\nmyshell$: ");
		fgets(cmd, sizeof(cmd), stdin); 
		
		// Remove the newline character from the input.
		 if (cmd[strlen(cmd) - 1] == '\n') {
            		cmd[strlen(cmd) - 1] = '\0';
        	}
		
		token = cmd[5]; // this will give token name
		for(i=7;i<strlen(cmd);i++){
			fname[j]=cmd[i];//this will give filename
			j++;
		}
		
		printf("count=%d\n",count++);
		if(token == 'f' || token == 'n' || token == 'i'){
			dirfunction(fname,token);
		}
		
		
		if(cmd=="exit")
			break;
	}
}	
