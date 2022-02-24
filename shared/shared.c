#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <fcntl.h>
#include <sys/shm.h>
#include <sys/stat.h>
#include <sys/mman.h>
#include <sys/types.h>
#include <unistd.h>


#define NAME "shmem"
#define NUM 3
#define SIZE (NUM * sizeof(int))


int main(){
  int fd = shm_open(NAME, O_CREAT | O_TRUNC | O_RDWR,0600);
  
  if(fd < 0){
    perror("shm_open error");
    exit(1);
  }
  int p = fork();

  if(p<0){
    perror("fork error");
  }


  if(p==0){
    ftruncate(fd,SIZE);
    int *datas = (int *)mmap(0,SIZE, PROT_READ | PROT_WRITE, MAP_SHARED, fd, 0);
    printf("sender adrress:%p\n",datas);

    for (int i = 0; i < NUM; ++i){
      datas[i] = i;
    }

    munmap(datas,SIZE);
    close(fd);
  }

  if(p>0){
    usleep(100);
    int *datar = (int*)mmap(0,SIZE,PROT_READ,MAP_SHARED,fd,0);
    printf("recive adress:%p\n",datar);

    for(int j = 0; j < NUM; ++j){
      printf("%d\n",datar[j]);
    }

    munmap(datar, SIZE);
    close(fd);
    shm_unlink(NAME);
    return 0;
  }



  return 0;

}