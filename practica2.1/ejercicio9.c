#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>

int main(int argc, char **argv)
{
	printf("Usuario real: %d\n", getuid());
	printf("Usuario efectivo: %d\n", geteuid());
	return 0;
}
//El fichero del programa tiene activado el bit "setuid"
//Cuando se crea un proceso y recibe el valor de "EUID" y "EGID"
//del fichero que lo contiene
