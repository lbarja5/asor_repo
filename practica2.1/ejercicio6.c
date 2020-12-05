#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char **argv)
{
	long argmax = sysconf(_SC_ARG_MAX);
        long maxchild = sysconf(_SC_CHILD_MAX);
        long maxopen = sysconf(_SC_OPEN_MAX);	
	if(argmax == -1 || maxchild == -1 || maxopen == -1)
		perror("Se ha producido un error en sysconf");
	else
	{
		printf("Longitud máxima de argumentos: %ld\n", argmax);
		printf("Número máximo de hijos: %ld\n", maxchild);
		printf("Número máximo de ficheros abiertos: %ld\n", maxopen);
	}	
	return 0;
}

