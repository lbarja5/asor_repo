#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

int main(int argc, char **argv)
{
        struct utsname buf;
        errno = 0;
        if(uname(&buf) != 0)
        {
                perror("Se ha producido un error en uname");
                return 1;
        }
        printf("Nombre del sistema: %s\n", buf.sysname);
        printf("Nombre del host: %s\n", buf.nodename);
        printf("Release del SO: %s\n", buf.release);
	printf("Version del SO: %s\n", buf.version);
	printf("Hardware: %s\n", buf.machine);
	#ifdef _GNU_SOURCE
		printf("Nombre del dominio: %s\n", buf.domainname);
	#endif
	return 0;
}

