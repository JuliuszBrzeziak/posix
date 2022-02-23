#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <sys/wait.h>
#include "../lib/pid.h"

void sig_handler(int signali)
{
    printf("Signal catch %d\n", signali);
    
}

int main(int argc, char *argv[])

{


    int PID = pid();

    printf("%i\n",PID);


    if(argc>3)
    {
        printf("too much args");
        return 1;
    }




        //default
        if(*argv[1]=='1')
        {
            if((signal(SIGINT, SIG_DFL))==SIG_ERR)
            {
            perror("Default signal error ");
            exit(1);
            }

        }


        //ignore
        if(*argv[1]=='2')
        {
            if((signal(SIGINT, SIG_IGN))==SIG_ERR)
            {
                perror("Ignore signal error");
                exit(2);
            }

        }


        //sig_handler signal
        if(*argv[1]=='3')
        {
            if((signal(SIGINT, sig_handler)==SIG_ERR))
            {
                perror("Blad przechwycenia sygnalu");
                exit(3);
            }
        }


        for (;;){
        pause();
        }


        return 0;

}
