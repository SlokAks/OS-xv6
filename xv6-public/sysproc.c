#include "types.h"
#include "x86.h"
#include "defs.h"
#include "date.h"
#include "param.h"
#include "memlayout.h"
#include "mmu.h"
#include "proc.h"
#include "processInfo.h"

int
sys_fork(void)
{
  return fork();
}

int
sys_exit(void)
{
  exit();
  return 0;  // not reached
}

int
sys_wait(void)
{
  return wait();
}

int
sys_kill(void)
{
  int pid;

  if(argint(0, &pid) < 0)
    return -1;
  return kill(pid);
}

int
sys_getpid(void)
{
  return myproc()->pid;
}

int
sys_sbrk(void)
{
  int addr;
  int n;

  if(argint(0, &n) < 0)
    return -1;
  addr = myproc()->sz;
  if(growproc(n) < 0)
    return -1;
  return addr;
}

int
sys_sleep(void)
{
  int n;
  uint ticks0;

  if(argint(0, &n) < 0)
    return -1;
  acquire(&tickslock);
  ticks0 = ticks;
  while(ticks - ticks0 < n){
    if(myproc()->killed){
      release(&tickslock);
      return -1;
    }
    sleep(&ticks, &tickslock);
  }
  release(&tickslock);
  return 0;
}

int sys_getprocinfo(void) {
	return getprocinfo();
}

//Get number of active processes
int
sys_getNumProc(void) {
	int *num_proc;
	argptr(0,(void *)&num_proc, sizeof(*num_proc));
	
	return getNumProc(num_proc);
}

//Get max PID among all active processes
int sys_getMaxPid(void) {
	int *max_pid;
	argptr(0,(void *)&max_pid, sizeof(*max_pid));
	
	return getMaxPid(max_pid);
}

//Get process info as per structure processInfo
int
sys_getProcInfo(void) {
	int pid;
	struct processInfo *up;
	
	argptr(0,(void *)&pid,sizeof(pid));
	argptr(1,(void *)&up,sizeof(*up));
	
	return getProcInfo(pid,up);
}

//Get priority function
int
sys_getPriority(void)
{
	int pid;int *priority;
	
	argptr(0,(void *)&pid,sizeof(pid));
	argptr(1,(void *)&priority,sizeof(*priority));
	
	return getPriority(pid,priority);
}

//Set priority function
int
sys_setPriority(void)
{
	int pid;int priority;
	
	argptr(0,(void *)&pid,sizeof(pid));
	argptr(1,(void *)&priority,sizeof(priority));
	
	return setPriority(pid,priority);
}

// return how many clock tick interrupts have occurred
// since start.
int
sys_uptime(void)
{
  uint xticks;

  acquire(&tickslock);
  xticks = ticks;
  release(&tickslock);
  return xticks;
}

