#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main () {
  pid_t pid;
  int rv;

  switch(pid = fork()) {
    case -1:
      printf("Something got messed up\n");
      exit(1);
    case 0:
      printf("CHILD: This is the child process\n");
      printf("CHILD: My process id: %d\n", getpid());
      printf("CHILD: My parent's process id: %d\n", getppid());
      printf("CHILD: Enter my exit status:");
      scanf("%d", &rv);
      printf("CHILD: I am out of here!!\n");
      exit(rv);

    default:
      printf("PARENT: This is the parent process\n");
      printf("PARENT: My process id: %d\n", getpid());
      printf("PARENT: My child's process id: %d\n", pid);
      printf("PARENT: Waiting for my child to exit()....\n");
      wait(&rv);
      printf("PARENT: My child's exit status: %d\n", WEXITSTATUS(rv));
      //printf("PARENT: My child's exit status: %d\n", rv);
      printf("PARENT: I am out of here!!\n");
  }
  return 0;
}
