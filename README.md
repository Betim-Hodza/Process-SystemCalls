# System Calls

Implemented program PS and the subsequent system calls required to run the user program. As well as system calls to set priority and effective priority.

## Process Control Block

modified the process control block to include the effective priority and real priority of a process. All processes default to a priority of 0. 

## System Calls

### int setPrority( int pid, int priority )
Implemented a system call that will set the priority of a process.  Valid priority levels are -20 to 20. Stored the priority of a process in its process control block as the process's real priority.  This routine should return 0 if successful, and -1 otherwise (if, for example, the caller passes in an invalid prority).

### int setEffectivePriority( int pid, int priority )
This system call sets the effective priority of the process with the given pid. This routine should return 0 if successful, and -1 otherwise (if, for example, the caller passes in an invalid pid or a priority < -20 or > 20.

### int getpinfo(struct pstat *)
The next is int getpinfo(struct pstat *). This routine returns some information about all running processes, including how many times each has been chosen to run and the process ID of each. This will use this system call to build a variant of the command line program ps, which can then be called to see what is going on. The structure pstat is defined below; note, you cannot change this structure, and must use it exactly as is. This routine should return 0 if successful, and -1 otherwise (if, for example, a bad or NULL pointer is passed into the kernel). getpinfo will read from the process table and populate the pstat function and then copy out the pstat function.

The structure should look like what you see here, in a file included called pstat.h:

```c
#ifndef _PSTAT_H_
#define _PSTAT_H_

#include "param.h"

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

```

## ps

Your ps application will print the following:

```
NAME    PID     STATUS      PRIORITY    
init    1       SLEEPING    1     
sh      2       SLEEPING    1  
test    4       SLEEPING    -10      
ps      6       RUNNING     20  
```

## BUILDING AND RUNNING XV6

### To build the kernel:
```
make
```

### To build the userspace applications and run the OS
```
make qemu
```

### To exit xv6
```
ctrl-a x
```
