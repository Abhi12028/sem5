#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define max 1024

void lineread(char *fname, char token) {
    FILE *fp;
    char buffer[max];
    if ((fp = fopen(fname, "r")) == NULL) {
        printf("Error in reading file\n");
        return;
    }

    switch (token) {
        case 'n':
            int length;
            printf("Number of lines to print: ");
            scanf("%d", &length);
            int i = 0;
            while (fgets(buffer, sizeof(buffer), fp) && i < length) {
                printf("%s", buffer);
                i++;
            }
            break;

        case 'r':
            // Implement 'r' functionality here
            printf("Option 'r' is not implemented yet.\n");
            break;

        case 'a':
            while (fgets(buffer, max, fp)) {
                printf("%s", buffer);
            }
            break;
    }

    fclose(fp);
}

int main() {
    char cmd[max], token, *fname;
    printf("Welcome to MyShell!\n");
    while (1) { // Infinite loop until an exit condition is met.
        printf("myshell$: ");
        fgets(cmd, sizeof(cmd), stdin);
        if (cmd[strlen(cmd) - 1] == '\n') {
            cmd[strlen(cmd) - 1] = '\0'; // Remove the newline character.
        }
        token = cmd[0]; // First character of the command.
        fname = &cmd[2]; // Assuming the file name starts at the third character.

        if (strcmp(cmd, "exit") == 0 || strcmp(cmd, "quit") == 0) {
            printf("Exiting MyShell.\n");
            break; // Exit the loop.
        } else if (token != '\0' && fname != NULL) {
            lineread(fname, token);
        } else {
            printf("Invalid command format. Please use 'n', 'r', or 'a' followed by a file name.\n");
        }
    }

    return 0;
}

