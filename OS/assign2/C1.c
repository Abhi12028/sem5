#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 1024

void lineread(char *fname, char *token ){
	FILE *fp;
	char buffer[max] ,len;
	int length ,i=0;
	if((fp=fopen(fname,"r"))==NULL){
		printf("Error in reading file");
		return;
	}
	char count = token[0];
	//printf("count = %c",count);
	switch(count){
		case 'n':			
			
			printf("Number of line to print:");
			scanf("%d",&length);
			while (fgets(buffer,max,fp)) { 
				i++; 
				if(i <= length ) 
					printf("%s", buffer);
 			}
			break;
		case 'r':
			printf("Number of line to print:");
			scanf("%c",&len);
			
			char newstring[]= "tail -n ";
			strcat(newstring,&len);
			printf("%s\n",newstring);
			strcat(newstring," ");
			strcat(newstring,fname);
			system(newstring);
			break; 
			
		case 'a':
			while(fgets(buffer,max,fp))
				printf("%s",buffer);
			break;
			
	}
}

int main(){
	char cmd[20],*token=NULL, *fname ,*temp ,nullString[max] ="\0";
	int i=0 ,j=0,count=0; 
	while(cmd){
		printf("\nmyshell$: ");
		fgets(cmd, sizeof(cmd), stdin);
		if (cmd[strlen(cmd) - 1] == '\n') {  // Remove the newline character from the input.
            		cmd[strlen(cmd) - 1] = '\0';
        	}
		strtok(cmd," ");
		token = strtok(NULL," ");
		fname = strtok(NULL," ");
		//printf("token = %s \n fname = %s\n",token,fname);
		
		if(token !=NULL)
			lineread(fname,token);
			
		i++;//returning condition
		
        	
	}
	return 0;
}
