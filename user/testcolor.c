#include "kernel/types.h"
#include "kernel/stat.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
  // testcolor
  enum COLOR color = INDIGO;
  int pid = 0;

  color = getcolor( 0 );
  printf("PID %d, Color: %d\n", pid, color);

  setcolor(0, BLUE);
  
  color = getcolor( 0 );
  printf("PID %d, Color: %d\n", pid, color);


  exit(0);
}
