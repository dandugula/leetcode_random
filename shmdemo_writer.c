#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#define MY_SIZE 1024 /* A 1K Memory segment */

int main(int argc, char* argv[]) {
  key_t key;
  int shmid;
  char *data;
  int mode;

  if(argc > 2) {
    fprintf(stderr, "usage: shmdemo [data_to_write]\n");
    exit(1);
  }

  /* Generate the key */
  if((key = ftok("shmdemo_writer.c", 'R')) == -1) {
    perror("ftok");
    exit(1);
  }

  /* Connect to (and possibly create) the segment */
  if((shmid = shmget(key, MY_SIZE, 0644 | IPC_CREAT)) == -1) {
    perror("shmget");
    exit(1);
  }

  /* Attach to the segment to get a pointer to it */
  data = shmat(shmid, (void *)0, 0);
  if(data == (char *)(-1)) {
    perror("shmat");
    exit(1);
  }

  /* Read or modify the segment, based on the command line arguments */
  if(argc == 2) {
    printf("Writing to the shared memory segment: \"%s\"\n", argv[1]);
    strncpy(data, argv[1], MY_SIZE);
  }

  /* Detach from the shared memory segment */
  if(shmdt(data) == -1) {
    perror("shmdt");
    exit(1);
  }

#ifdef DESTROY_SHM
  /* Destroy the shared memory segment */
  printf("Destroying the shared memory segment\n");
  if(shmctl(shmid, IPC_RMID, NULL) == -1){ 
    perror("shmctl");
    exit(1);
  }
#endif /* DESTORY_SHM */
  return 0;
}
