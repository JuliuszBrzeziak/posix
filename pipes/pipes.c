#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include "../lib/pid.h"


int main()
{
 
    int fd[2]; //file descryptor
 
    pid_t p;
 
    if (pipe(fd) == -1) {
        fprintf(stderr, "Pipe Failed");
        return 1;
    }

    p = fork();
 
    if (p < 0) {
        perror("fork error!");
        return 1;
    }
 
    // Parent process
    else if (p > 0) {
        int arr[100];
 
        close(fd[0]); 
 

        for(int a = 0; a <3; a++){
            sleep(1);
            for(int b = 0; b<100;b++){
                arr[b] = rand();
            }

            //printf("send%d\n",arr[2]);
            write(fd[1], arr, sizeof(int) * 100);

        }
        close(fd[1]);
 

    }
 
    // child process
    else {
        close(fd[1]); 
 

        int con_int[100];
        while(read(fd[0], con_int, sizeof(int) * 100)){
            printf("ret%d\n",con_int[2]);
            printf("ret%d\n",con_int[3]);

        } 
       close(fd[0]);

 

 
        exit(0);
    }
}