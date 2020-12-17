#include "types.h"
#include "user.h"

int main(int argc, char **argv)
{
    if (myps() < 0)
    {
        printf(1, "Error\n");
        exit();
    }
    exit();
}