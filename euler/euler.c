#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <semaphore.h>
// #include "../lib/pid.h"
#include "../lib/mymc.h"

#define NAME "/sasssdasd"

int main(){
    int shm_fd= shm_open(NAME, O_CREAT | O_TRUNC | O_RDWR,0600);
    ftruncate(shm_fd,sizeof(RndArr)); 
    pid_t child;
    char a;
    RndArr *datas = (RndArr*)mmap(NULL,sizeof(RndArr), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    create(datas);
    datas->test();
    datas->calculate(datas,1000);



    while (scanf("%c",&a) == 1){

        if(a == 'y'){

            sem_t *sem = sem_open("name", O_CREAT, 0644,1);
                    sem_post(sem);

            child = fork();

            if(child==0)
                {

                    sem_wait(sem);

                    datas->calculate(datas,10000);
                    close(shm_fd);


                    sem_post(sem);

                    return 0;

                }

                if(child<0){
                    perror("forkerror");
                    exit(1);
                }

                //parent
                if(child>0)
                {
                    wait(NULL);
                    sem_wait(sem);

                    printf("\ne estimation = %f  trials = %d\n",datas->avr,datas->trials);
                    sem_post(sem);
                }

        }
        
    }

    shm_unlink(NAME);

    return 0;

}




