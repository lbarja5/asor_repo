#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <sys/sysmacros.h>

int main (int argc, char **argv){
	struct stat statbuf;

	if (argc != 2) {
        	fprintf(stderr, "Usage: %s <pathname>\n", argv[0]);
        	return -1;
        }

	int estado = stat(argv[1], &statbuf);
	if( estado == -1){
		perror("stat()");
		return -1;		
	}
	//número major y minor asociado al dispositivo
	printf("Major y minor del dispositivo: [%lx,%lx]\n",
                  (long) major(statbuf.st_dev), (long) minor(statbuf.st_dev));
	//número de i-nodo del fichero
	printf("I-nodo: %ld\n", (long) statbuf.st_ino);
	//tipo de fichero
	printf("Tipo de fichero: ");
	switch (statbuf.st_mode & S_IFMT) {
           case S_IFBLK:  printf("block device\n");            break;
           case S_IFCHR:  printf("character device\n");        break;
           case S_IFDIR:  printf("directory\n");               break;
           case S_IFIFO:  printf("FIFO/pipe\n");               break;
           case S_IFLNK:  printf("symlink\n");                 break;
           case S_IFREG:  printf("regular file\n");            break;
           case S_IFSOCK: printf("socket\n");                  break;
           default:       printf("unknown?\n");                break;
        }
	//hora en la que se accedió el fichero por última vez
	printf("Ultimo acceso: %s\n", ctime(&statbuf.st_atime));
	return 0;
}
