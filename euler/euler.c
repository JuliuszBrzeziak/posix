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
// #include "../lib/pid.h"
#include "../lib/mymc.h"



int main(){
    char a;

    RndArr *rn = create();
    rn->test();
    rn->printRA(rn);
    rn->printRA(rn);

    rn->printRA(rn);

    rn->printRA(rn);
    for(int i = 0; i<100; i++){

    }


    while (scanf("%c",&a) == 1){

        if(a == 'y'){
            rn->printRA(rn);


        }

        if(a == 'n'){
            break;
        } else 
            return 0;

    }


    return 0;
}
