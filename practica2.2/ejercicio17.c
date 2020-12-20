#include <stdlib.h>
#include <stdio.h>
#include <dirent.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>
#include <sys/sysmacros.h>

int main (int argc, char *argv[]) {
        struct dirent *entrada;
        DIR *dir;
        struct stat sbuf;
        char *buf;
        ssize_t nbytes, bufsiz;
        
        if (argc != 2) {
        	printf ("Usage: %s <dirname>\n", argv[0]);
        	return -1;
        }
      	
	dir = opendir (argv[1]);
        if (dir == NULL) {
            perror("opendir()");
            return -1;
        }

        while ((entrada = readdir(dir)) != NULL) {
		//printf ("[%s]\n", entrada->d_name);
                int estado = stat(entrada->d_name, &sbuf);
                if(estado == -1){
                        perror("stat()");
                        return -1;
                }
                switch(sbuf.st_mode & S_IFMT){
                        case S_IFREG:   printf("%s\n", entrada->d_name);        break;
                        case S_IFDIR:   printf("%s/\n", entrada->d_name);       break;
                        case S_IFLNK:{
                        printf("simbolico");
                        bufsiz = sbuf.st_size + 1;
                        buf = malloc(bufsiz);
                        if (buf == NULL) {
                                perror("malloc()");
                                return -1;
                        }
                        nbytes = readlink(entrada->d_name, buf, bufsiz);
                        if (nbytes == -1) {
                                perror("readlink()");
                                return -1;
                        }
                        printf("%s -> '%.*s'\n", entrada->d_name, (int) nbytes, buf);
                        free(buf);
                        }break;
                        case S_IEXEC: printf("%s*\n", entrada->d_name);         break;
                }
	}
        
        closedir (dir);
	return 0;
}