#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

//fichero regular -> enlace simbolico y rigido
int main(int argc, char **argv)
{
	if (argc != 2) {
        	fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
        	return -1;
        }
	char origin;
	stpcpy(&origin, argv[1]);	
	open(&origin, O_CREAT, 0666);
	
	char rigido;
	stpcpy(&rigido, argv[1]);
	strcat(&rigido,".hard");
	if(link(argv[1], &rigido) == -1){
		perror("link()");
		return -1;
	}else{
		printf("Se ha creado un enlace rigido de %s -> %s\n",argv[1],&rigido);
	}
	char simbol;
	stpcpy(&simbol,argv[1]);
	strcat(&simbol, ".sym");
	if(symlink(argv[1], &simbol) == -1){
		perror("symlink()");
		return -1;
	}else{
		printf("Se ha creado un enlace sibolico de %s -> %s\n",argv[1],&simbol);

	}
	return 0;
}
