#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/socket.h>
#include <netdb.h>
#include <time.h>

int main(int argc, char** argv){
    if (argc != 3) {
        fprintf(stderr, "Usage: %s <dir|ip|url> <port>\n", argv[0]);
    	return -1;
    }

    char buffer[80];

    struct addrinfo filtro;
    struct addrinfo *res, *rp;

    memset(&filtro, 0, sizeof(filtro));
    filtro.ai_flags = AI_PASSIVE;
    filtro.ai_family = AF_UNSPEC;
    filtro.ai_socktype = SOCK_DGRAM;
    filtro.ai_protocol = 0;

    int rc = getaddrinfo(argv[1], argv[2], &filtro, &res);

    if(rc != 0){
        fprintf(stderr, "Error getaddinfo: %s\n",gai_strerror(rc));
        return -1;
    }

    int sd = socket(res->ai_family, res->ai_socktype, 0);

    bind(sd, res->ai_addr, res->ai_addrlen);

    freeaddrinfo(res);

    while(1){
        char host[NI_MAXHOST];
        char serv[NI_MAXSERV];

        struct sockaddr_storage client_addr;
        socklen_t client_len = sizeof(client_addr);

        int bytes = recvfrom(sd, buffer, 79, 0, (struct sockaddr *) &client_addr, &client_len);
        printf("B: %s\n", &buffer);
        char msg = buffer[0];
        buffer[bytes]='\0';

        getnameinfo((struct sockaddr *) &client_addr, client_len, host, NI_MAXHOST, serv, NI_MAXSERV, NI_NUMERICHOST | NI_NUMERICSERV);
        
        size_t tam;
        switch(msg){
            case 't':
                printf("%i bytes de %s:%s\n", bytes, host, serv);
                tam = strftime(buffer, sizeof(buffer), "%r", localtime(0));
                sendto(sd, buffer, tam,0,(struct sockaddr *) &client_addr, client_len);
                break;
            case 'd':
                printf("%i bytes de %s:%s\n", bytes, host, serv);
                tam = strftime(buffer, sizeof(buffer), "%D", localtime(0));
                sendto(sd, buffer, tam,0,(struct sockaddr *) &client_addr, client_len);
                break;
            default:
                printf("Comando no soportado %s", buffer);
                break;
        }
    }

    //Cerrar socket
    close(sd);

    return 0;
}