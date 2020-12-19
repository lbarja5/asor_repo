#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	if(remove("5.txt") == 0){
		mode_t mascara = umask(0027)
		int fd = open("5.txt", O_RDWR|O_CREAT, mascara);
		if(fd == -1)
			printf("ERROR en open");
		else
			printf("Se ha creado el fichero");
		close(fd);
	}else{
		perror("El fichero ya existe y no sido posible borrarlo")
	}
	return 0;
}
