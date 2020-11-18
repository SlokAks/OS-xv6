// Specical structure for process info

struct uproc {
	char name[16];
	int pid;
	uint sz;
	int num_swtch;
	int priority;
};
