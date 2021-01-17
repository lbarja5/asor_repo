#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char **argv)
{
    //---System-----
    /*char* buf = (char*)malloc(1000);
    int i;
    for(i=1;i<argc;i++)
    {
        strcat(buf,argv[i]);
        strcat(buf," ");
    }
    system(buf);
    free(buf);*/
    //--------------
    execvp(argv[1], argv + 1);
    printf("El comando terminó de ejecutarse\n");
    
    return 0;
}