#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <sys/file.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <string.h>



int main()
{
    int fd, vissza;
    char buffer[100];

    buffer[0] = 0;

    fd = open("AJYKQ3.txt", O_RDWR);

    if (fd == -1) {
        perror("Fajl megnyitas [open()] hiba! \n");
        exit(-1);
    }

    vissza = read(fd, buffer, 100);
    printf("A read() %d byteot olvasott.\n\n", vissza);
    strcpy(buffer, "AJYKQ3");


    vissza = lseek(fd, 0, SEEK_SET);
    printf("Az lseek() beallt a %d. helyre, és ide ", vissza);

    vissza = write(fd, buffer, 6);
    printf("a write() %d byteot irt: %s\n\n", vissza, buffer);
    strcpy(buffer, "AJYKQ3");

    close(fd);

    return 0;
}
