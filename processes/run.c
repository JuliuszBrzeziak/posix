#include "pid.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

int main(void)
{
    
    pid_t children[3];


    for(int i = 0; i < 3; i++){
        switch(children[i] = fork()){

            //error case   
            case -1:
            perror("fork error");
            exit(1);

            //child case
            case 0:
            //break;
            //break doesnt work!
            i = 3;

            //parent case
            default:
            usleep(100);


        }
    }


    pid();
    return 0;
}