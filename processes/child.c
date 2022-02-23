#include <stdio.h>


int main(int argc, char *argv[])
{
    printf("\n jestem:%s a moje argumenty to:", argv[0]);
    for(int i = 1; i < argc; i++){
        printf("%s,",argv[i]);
    }
    printf("\n");
}