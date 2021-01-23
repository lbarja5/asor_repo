#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char** argv){
    struct addrinfo filtro;
    struct addrinfo *res;

    memset(&filtro, 0, sizeof(struct addrinfo));
    filtro.ai_flags = AI_PASSIVE;
    filtro.ai_family = AF_UNSPEC;
    filtro.ai_socktype = SOCK_STREAM;

    int rc = getaddrinfo(argv[1], argv[2], &filtro, &res);

    if(rc != 0){
        printf("Error getaddinfo: %s\n",gai_strerror(rc));
        return -1;
    }

    for(struct addrinfo*i = res; i != NULL; i = i->ai_next){
        char host[NI_MAXHOST];
        char serv[NI_MAXSERV];

        getnameinfo(i->ai_addr, i->ai_addrlen, host, NI_MAXHOST, serv, NI_MAXSERV, NI_NUMERICHOST | NI_NUMERICSERV);

        printf("Host: %s. Puerto: %s.\n", host, serv);
    }

    freeaddrinfo(res);
    return 0;
}