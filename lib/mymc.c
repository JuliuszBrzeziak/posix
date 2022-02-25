#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "mymc.h"
#include <time.h>

#define N 1000

int test2(void){
    printf("UDAŁOSIsE\n");
    return 0;
}

RndArr  *create(RndArr *self){
    srand(time(NULL));
    //RndArr *self = malloc(sizeof(RndArr));
    self->test = test2;
    self->printRA = printrndarr;
    self->array = malloc(sizeof(float)*N);
    for(int i = 0; i<N;i++){
        self->array[i] = (float)rand() / (float)RAND_MAX;
        //printf("\n%f\n",p->array[i]);
    }
    return self;
}

void printrndarr(RndArr *self){
    //printf("%f",self->array[2]);
    collect2(self);
}

int collect2(RndArr *self){
    float temp = 0;
    int s = 0;
    int c = 0;
    srand(time(NULL));


    for(int i = 0; i<N;i++){
        self->array[i] = (float)rand() / (float)RAND_MAX;
    }

    for(int i = 0; i <N; i++){
        temp = temp +self->array[i];
        if(temp > 1){
            self->sum = s + self->sum;
            self->count += 1;
            //printf("c==%d     s==%d\n",self->count,self->sum );
            s = 1;
            temp = 0;

        } else{
            s++;
        }
    }
    float a = (float)self->sum/(float)self->count;
    self->avr = a;
    printf("%f,  %d,   %d\n",a,self->sum,self->count);
}


int pid(){
  printf("pid(): UID = %i , GID = %i, PID = %i, PPID = %i, PGID = %i \n", getuid(), getgid(), getpid(), getppid(), getpgrp());
  return getpid();
}

