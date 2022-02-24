#ifndef PID_H  
#define PID_H 


int pid();

typedef struct RndArr{
    int sum;
    int count;
    float avr;
    float *array;
    int (*test)(void);
    void (*printRA)(struct RndArr *self);
    void (*collect)(struct RndArr *self)

}RndArr;

void printrndarr(RndArr *self);

RndArr  *create(void);

int collect2(RndArr *self);

int test2(void);
#endif
