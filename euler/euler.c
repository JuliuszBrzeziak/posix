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

#define NAME "/sadasd"

int main(){
    const char* name = "O3131S";
    int shm_fd= shm_open(NAME, O_CREAT | O_TRUNC | O_RDWR,0600);
    ftruncate(shm_fd,sizeof(RndArr)); 
    pid_t child;
    int childstate;
    RndArr *datar;
        //RndArr *rn = create(rn);
    //shared = rn;
    char a;
                //rn->printRA(rn);
    RndArr *datas = (RndArr*)mmap(NULL,sizeof(RndArr), PROT_READ | PROT_WRITE, MAP_SHARED, shm_fd, 0);
    create(datas);
    datas->test();
    datas->printRA(datas);



    while (scanf("%c",&a) == 1){

        if(a == 'y'){

            sem_t *sem = sem_open("name", O_CREAT, 0644,1);
                    sem_post(sem);

            child = fork();

            if(child==0)
                {
                    // usleep(500);
                    printf("\n1Entered\n");

                    sem_wait(sem);
                    printf("\n1Entered\n");
                          printf("\n1Entered\n");

                    //rn = datas;
                    datas->printRA(datas);
                    //datas = rn;
                    close(shm_fd);


                    printf("\n2EXIT\n");
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
                    printf("\n3ENTER\n");

                    datar = (RndArr*)mmap(NULL,sizeof(RndArr),PROT_READ,MAP_SHARED,shm_fd,0);
                    datar = datas;
                   // close(shm_fd);

                    printf("\n4EXIT%d\n",datas->sum);
                    sem_post(sem);
                }

        }
        
    }

    shm_unlink(NAME);

    return 0;

}




/*

    char a;

    RndArr *rn;



    int fd = shm_open(NAME, O_CREAT | O_TRUNC | O_RDWR,0666);
    if (fd == -1)
	{
		perror("open");
		return 10;
	}

    int res = ftruncate(fd, sizeof(RndArr));
    RndArr *shared = mmap(NULL,sizeof(RndArr),PROT_WRITE | PROT_READ,MAP_SHARED|MAP_ANONYMOUS,fd,0);

	if (res == -1)
	{
		perror("ftruncate");
		return 20;
	}
    




    rn->printRA(rn);

    rn->printRA(rn);

    rn->printRA(rn);

    shared = rn;


    for(int i = 0; i<100; i++){

    }




            pid_t p = fork();
    shared = mmap(NULL, sizeof(int), PROT_READ|PROT_WRITE, MAP_SHARED|MAP_ANONYMOUS, -1, 0); 
            


            if(p < 0){
                perror("forkerror!");
                exit(1);
            }if(p==0){
                
                //ftruncate(fd,seofiz(RndArr));

                printf("debug\n");

                // RndArr *rn2 = mmap(NULL,sizeof(RndArr),PROT_WRITE | PROT_READ,MAP_SHARED,fd,0);
                rn->printRA(rn);
                rn->printRA(rn);
                shared = rn;
                //memcpy(rn, rn2, sizeof(RndArr));
                printf("shared%d\n",shared->count);
                exit(0);

                //rn = (RndArr *)mmap(0,sizeof(RndArr), PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);

                if(rn <0){
                    perror("mmaperror!");
                    exit(2);
                }

                //munmap(rn,sizeof(RndArr));
                close(fd);
                return 0;

            }
            if(p > 0){
                printf("parrentdebug");
                printf("%d\n",shared->count);

                wait(NULL);
                //rn->printRA(rn);

                
            }
            





        }

        if(a == 'n'){
            return 0;
            shm_unlink(NAME);
        }

    }



    return 0;
}
*/