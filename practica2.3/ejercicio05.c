#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <sys/resource.h>

//Id proceso, id padre, id grupo, id sesion, max fich open y dir
int main()
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
    if(getrlimit(RLIMIT_NOFILE, &rlim) == 0)///////////////////
        printf("Max ficheros abiertos: %i\n",rlim.rlim_max);
    else
    {
        perror("getrlimit");
        return -1;
    }
    char dir_buf[PATH_MAX];
    if(getcwd(dir_buf, sizeof(dir_buf)) != NULL){
        printf("Dirección: %s\n",dir_buf);
    }else{
        perror("getcwd");
        return -1;
    }
    return 0;
}