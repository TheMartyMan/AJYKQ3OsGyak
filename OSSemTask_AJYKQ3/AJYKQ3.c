#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int gyerek;

    if((gyerek=fork())==0) // Gyerek processz forkolás
    {
      execl("./main2.out", "main2.out",(char *)NULL);
    return 0;
        }
        printf("Szülő processz vagyok! PIDem: %d\nGyerekem PIDje: %d\n", getpid(), gyerek);
        waitpid(gyerek, NULL, 0); // A szülő processz bevárja a gyereket

    return 0;
}
