#include "types.h"
#include "fcntl.h"
#include "stat.h"
#include "user.h"

int main(int argc, char **argv)
{
    int pid;
    pid = fork();
    if (pid < 0)
    {
        printf(2, "Fork error\n");
        exit();
    }
    else if (!pid)
    {
        printf(1, "Child: %s\n", argv[1]);
        // int j = 0;
        // for (int i = 0; i < 100000000; i++)
        // {
        //     j++;
        //     j--;
        //     j++;
        // }
        if (exec(argv[1], argv + 1) < 0)
        {
            printf(2, "Exec failed\n");
            exit();
        }
    }
    else
    {
        int wtime, rtime;
        int pid1 = waitx(&wtime, &rtime);
        printf(1, "Time-> Name: %s    PID: %d    wtime: %d    rtime: %d\n\n", argv[1], pid1, wtime, rtime);
        exit();
    }
}