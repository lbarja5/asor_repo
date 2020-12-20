#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>

int main(int argc, char *argv[])
{
	//argv[1] -> path directorio valido
	if(argc != 2){
		fprintf(stderr,"Usage:%s <pathname>\n", argv[0]);
		return -1;
	}
	struct stat buf;
	if(stat(argv[1], &buf) == -1)
	{
		perror("stat()");
		return -1;
	}
	if((buf.st_mode & S_IFMT) != S_IFDIR)
	{
		fprintf(stderr,"%s debe de ser un directorio\n",argv[1]);
		return -1;
	}
	printf("Antes dir\n");
	char *dirname = argv[1];
	DIR *dir;
	printf("Dirname: %s\n",dirname);
	dir = opendir (dirname);
	printf("a");
	if(dir == NULL)
	{
		perror("opendir()");
                return -1;
	}
	printf("Fichero abierto");
	//Para cada entrada
	struct dirent *entradas;
	entradas = readdir(dir);
	printf("Antes while");
	while(entradas != NULL)
	{
	//-Fichero normal -> print nombre
	//-Directorio -> print nombre + '/'
	//-Enlace simbolico -> print nombre + '->' + nombre fich enlazado
	//-Ejecutable -> print nombre + '*'
		printf("Tipo: %s\n", entradas->d_type);
		//switch(entradas->d_type)
		closedir(dir);
		entradas = readdir(dir);
	}
	//-Fichero normal -> print nombre
	//-Directorio -> print nombre + '/'
	//-Enlace simbolico -> print nombre + '->' + nombre fich enlazado
	//-Ejecutable -> print nombre + '*'
	//Print tamaño total 
	
	closedir(dir);
	return 0;
}
