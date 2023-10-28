// TODO: add the appropriate header files here
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/ipc.h>
#include <sys/shm.h>

/**************************************************************
 *  ipc_create - creates a shared memory object called lab2 and
 *               returns a char pointer to the memory shared
 *               memory object.
 * 
 *  size - is the size of the memory object to create.
 *   
 ***************************************************************/
char* ipc_create(int size){
    /* shared memory file descriptor */
    int fd;
    /* pointer to shared memory obect */
    char* ptr;

    // TODO: create the shared memory object called lab2
    key_t key = ftok("/lab2", 1);
    int shm_id = shmget(key,size,IPC_CREAT |0666);
    if(shm_id == -1) {
        exit(1);
    }
    void*shared_memory = shmat(shm_id, NULL, 0);
    if(shared_memory == (void *)-1) {
        perror("shmat");
        exit(1);
    }
    shmdt(shared_memory); //Detach
    shmct1(shm_id, IPC_RMID, NULL); //Remove

    // TODO: configure the size of the shared memory object 
    int shmget(key_t key, size_t size, int shmflg);
    size_t size = 1024 * 1024; // 1 MB
    int shm_id = shmgt( key, size | 0666);
    // TODO: memory map the shared memory object */
    int_main();
    key_t key = ftok();
    size_t size = 1024 * 1024; //1MB
    int shm_id = shmget(); // Not sure what this is doing
    perror("shmget");
    exit(1);

    void *shared_memory = shmat(shm_id, NULL, 0);
    if(shared_memory == (void *)-1) {
        perror("shmat");
        exit(1);
    }
    strcpy(shared_memory, "Hello, Shared Memory!")

    shmdt(shared_memory);
    int fd = shm_open("lab2");
        return ptr;
    }
        printf("Data from shared memory: %s\n", (char *)mapped_memory);

        munmap(mapped_memory, size);

        close(fd);






/**************************************************************
 * ipc_close - closes the ipc communication channel that was
 *             created with ipc_create.
 * 
 **************************************************************/
void ipc_close(){
    shm_unlink("lab2");
}