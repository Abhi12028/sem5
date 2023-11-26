#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void search(char t2, char *t3) {
  char newstring[80];int n;
  switch (t2) {
  case 'n':
    printf("Enter line number\n");
    scanf("%d",&n);
    snprintf(newstring, sizeof(newstring), "head -n %d %s", n, t3);
    system(newstring);
    break;
  case 'r':
    printf("Enter line number\n");
    scanf("%d",&n);
    snprintf(newstring, sizeof(newstring), "tail -n %d %s",n,t3);
    system(newstring);
    break;
  case 'a':
    snprintf(newstring, sizeof(newstring), "cat %s", t3);
    system(newstring);
    break;
  }
}

int main() {
  char cmd[80], t1[10], t2[10], t3[10], t4[10];
  int n;

  while (1) {
    printf("\nmyshell$: ");
    fgets(cmd, sizeof(cmd), stdin);
    n = sscanf(cmd, "%s%s%s", t1, t2, t3);
    
    if (n == 3) {
      if (strcmp(t1, "typeline") == 0)
        search(t2[0], t3);
    }
  }
}
