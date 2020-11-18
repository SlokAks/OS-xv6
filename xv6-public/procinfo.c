#include "types.h"
#include "stat.h"
#include "user.h"
#include "fs.h"
#include "processInfo.h"

int main(int argc, char *argv[])
{
	
	if(argc<2){printf(1,"Enter the PID !!! \n");	exit();}
	
	struct uproc *up;up=malloc(1000);
	
	int pid=atoi(argv[1]);
	
	
		if(getProcInfo(pid,up)==-1)printf(1,"Process with given PID not Found !!! \n");
		else {
			printf(1,"Name \t PID \t Memory \tNumber of Context Switch\n");
		
			printf(1,"%s \t %d \t %d \t\t %d\n",up->name,up->pid,up->sz,up->num_swtch);
			}

	exit();
	
}
