#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv){

     if (argc < 5) {
        fprintf(stderr, "Usage: %s <command 1> <command 2>\n", argv[0]);
        return -1;
    }

    //Crea tuberia
    int fd[2];
    pipe(fd);
    //fork
    pid_t pid = fork();

    switch(pid) {
        case -1:
            perror("fork");
            exit(1);
        case 0: //Hijo lee de la tuberia
            dup2(fd[0], 0);

            close(fd[1]);
            close(fd[0]);

            execlp(argv[3], argv[3], argv[4], NULL);
            break;
        default: //Padre escibe en la tuberia
            dup2(fd[1], 1);

            close(fd[0]);
            close(fd[1]);

            execlp(argv[1], argv[1], argv[2], NULL);
            break;
    }
    return 0;
}   