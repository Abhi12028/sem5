#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void search(char t2, char *t3, char *t4) {
  char newstring[80];
  switch (t2) {
  case 'f':
    snprintf(newstring, sizeof(newstring), "grep -m 1 %s %s", t4, t3);
    system(newstring);
    break;
  case 'a':
    snprintf(newstring, sizeof(newstring), "grep %s %s", t4, t3);
    system(newstring);
    break;
  case 'c':
    snprintf(newstring, sizeof(newstring), "grep -c %s %s", t4, t3);
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
    n = sscanf(cmd, "%s%s%s%s", t1, t2, t3, t4);
    if (n == 4) {
      if (strcmp(t1, "search") == 0)
        search(t2[0], t3, t4);
    }
  }
}
