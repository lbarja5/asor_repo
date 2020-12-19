#include <stdlib.h>
#include <stdio.h>

//Redirigir la salida estandar a un fichero argv[1]
int main(int argc, char **argv)
{
	if (argc != 2) {
        	fprintf(stderr, "Usage: %s <file>\n", argv[0]);
        	return -1;
        }
	
	int fd;
	
	fd = open(argv[1], O_CREAT | O_TRUNC | O_RDWR, 0644);
	
	dup2(fd, 1);
	close(fd);
	printf("%s\n",argv[1]);
	return 0;
}
