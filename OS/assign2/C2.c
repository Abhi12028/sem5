#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 1024

void lineread(char *fname, char *token ){
	FILE *fp;
	char buffer[max] ,len[max] ,newstring[max]="\0";
	int length ,i=0;
	if((fp=fopen(fname,"r"))==NULL){
		printf("Error in reading file");
		return;
	}
	char count = token[0];
	//printf("count = %c",count);
	switch(count){
		case 'f':			
			/*while((ch=fgetc(fpoint))!= EOF){
				char_count++;
				if(ch == ' '|| ch=='\n' || ch=='\t'){
					if(in_word){
						word_count++;
						in_word=0;
					}
					if(ch=='\n' || ch=='\t')
						line_count++;
				}
				else{
					in_word =1;
				}
			}*/
		case 'a':
			printf("Word to search:");
			fgets(len , sizeof(len),stdin);
			if (len[strlen(len) - 1] == '\n') {  
				len[strlen(len) - 1] = '\0';
        		}
			
			strcat(newstring , "grep ");
			strcat(newstring , len);
			printf("%s\n",newstring);
			strcat(newstring," ");
			strcat(newstring,fname);
			system(newstring);
			fclose(fp);
			break; 
			
		case 'c':
			printf("Word to search:");
			fgets(len , sizeof(len),stdin);
			if (len[strlen(len) - 1] == '\n') {  
				len[strlen(len) - 1] = '\0';
        		}
			strcat(newstring , "grep -c ");
			strcat(newstring , len);
			printf("%s\n",newstring);
			strcat(newstring," ");
			strcat(newstring,fname);
			system(newstring);
			fclose(fp);
			break; 
			
	}
}

int main(){
	char cmd[max],*token=NULL, *fname ,*temp ,nullString[max] ="\0";
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
