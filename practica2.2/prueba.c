#include <stdio.h>
#include <dirent.h>

int main (int argc, char *argv[]) {
        struct dirent *pDirent;
        DIR *pDir;

        // Ensure correct argument count.
        
        if (argc != 2) {
        	printf ("Usage: testprog <dirname>\n");
        	return 1;
        }
      	
	pDir = opendir (argv[1]);
        if (pDir == NULL) {
            printf ("Cannot open directory '%s'\n", argv[1]);
            return 1;
        }

        // Process each entry.
        while ((pDirent = readdir(pDir)) != NULL) {
		printf ("[%s]\n", pDirent->d_name);
	}
        // Close directory and exit.
        closedir (pDir);
	return 0;
}
