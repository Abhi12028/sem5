#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define max 1024

void fileread(char *fname, char token){
	
	int char_count=0, word_count=0, line_count=0,in_word=0;
	char ch;
	
	
	printf("%s",fname);
	
	FILE *fpoint = fopen(fname,"r");
	if(fpoint==NULL){
		printf("\nThere is error while reading file. Check file!!!\n");
		return;
	}
	
	while((ch=fgetc(fpoint))!= EOF){
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
	}
	//printf("line word::%d\n word_count::%d\n",line_count,word_count);
	switch(token){
	case 'c':
		printf("Character in give file :%d",char_count);
		break;
		
	case 'w':
		printf("Word in give file :%d",word_count);
		break;
		
	case 'l':
		printf("Line in give file :%d",line_count);
		break;
	}
	fclose(fpoint);
	return;
}

int main(){
	char cmd[max],token, fname[max];
	int i=0 ,j=0;
	while(cmd){
		printf("\nmyshell$: ");
		fgets(cmd, sizeof(cmd), stdin); 
		
		// Remove the newline character from the input.
		 if (cmd[strlen(cmd) - 1] == '\n') {
            		cmd[strlen(cmd) - 1] = '\0';
        	}
		
		token = cmd[6]; // this will give token name
		for(i=8;i<strlen(cmd);i++){
			fname[j]=cmd[i];//this will give filename
			j++;
		}
		
		if(token == 'c' || token == 'w' || token == 'l'){
			fileread(fname,token);
		}
		token ='a';// this is for making above condition false when no cmd set
		if(cmd=="exit")
			break;
	}
}
