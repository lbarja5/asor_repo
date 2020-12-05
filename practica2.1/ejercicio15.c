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
	char semana[20], dia[10],mes[10],hora[10],min[10];
	tiempo = localtime(&t);
	setlocale(LC_ALL,"es_ES");
	if(tiempo == NULL) {
		perror("Se ha producido un error en localtime");
		return -1;
	}
	if(strftime(semana,sizeof(semana),"%A",tiempo) == 0||
		strftime(dia,sizeof(dia),"%d",tiempo) == 0||
		strftime(mes,sizeof(mes),"%B",tiempo) == 0||
		strftime(hora,sizeof(hora),"%H",tiempo) == 0||
		strftime(min,sizeof(min),"%M",tiempo) == 0)
	{
		printf("Error en strftime");
		return -1;
		
	}
	printf("%s, %s de %s de %i, %s:%s\n",semana,dia,mes,tiempo->tm_year+1900,hora,min);
	return 0;
}

