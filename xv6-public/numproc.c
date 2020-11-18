#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"

int main(int argc, char *argv[]) {

        int *num_proc;        
        num_proc = malloc(30);

        getNumProc(num_proc);
        printf(1, "Total number of Processes running : %d\n", (*num_proc));
        exit();
}
