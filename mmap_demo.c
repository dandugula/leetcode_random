#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <sys/mman.h>

#define SHMEM_SIZE 128

int main () {
  char *parent_message = "hello";
  char *child_message = "goodbye";

  void *shmem = mmap(NULL, SHMEM_SIZE, PROT_READ | PROT_WRITE, 
                     MAP_ANONYMOUS | MAP_SHARED, 0, 0);
  memcpy(shmem, parent_message, sizeof(parent_message));
  
  if(!fork()) {
    printf("Child read: %s\n", shmem);
    memcpy(shmem, child_message, sizeof(child_message));
    printf("Child wrote: %s\n", shmem);

  } else {
    printf("Parent read: %d\n", shmem);
    sleep(1);
    printf("After 1s, parent read: %s\n", shmem);
  }

  return 0;
}
