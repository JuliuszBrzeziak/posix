#include <stdio.h>
#include <signal.h>
#include <stdlib.h>
#include <unistd.h>
#include "../lib/pid.h"


int main(int argc, char *argv[])
{



    int PID = pid();

    int sig=strtol(argv[2],NULL,10);
    int pid;


    switch (pid=fork())
    {
      //fork error
        case -1:
            perror("fork error");
            exit(1);

      //child case
        case 0:
            execl("./signals.o", "./signals.o", argv[1], NULL);

      //parent case
        default:
            usleep(800);
            if(kill(pid, 0)==0)
        {

            kill(pid, SIGINT);
        } else { //kill error
            perror("kill error");

          exit(2);
        }
    };
    
    return 0;

}
