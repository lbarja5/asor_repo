#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

int main(int argc, char **argv){
    
    char mensaje[2];
    char entrada[100];
    int i;
    //Crea tuberias
    int p_h[2];
    int h_p[2];
    pipe(p_h);
    pipe(h_p);

    //fork
    pid_t pid = fork();

    switch(pid) {
        case -1:
            perror("fork");
            exit(1);
        case 0: //Hijo lee de la tuberia

            close(p_h[1]);
            close(h_p[0]);
            read(p_h[0],entrada,sizeof(entrada));
            printf("[H]Mensaje: %s\n",entrada);
            sleep(1);
            for(i=0;i<10;i++){
                if(write(h_p[1], "1", 2) == -1){
                    perror("write");
                    return -1;
                }
                read(p_h[0],mensaje,sizeof(mensaje));
                
            }
            close(p_h[0]);
            if(write(h_p[1], "q", 2) == -1){
                perror("write");
                return -1;
            }
            close(h_p[1]);
            break;
        default: //Padre escibe en la tuberia

            close(p_h[0]);
            close(h_p[1]);
            printf("[P]Introduzca mensaje: ");
            scanf("%s",entrada);
            write(p_h[1], entrada, sizeof(entrada));
            while(read(h_p[0],mensaje,2)>0 && strcmp(mensaje,"q")!=0){
                //printf("Padre ha recibido: %s\n", mensaje);
                //Bloquear hasta que el hijo responda
                write(p_h[1],"1",2);
            }
            
            close(p_h[1]);
            close(h_p[0]);
            break;
    }
    waitpid(pid,NULL,0);
    return 0;
}   