#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

//Bloquear SIGINT y SIGTSTP
int main(){
    if(setenv("SLEEP_SECS","10",0) != 0){
        perror("setenv");
        return -1;
    }
    sigset_t blk_set;
    sigemptyset(&blk_set);
    sigaddset(&blk_set, SIGINT);
    sigaddset(&blk_set, SIGTSTP);
    sigprocmask(SIG_BLOCK, &blk_set, NULL);
    sleep((int)*getenv("SLEEP_SECS"));
    if(sigpending(&blk_set) != 0){
        perror("sigpending");
        return -1;
    }
    sigprocmask(SIG_UNBLOCK, &blk_set, NULL);
}