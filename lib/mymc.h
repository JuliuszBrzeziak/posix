#ifndef PID_H  
#define PID_H 


int pid();

typedef struct RndArr{
    int sum;
    int count;
    float avr;
    float *array;
    int trials;
    int (*test)(void);
    int (*calculate)(struct RndArr *self,int times);
    void (*collect)(struct RndArr *self)

}RndArr;

RndArr  *create(RndArr *self);

int collect2(RndArr *self,int times);

int test2(void);



#endif
