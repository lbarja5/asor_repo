//ejercicio 15
#include <time.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <locale.h>

int main()
{
	struct tm *tiempo;
	time_t t;
	time(&t);
	char s[200];
	tiempo = localtime(&t);
	setlocale(LC_ALL,"es_ES");
	if(tiempo == NULL) {
		perror("Se ha producido un error en localtime");
		return -1;
	}
	char format[10] = "%A";
	if(strftime(s,sizeof(s),format,tiempo) == 0)
	{
		printf("Error en strftime");
		return -1;
		
	}
	printf("%s",s);
	return 0;
}

