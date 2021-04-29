#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <sys/wait.h>
#include <limits.h>
#include <string.h>




int main()
{
    putenv("FAJL=/main2.out");
    int gyerek;

    if((gyerek=fork())==0) // Gyerek processz forkolás
    {



char cwd[PATH_MAX];
   if (getcwd(cwd, sizeof(cwd)) != NULL) {
   } else {
       perror("getcwd() hiba!\n");
       return 1;
}


char *HELY = strcat(cwd, getenv("FAJL"));


      execl(HELY, HELY, (char *)NULL);
    return 0;
        }
        printf("Szülő processz vagyok! PIDem: %d\nGyerekem PIDje: %d\n", getpid(), gyerek);
        waitpid(gyerek, NULL, 0); // A szülő processz bevárja a gyereket

    return 0;
}
