#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <errno.h>

void unix_error(char *msg){
	fprintf(stderr,"%s: %s\n",msg,strerror(errno));
	exit(0);
}

//包装fork 函数
pid_t Fork(void){
	pid_t pid;

	if((pid = fork()) < 0){
		unix_error("fork error");
	}
	return pid;
}

int main(void) {
	printf("go to main   pid:%d\n",getpid());
	int x = 1;
	//创建子进程
	pid_t pid = fork();
	if (pid < 0) {
		//如果进程失败
		unix_error("fork error");
	} else if (pid == 0) {
		printf("child pid: %d, x: %d \n",getpid(), ++x);
	}else{
		printf("parent pid: %d, x: %d \n",getpid(),--x);
	}


	pid_t wPid = waitpid(-1,NULL,0);
	printf("wait pid :%d\n",wPid);
//	Fork();
//	Fork();
//	Fork();
	printf("hello world pid:%d ppid:%d\n",getpid(),getppid());

	return EXIT_SUCCESS;
}
