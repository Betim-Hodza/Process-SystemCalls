#ifndef _PSTAT_H_
#define _PSTAT_H_

#include "param.h"
#include "process.h"

struct pstat {
  char name[NPROC][16];          // name of the process
  enum procstate state[NPROC];   // state of the process   
  int inuse[NPROC];              // whether this slot of the process table is in use (1 or 0)
  int effective_priority[NPROC]; // the effective priority of the process
  int real_priority[NPROC];      // the real priority of the process
  int pid[NPROC];                // the PID of each process
  int ticks[NPROC];              // the number of ticks each process has accumulated 
  };

#endif // _PSTAT_H_ 