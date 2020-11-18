#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "processInfo.h"

int main(int argc, char *argv[])
{
	
	if(argc<2) {
		printf(1, "Please enter the PID !!! \n");
		exit();
	}

	int *priority;
	priority = malloc(30);
	
	int pid = atoi(argv[1]);
	
	
		if(getPriority(pid,priority)==-1)
			printf(1,"Process with given PID not Found !!! \n");
		else {
			printf(1,"\nPID\tPriority\n");
			printf(1,"%d\t%d\n",pid,*priority);	
		}

	exit();
}
