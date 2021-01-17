#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv)
{
    const int MAX = 256;
    char buffer[MAX];
    int tub = open("tub",O_RDONLY):
    int pipe = open("pipe", O_RDONLY);

    read(tub,buffer,MAX);
    read(pipe,buffer,MAX);
  
    return 0;
}