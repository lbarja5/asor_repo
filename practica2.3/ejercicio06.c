#include <sys/types.h>
#include <unistd.h>
#include <stdio.h>
#include <limits.h>
#include <sys/resource.h>

void atributos()
{
    pid_t pid = getpid();
    printf("Id de proceso: %ld\n",pid);
    pid_t ppid = getppid();
    printf("Id de proceso padre: %ld\n",ppid);
    pid_t pgid = getpgid(0);
    printf("Id de grupo: %ld\n",pgid);
    pid_t sid = getsid(0);
    printf("Id de sesion: %ld\n",sid);
    struct rlimit rlim;
    if(getrlimit(RLIMIT_NOFILE, &rlim) == 0)
        printf("Max ficheros abiertos: %i\n",rlim.rlim_max);
    else
    {
        perror("getrlimit");
    }
    char dir_buf[PATH_MAX];
    if(getcwd(dir_buf, sizeof(dir_buf)) != NULL){
        printf("Dirección: %s\n",dir_buf);
    }else{
        perror("getcwd");
    }
}

//Crear un proceso y una sesion, mostrar atributos y dir = /tmp
int main(int argc, char **argv)
{
    pid_t pid = fork();
    switch (pid)
    {
        case -1:
            perror("fork()");
            return -1;
        case 0: //Hijo
            sleep(10);
            printf("---Hijo---\n");
            printf("Nueva sesion: %ld\n",setsid());
            if(chdir("/tmp") == -1){
                perror("chdir");
                return -1;
            }
            atributos();
            return 0; 
        default: //Padre
            sleep(1);
            printf("---Padre---\n");
            atributos();
            return 0;
    }
    return 0;
}
//Si finalizase la ejecucion del proceso hijo antes que la del padre
//este se quedaria en estado zombie, hasta que reciba una señal de fin