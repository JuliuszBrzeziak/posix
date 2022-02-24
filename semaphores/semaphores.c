#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <fcntl.h>

  
sem_t sem;
  

  
int main()
{



    sem_t *sem = sem_open("name", O_CREAT, 0644,1);

    int p = fork();

    if(p<0)
    {
        perror("fork error");
    }

    //child
    if(p==0)
    {
        usleep(500);
        sem_wait(sem);
        printf("\nEntered\n");
  
        usleep(800);


        printf("\nEXIT\n");
        sem_post(sem);
    }   

    //parent
    else
    {
        sem_wait(sem);
        printf("\nENTER\n");
  
        //critical section
        usleep(800);
      
        printf("\nEXIT\n");
        sem_post(sem);
    }


    sem_destroy(sem);
    return 0;
}