#include <stdio.h>
#include <dirent.h>

int main (int argc, char *argv[]) {
        struct dirent *entrada;
        DIR *dir;
        
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
		printf ("[%s]\n", entrada->d_type);
	}
        
        closedir (dir);
	return 0;
}
