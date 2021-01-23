#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>

int main(int argc, char** argv){
    if (argc != 2) {
        fprintf(stderr, "Usage: %s <dir|ip|url>\n", argv[0]);
    	return -1;
    }

    struct addrinfo filtro;
    struct addrinfo *res, *rp;

    memset(&filtro, 0, sizeof(filtro));
    filtro.ai_flags = AI_PASSIVE;
    filtro.ai_family = AF_UNSPEC;
    filtro.ai_socktype = 0;
    filtro.ai_protocol = 0;

    int rc = getaddrinfo(argv[1], NULL, &filtro, &res);

    if(rc != 0){
        fprintf(stderr, "Error getaddinfo: %s\n",gai_strerror(rc));
        return -1;
    }

    for(rp = res; rp != NULL; rp = rp->ai_next){
        char host[NI_MAXHOST];
        char serv[NI_MAXSERV];

        getnameinfo(rp->ai_addr, rp->ai_addrlen, host, NI_MAXHOST, serv, NI_MAXSERV, NI_NUMERICHOST | NI_NUMERICSERV);

        printf("%s  %i  %i\n", host,rp->ai_family, rp->ai_socktype);
    }

    freeaddrinfo(res);

    return 0;
}