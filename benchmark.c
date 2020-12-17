#include "types.h"
#include "user.h"

int number_of_processes = 10;

int main(int argc, char *argv[])
{
  int j;
  for (j = 0; j < number_of_processes; j++)
  {
    int pid = fork();
    if (pid < 0)
    {
      printf(1, "Fork failed\n");
      continue;
    }
    if (pid == 0)
    {
      volatile int i;
      // for (volatile int k = 0; k < number_of_processes; k++)
      for (volatile int k = 0; k < 10; k++)
      {
        // if (k <= j)
        // // if (j % 2 == 0)
        // {
          sleep(20); //io time
        // }
        // else
        // {
          for (i = 0; i < (int)1e7; i++)
          {
            ; //cpu time
          }
        // }
      }
      printf(1, "\nProcess: %d with PID: %d Finished\n\n\n", j, getpid());
      // myps(); // To Print comparison report
      exit();
    }
    else
    {
      ;
      // set_priority(100 - (20 + j), pid); // will only matter for PBS, comment it out if not implemented yet (better priorty for more IO intensive jobs)
      #if SCHEDULER == SCHED_PBS
      set_priority(80 + j % 2, pid); // will only matter for PBS, comment it out if not implemented yet (better priorty for more IO intensive jobs)
      #endif
    }
  }
  for (j = 0; j < number_of_processes + 5; j++)
  {
    wait();
    // int wtime, rtime;
    // int pid1 = waitx(&wtime, &rtime);
    // printf(1, "Time-> Name: %s    wtime: %d    rtime: %d\n\n", argv[1], wtime, rtime);
  }
  exit();
}
