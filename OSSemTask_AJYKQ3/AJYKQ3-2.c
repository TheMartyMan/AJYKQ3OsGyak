#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
        printf("Gyerek processz vagyok! PIDem: %d\nSzülőm PIDje: %d\n", getpid(), getppid());
        wait(NULL);	
	return 0;
}
