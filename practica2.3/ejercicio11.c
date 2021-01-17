#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

//Bloquear SIGINT y SIGTSTP
int main(){
    if(setenv("SLEEP_SECS","20",0) != 0){
        perror("setenv");
        return -1;
    }
    sigset_t blk_set, pend;
    sigemptyset(&blk_set);
    sigaddset(&blk_set, SIGINT);
    sigaddset(&blk_set, SIGTSTP);
    sigprocmask(SIG_BLOCK, &blk_set, NULL);
    char* tiempo = getenv("SLEEP_SECS");
    int t = atoi(tiempo);
    sleep(t);

    if(sigpending(&pend) != 0){
        perror("sigpending");
        return -1;
    }
    if(sigismember(&pend,SIGINT)){
        printf("Se ha detectado la señal SIGINT\n");
    }
    if(sigismember(&pend,SIGTSTP)){
        printf("Se ha detectado la señal SIGTSTP. El programa se detendrá\n");
        sigprocmask(SIG_UNBLOCK, &pend, NULL);
}
    }
    