#include "types.h"
#include "user.h"

int main(int argc, char **argv)
{
    if(argc < 3){
        printf(1, "Invalid number of arguments\n");
        exit();
    }
    int priority = atoi(argv[1]);
    int pid = atoi(argv[2]);
    if (set_priority(priority, pid) < 0)
    {
        printf(1, "Error\n");
    }
    exit();
}