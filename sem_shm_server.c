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

#define NUMMSG 2                /* Server does only "receives" on shm segment */

int main(int argc, char *argv[]) {
  int rc, semid, shmid, i;
  key_t semkey, shmkey;
  void *shm_address;
  struct sembuf operations[2];
  struct shmid_ds shmid_struct;
  short sarray[NUMSEMS];

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

  /* Create a semaphore set using the IPC key. */
  semid = semget(semkey, NUMSEMS, 0666 | IPC_CREAT | IPC_EXCL);
  if(-1 == semid) {
    printf("main: semget() failed\n");
    return -1;
  }
  
  /* Intialize the fisrt semaphore in the set to 0 and the
   * second semaphore in the set to 0.                     
   * 
   * The first semaphore means:
   *    '1' -- The shared memory segment is being used.
   *    '0' -- The shared memory segment is freed.
   * The second semaphore means:
   *    '1' -- The shared memory segment has been changed by
   *           the client.
   *    '0' -- The shared memory segment has not been 
   *           changed by the client.
   */
  sarray[0] = 0;
  sarray[1] = 0;

  /* The '1' on this command is a no-op, because the SETALL command
   * is used.
   */
  rc = semctl(semid, 1, SETALL, sarray);
  if(-1 == rc) {
    printf("main: semctl() init failed\n");
    return -1;
  }

  /* Create a shared memory segment using IPC key. */
  shmid = shmget(shmkey, SIZEOFSHMSEG, 0666 | IPC_CREAT | IPC_EXCL);
  if(-1 == shmid) {
    printf("main: shmget() failed\n");
    return -1;
  }

  /* Attach the shared memory segment to the server process. */
  shm_address = shmat(shmid, NULL, 0);
  if(NULL == shm_address) {
    printf("main: shmat() failed\n");
    return -1;
  }

  printf("Ready for client jobs\n");

  for(i = 0; i < NUMMSG; ++i) {
    /* Set the sturcture passed to semop() to first wait
     * for the second semval to equal 1, then decrement it to 
     * allow the next signal that the client writes to it.
     * Next, set the first semaphore to equal 1, which means
     * that the shared memory segment is busy.
     */
    operations[0].sem_num = 1;
    operations[0].sem_op = -1;
    operations[0].sem_flg = 0;

    operations[1].sem_num = 0;
    operations[1].sem_op = 1;
    operations[1].sem_flg = IPC_NOWAIT;

    rc = semop(semid, operations, 2);
    if(-1 == rc) {
      printf("main: semop() failed\n");
      return -1;
    }

    /* Print the shared memory contents. */
    printf("Server received: \"%s\"\n", (char*) shm_address);

    /* Signal the first semaphore to free shared memory. */
    operations[0].sem_num = 0;
    operations[0].sem_op = -1;
    operations[0].sem_flg = IPC_NOWAIT;

    rc = semop(semid, operations, 1);
    if(-1 == rc) {
      printf("main: semop() failed\n");
      return -1;
    }
  }

  /* Clean up */
  rc = semctl(semid, 1, IPC_RMID);
  if(-1 == rc) {
    printf("main: semctl() remove id failed\n");
    return -1;
  }

  rc = shmdt(shm_address);
  if(-1 == rc) {
    printf("main: shmdt() failed\n");
    return -1;
  }
  
  rc = shmctl(shmid, IPC_RMID, &shmid_struct);
  if(-1 == rc) {
    printf("main: shmctl() remove id failed\n");
    return -1;
  }
  
  return 0;
}
