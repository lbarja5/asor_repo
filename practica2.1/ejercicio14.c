//ejercicio 14
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main()
{
	struct tm *tiempo;
	time_t t;
	time(&t);
	tiempo = localtime(&t);
	printf("Año: %i \n", tiempo->tm_year);
	return 0;
}
