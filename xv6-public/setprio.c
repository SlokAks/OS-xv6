#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "processInfo.h"

int main(int argc, char *argv[])
{
	
	if(argc<3) {
		printf(1,"Please enter PID and priority !!! \n");	
		exit();
	}
	
	int pid=atoi(argv[1]);
	int priority=atoi(argv[2]);
	
		if(setPriority(pid,priority) == -1)
			printf(1,"Process with given PID not Found !!! \n");
		else {
			printf(1,"\nPriority Set !! \n");	
		}

	exit();
	
}
