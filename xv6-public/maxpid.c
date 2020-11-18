#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"

int main(int argc, char *argv[])
{

        int *max_pid;
        max_pid=malloc(30);

        getMaxPid(max_pid);
        printf(1, "Maximum PID of all processes : %d\n", (*max_pid));

        exit();

}

