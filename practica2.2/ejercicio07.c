#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	unlink("6");
	umask(0027);
	int fd = open("6", O_CREAT,0777);
	if(fd == -1)
		printf("ERROR en open\n");
	else
		printf("Se ha creado el fichero\n");
	close(fd);

	return 0;
}
