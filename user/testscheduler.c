#include "kernel/types.h"
#include "kernel/stat.h"
#include "kernel/spinlock.h"
#include "kernel/riscv.h"
#include "kernel/pstat.h"
#include "kernel/process.h"
#include "user/user.h"


int main(int argc, char *argv[])
{
  int pid1, pid2;
  // int i = 0;
  struct pstat *userProcessStat = (struct pstat*) malloc(sizeof(struct pstat) * NPROC); 

  // int parentpid = getpid();
  // parentpid--;
  // printf("pid1: name: %s pid %d priority %d\n", userProcessStat->name[parentpid], userProcessStat->pid[parentpid], userProcessStat->real_priority[parentpid]);


  pid1 = fork();
  pid2 = fork();
  setP(pid1, -20);
  setP(pid2, 20);

  if (pid1 > 0 && pid2 > 0)
  {
    int parentpid = getpid();
    printf("parent\n");
    printf("pid1 %d pid2 %d\n", pid1, pid2);
    printf("parent pid: %d\n", parentpid);
  }
  else if (pid1 == 0 && pid2 > 0)
  {
    int childpid1 = getpid();
    printf("childpid1\n");
    printf("pid1 %d pid2 %d\n", pid1, pid2);
    printf("childpid1: %d\n", childpid1);
  }
  else if (pid1 > 0 && pid2 == 0)
  {
    int childpid2 = getpid();
    printf("childpid2\n");
    printf("pid1 %d pid2 %d\n", pid1, pid2);
    printf("childpid2: %d\n", childpid2);
  }
  else
  {
    int childpid3 = getpid();
    printf("childpid3\n");
    printf("pid1 %d pid2 %d\n", pid1, pid2);
    printf("childpid3: %d\n", childpid3);
  }


  if ( getpinfo(userProcessStat) < 0)
  {
    printf("getpinfo failed\n");
    free(userProcessStat);
    exit(0);
  }

  // while(i < 64)
  // {
  //   if (pid1 == 0)
  //   {
  //     int childpid1 = getpid();
  //     childpid1--;
  //     printf("pid1: name: %s pid %d priority %d\n", userProcessStat->name[childpid1], userProcessStat->pid[childpid1], userProcessStat->real_priority[childpid1]);
  //   }
  //   if (pid2 == 0)
  //   {
  //     int childpid2 = getpid();
  //     childpid2--;
  //     printf("pid1: name: %s pid %d priority %d\n", userProcessStat->name[childpid2], userProcessStat->pid[childpid2], userProcessStat->real_priority[childpid2]);
  //   }
  //   i++;
  // }
  


  free(userProcessStat);
  exit(0);

}