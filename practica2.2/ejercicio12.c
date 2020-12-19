#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

//Redirigir la salida estandar a un fichero argv[1]
int main(int argc, char **argv)
{
	if (argc < 3) {
        	fprintf(stderr, "Usage: %s <file> <text>\n", argv[0]);
        	return -1;
        }
	
	int fd;
	
	fd = open(argv[1], O_CREAT | O_TRUNC | O_RDWR, 0644);
	
	dup2(fd, 1);
	close(fd);
	int i = 2;
	while(i < argc){
		printf("%s\n",argv[i]);
		i++;
	}
	return 0;
}
