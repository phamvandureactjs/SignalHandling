#include <stdio.h>
#include <unistd.h>
#define _GNU_SOURCE
#include <fcntl.h>
#include <sys/types.h>
#include <stdlib.h>
#include <string.h>
int main(){
	int fd[2], nbytes;
	pid_t childpid;
	char readbuffer[80];
	char string[80];
	printf("Please type the string:");
	fgets(string, 80, stdin);
	pipe(fd);
	childpid = fork();
	if(childpid == -1){
		perror("fork");
		exit(1);
	}
	printf("Before if \n");
	if(childpid == 0){ // this code run only in the child process
		printf("In child process\n");
		close(fd[0]);
		printf("After close(fd[0]); In child process\n");
		write(fd[1], string, (strlen(string)+1));
		printf("After write in child process");
		exit(0);
	}else{ // this code run only in the parent process
		printf("In parent process\n");
		close(fd[1]);
		printf("After close in parent process\n");
		nbytes = read(fd[0],readbuffer,sizeof(readbuffer));
		printf("After read in parent process\n");
		printf("Received string:%s", readbuffer);
	}

	printf("hello\n");

	return 0;
}
