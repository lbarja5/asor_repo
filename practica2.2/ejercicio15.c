#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <sys/types.h>
#include <fcntl.h>
#include <time.h>

int main(int argc, char **argv)
{
	if (argc != 2) {
        	fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        	return -1;
        }
	//Mostrar el estado de un cerrojo sobre un fichero
	int fd = open(argv[1], O_CREAT | O_TRUNC | O_RDWR, 0644);
	errno = lockf(fd, F_TLOCK, 0);
	if(errno != EAGAIN)
	{
		//Desbloqueado -> Fijar el cerrojo y escribir la hora actual.
		//Sleep 30seg y liberarlo
		printf("Desbloqueado\n");
		char hora[20];
		time_t t;
		time(&t);
		strftime(hora,sizeof(hora),"%T",localtime(&t));
		printf("Hora block: %s\n",hora);
		sleep(30);
		lockf(fd, F_ULOCK, 0);
		time(&t);
                strftime(hora,sizeof(hora),"%T",localtime(&t));
                printf("Hora unblock: %s\n",hora);

	}else{
		//Bloqueado -> Terminar el programa
		printf("Bloqueado\n");
	}
	close(fd);
	return 0;
}
