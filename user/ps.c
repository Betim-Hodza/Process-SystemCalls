#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/spinlock.h"
#include "kernel/riscv.h"
#include "kernel/pstat.h"
#include "kernel/process.h"
#include "user/user.h"


int main(int argc, char *argv[])
{
  char state[10];

  // iterator
  int i = 0; 

  // this will be our max number of processes
  struct pstat *userProcessStat = (struct pstat*) malloc(sizeof(struct pstat) * NPROC); 
  // if the malloc failed exit 
  if (userProcessStat == 0)
  {
    free(userProcessStat);
    exit(0);
  }

  if ( getpinfo(userProcessStat) < 0)
  {
    printf("getpinfo failed\n");
    free(userProcessStat);
    exit(0);
  }

  printf("NAME\tPID\tSTATUS  \tPRIORITY\n");
  // i presume we need to loop over the userProcStat values
  for(i = 0; i < NPROC; i++) 
  {
    // if the process is in use, we wanna see that
    if ( userProcessStat->inuse[i] )
    {
      // switch statement to print the state based on its enum value
      switch (userProcessStat->state[i])
      {
      case 0:
        // UNUSED
        strcpy(state, "UNUSED");
        break;
      case 1:
        // USED
        strcpy(state, "USED    ");
        break;
      case 2:
        // SLEEPING
        strcpy(state, "SLEEPING");
        break;
      case 3:
        // RUNNABLE
        strcpy(state, "RUNNABLE");
        break;
      case 4:
        // RUNNING
        strcpy(state, "RUNNING ");
        break;
      case 5:
        // ZOMBIE
        strcpy(state, "ZOMBIE  ");
        break;
      default:
        strcpy(state, "NULL    ");
        break;
      }

      printf("%s\t%d\t%s\t%d\n", userProcessStat->name[i], userProcessStat->pid[i], state, userProcessStat->real_priority[i]);

    }
  }


  free(userProcessStat);


  exit(0);
}
