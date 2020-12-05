//ejercicio 13
#include <sys/time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>


int main()
{
	struct timeval ini,fin;
	errno = 0;
	errno = gettimeofday(&ini,NULL);
	if(errno==-1)
	{
		perror("Se ha producido un error en gettimeofday");
		return -1;
	}

	int i=0;
	while(i<1000000)
		i=i+1;

        errno = gettimeofday(&fin,NULL);
        if(errno==-1)
        {
                perror("Se ha producido un error en gettimeofday");
                return -1;
        }
	
	long tiempo = fin.tv_usec - ini.tv_usec;
	printf("Ha trascurrido un tiempo de %ld segundos\n",tiempo);
	return 0;
}

