#include <stdio.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include <sys/shm.h>

#define SEMKEYPATH "/dev/null"  /* Path used for ftok for smget key */
#define SEMKEYID 1              /* Id used on ftok for smget key */
#define SHMKEYPATH "/dev/null"  /* Path used for ftok for shmget key */
#define SHMKEYID 1              /* Id used on ftok for shmget key */

#define NUMSEMS 2               /* Num of semaphores */
#define SIZEOFSHMSEG 50         /* Size of shared memory segment */

int main(int argc, char *argv[]) {
  struct sembuf operations[2];
  void *shm_address;
  int semid, shmid, rc;
  key_t semkey, shmkey;

  /* Generate an IPC key for the semaphore set and the shared
   * memory segment.
   */
  semkey = ftok(SEMKEYPATH, SEMKEYID);
  if((key_t)-1 == semkey) {
    printf("main: ftok() for sem failed\n");
    return -1;
  }
  shmkey = ftok(SHMKEYPATH, SHMKEYID);
  if((key_t)-1 == shmkey) {
    printf("main: ftok() for shm failed\n");
    return -1;
  }
  
  /* Get the already created semaphore ID associated with key.
   * If the semaphore ID does not exist, then it will not be 
   * created, and an error will occur.
   */
  semid = semget(semkey, NUMSEMS, 0666);
  if(-1 == semid) {
    printf("main: semget() failed\n");
    return -1;
  } 

  /* Get the already created shared memory ID associated with key.
   * If the shared memory ID does not exist, then it will not be
   * created, and an error will occur.
   */
  shmid = shmget(shmkey, SIZEOFSHMSEG, 0666);
  if(-1 == shmid) {
    printf("main: shmget() failed\n");
    return -1;
  }
  
  /* Attach the shared memory segment to the client process. */
  shm_address = shmat(shmid, NULL, 0);
  if(NULL == shm_address) {
    printf("main: shmat() failed\n");
    return -1;
  }

  /* First, check to see if the first semaphore is a zero. If it
   * is not, it is busy right now. The semop() command will wait
   * for the semaphore to reach zero before running the semop().
   * When it is zero, increment the first semaphore to show that
   * the shared memroy segment is busy.
   */
  operations[0].sem_num = 0;
  operations[0].sem_op = 0;
  operations[0].sem_flg = 0;

  operations[1].sem_num = 0;
  operations[1].sem_op = 1;
  operations[1].sem_flg = 0;

  rc = semop(semid, operations, 2);
  if(-1 == rc) {
    printf("main: semop() failed\n");
    return -1;
  }
  strcpy((char*) shm_address, "Hello from client");

  /* Release the shared memory segment by decrementing the in-use
   * semaphore (the first one). Increment the second semaphore to 
   * show that the client is finished with it.
   */
  operations[0].sem_num = 0;
  operations[0].sem_op = -1;
  operations[0].sem_flg = 0;

  operations[1].sem_num = 1;
  operations[1].sem_op = 1;
  operations[1].sem_flg = 0;

  rc = semop(semid, operations, 2);
  if(-1 == rc) {
    printf("main: semop() failed\n");
    return -1;
  }

  /* Detach the shared memory segment from the current process. */
  rc = shmdt(shm_address);
  if(-1 == rc) {
    printf("main: shmd() failed\n");
    return -1;
  }
  return 0;
}
