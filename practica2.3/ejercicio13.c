#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>


int main(int argc, char **argv){
    if (argc < 2) {
        fprintf(stderr, "Usage: %s <segundos>\n", argv[0]);
    	return -1;
    }
    struct sigaction sa;

    sa.sa_handler = SIG_IGN;
    sa.sa_flags = SA_RESTART;

    sigaction(SIGUSR1, &sa, 0);

    sigset_t set;
    sigemptyset(&set);
    sigaddset(&set,SIGUSR1);
    sigsuspend(&set);
    
    if(remove(argv[0]) == 0){
        printf("El ejetable a sido borrado");
    }else{
        perror("remove");
        return -1;
    }

    return 0;
}
    