#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include "mymc.h"
#include <time.h>

#define N 1000000000

int test2(void){
    printf("UDAŁOSIsE\n");
    return 0;
}

RndArr  *create(void){
    srand(time(NULL));
    RndArr *p = malloc(sizeof(RndArr));
    p->test = test2;
    p->printRA = printrndarr;
    p->array = malloc(sizeof(float)*N);
    for(int i = 0; i<N;i++){
        p->array[i] = (float)rand() / (float)RAND_MAX;
        //printf("\n%f\n",p->array[i]);
    }
    return p;
}

void printrndarr(RndArr *self){
    //printf("%f",self->array[2]);
    collect2(self);
}

int collect2(RndArr *self){
    float temp = 0;
    int s = 0;
    int c = 0;

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
    self->avr = (float)self->sum/(float)self->count;
    printf("%f,  %d,   %d",self->avr,self->sum,self->count);
}


int pid(){
  printf("pid(): UID = %i , GID = %i, PID = %i, PPID = %i, PGID = %i \n", getuid(), getgid(), getpid(), getppid(), getpgrp());
  return getpid();
}

