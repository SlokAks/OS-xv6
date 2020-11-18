// Specical structure for process info

struct processInfo {
	char name[16];
	int pid;
	uint sz;
	int num_swtch;
	int priority;
};
