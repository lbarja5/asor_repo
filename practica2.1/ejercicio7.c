#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char **argv)
{
	long maxlink = pathconf("/root/asor_repo/practica2.1", _PC_LINK_MAX);
        long maxpath = pathconf("/root/asor_repo/practica2.1", );
        long maxname = pathconf("/root/asor_repo/practica2.1", );
	if(maxlink == -1 || maxpath == -1 || maxname == -1)
		perror("Se ha producido un error en pathconf\n");
	else
	{
		printf("Número máximo de enlaces: %ld\n", maxlink);
		printf("Tamaño máximo de una ruta: %ld\n", maxpath);
                printf("Tamaño máximo de nombre de fichero: %ld\n", maxname);
	}
	return 0;
}
