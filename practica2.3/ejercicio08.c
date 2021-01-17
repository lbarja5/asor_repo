#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <sys/resource.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <fcntl.h>

int main(int argc, char **argv)
{
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <command>\n", argv[0]);
        return -1;
    }
    pid_t pid = fork();
    switch (pid)
    {
        case -1:
            perror("fork()");
            return -1;
        case 0: //Hijo
            sleep(3);
            printf("---Hijo---\n");
            printf("Nueva sesion: %ld\n",setsid());
            if(chdir("/tmp") == -1){
                perror("chdir");
                return -1;
            }
            int fd1,fd2,fd3;
            //Salida  estandar -> /tmp/daemon.out
            fd1 = open("/tmp/daemon.out", O_CREAT | O_TRUNC | O_RDWR, 0640);
            dup2(fd1, 1);
            close(fd1);
            //Salida de error -> /tmp/daemon.err
            fd2 = open("/tmp/daemon.err", O_CREAT | O_TRUNC | O_RDWR, 0640);
            dup2(fd2, 2);
            close(fd2);
            //Entrada estandar -> /dev/null
            fd3 = open("/dev/null", O_CREAT | O_TRUNC | O_RDWR, 0640);
            dup2(fd3, 0);
            close(fd3);
            execvp(argv[1], argv + 1);
            return 0; 
        default: //Padre
            
            sleep(10);
            printf("---Padre---\n");
            return 0;
    }
    return 0;
}