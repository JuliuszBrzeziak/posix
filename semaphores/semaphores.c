#include <stdio.h>
#include <pthread.h>
#include <semaphore.h>
#include <unistd.h>
#include <fcntl.h>

  
sem_t sem;
  

  
int main()
{
    //sem_init(sem, 1, 0);



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
    printf("\nEntered..\n");
  
    //critical section
    sleep(4);
      
    //signal
    printf("\nJust Exiting...\n");
    sem_post(sem);
    }   

    //parent
    else
    {
    sem_wait(sem);
    printf("\nEntered..\n");
  
    //critical section
    sleep(4);
      
    //signal
    printf("\nJust Exiting...\n");
    sem_post(sem);
    }


    sem_destroy(sem);
    return 0;
}