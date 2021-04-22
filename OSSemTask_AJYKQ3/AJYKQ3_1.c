#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>
#include <errno.h>


int main() {

    char *hely = "/bin/ls";
    char *arg1 = "-la";
    char *arg2 = "/home";

    
	int childPID = fork();

//Gyerek
	if (childPID == 0) {
        
        printf("Gyerek PID: %u, Szülő PID: %u\n\n", getpid(), getppid());
        printf("execl() parancs futtatása 'ls -la' -val:\n");
		execl(hely, hely, arg1, arg2, NULL);
        
	}


//Szülő
wait(2);
    printf("\nSzülő PID: %u, Gyerek PID: %d\n\n", getpid(), childPID);


	return 0;
}
