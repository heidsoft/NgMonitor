#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int main(void) {
	printf("Hello NgDeamon\n");

	pid_t pid = fork();
	if (pid == -1) {
		printf("fork error %d\n",errno);
	} else if (pid == 0) {
		printf("my1 pid %d\n",getpid());
	}else{
		sleep(1);
		printf("my2 pid %d\n",getpid());
	}

	return EXIT_SUCCESS;
}
