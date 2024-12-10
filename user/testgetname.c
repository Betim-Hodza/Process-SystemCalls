#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
  // testgetname 1
  if (argc < 2)
  {
    printf("ERROR: must provide pid\n");
    printf("USAGE: testgetname [pid]\n");
  }

  char name[16];

  int pid = atoi(argv[1]);

  getname(pid, name);
  printf("PID: %d name: %s\n", pid, name);

  exit(0);
}