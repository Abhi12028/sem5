#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void search(char t2, char *t3) {
  char newstring[80];
  switch (t2) {
  case 'f':
    snprintf(newstring, sizeof(newstring), "ls %s", t3);
    system(newstring);
    break;
  case 'n':
    snprintf(newstring, sizeof(newstring), "ls -q %s| wc -l",t3);
    system(newstring);
    break;
  case 'i':
    snprintf(newstring, sizeof(newstring), "ls -i %s", t3);
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
    printf("%s",t3);
    if (n == 3) {
      if (strcmp(t1, "list") == 0)
        search(t2[0], t3);
    }
  }
}
