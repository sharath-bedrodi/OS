#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void main()
 {
 	pid_t pid=fork();
 	 if(pid==-1)
 	  {
 	  	printf("Fork Error");
 	  	exit(1);
	   }
	if(pid==0)
	 {
	 	execlp("/bin/date","date",NULL);
	 	exit(1);
	 }
	 else
	 {
	 	int status;
	 	printf("Parent Process\n");
	 	wait();
	 	printf("Child Process Terminates\n");
	 }
 }