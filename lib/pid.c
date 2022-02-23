#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>

#include "pid.h"

/*prints ID's:
UID - user id
GID - user group id
PID - process id
PPID - parent process id
PGID - parent group id
*/
int pid(){
  printf("UID = %i , GID = %i, PID = %i, PPID = %i, PGID = %i \n", getuid(), getgid(), getpid(), getppid(), getpgrp());
  return getpid();
}