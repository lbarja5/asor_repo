#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv){

    int fd = open("tub", O_WRONLY);
    if(write(fd,argv[1], sizeof(argv[1]))<0)
    {
        perror("write");
        return -1;
    }
    return 0;
}   

//$ ./pr w
//$ cat tub
//w