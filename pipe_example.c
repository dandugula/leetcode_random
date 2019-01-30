#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

int main() {
  int pfds[2];
  
  if(pipe(pfds) == -1){
    perror("Pipe");
    exit(1);
  }

  if(!fork()){
    close(1);
    dup(pfds[1]);
    close(pfds[0]);
    execlp("ls", "ls", NULL);
  } else {
    close(0);
    dup(pfds[0]);
    close(pfds[1]);
    execlp("wc", "wc", "-l", NULL);
  }

  return 0;
}

