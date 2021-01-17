#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdio.h>

static volatile int cont = 0;
static volatile int cont_int = 0;
static volatile int cont_tstp = 0;

void contar_int(int s){
    cont++;
    cont_int++;
}

void contar_tstp(int s){
    cont++;
    cont_tstp++;
}

//Contar SIGINT y SIGTSTP
int main(){
    struct sigaction sa1;
    struct sigaction sa2;

    sa1.sa_handler = contar_int;
    sa2.sa_handler = contar_tstp;
    sa1.sa_flags = SA_RESTART;
    sa2.sa_flags = SA_RESTART;

    sigaction(SIGINT, &sa1, 0);
    sigaction(SIGTSTP, &sa2, 0);

    while(cont < 10){}
    
    printf("SIGINT: %i\n",cont_int);
    printf("SIGTSTP: %i\n",cont_tstp);
    return 0;
}
    