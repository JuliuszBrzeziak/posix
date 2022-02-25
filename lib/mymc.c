#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "mymc.h"
#include <time.h>

#define N 1000000

int test2(void){
    return 0;
}

RndArr  *create(RndArr *self){
    srand(time(NULL));
    self->test = test2;
    self->calculate = collect2;
    self->array = malloc(sizeof(float)*N);
    for(int i = 0; i<N;i++){
        self->array[i] = (float)rand() / (float)RAND_MAX;
    }
    return self;
}


int collect2(RndArr *self,int times){
    float temp = 0;
    int s = 0;
    srand(time(NULL));


    for(int i = 0; i<times;i++){
        self->array[i] = (float)rand() / (float)RAND_MAX;
    }

    for(int i = 0; i <times; i++){
        temp = temp +self->array[i];
        if(temp > 1){
            self->sum = s + self->sum;
            self->count += 1;
            s = 1;
            temp = 0;

        } else{
            s++;
        }
    }
    float a = (float)self->sum/(float)self->count;
    self->avr = a;
    self->trials += times;
    return 0;
}


int pid(){
  printf("pid(): UID = %i , GID = %i, PID = %i, PPID = %i, PGID = %i \n", getuid(), getgid(), getpid(), getppid(), getpgrp());
  return getpid();
}

