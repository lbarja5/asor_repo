//ejercicio 10
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <pwd.h>

int main(int argc, char **argv)
{
	struct passwd *pw;
	uid_t user = getuid();
	pw = getpwuid(user);
	
	if(pw != NULL)
	{	
		printf("Nombre de usuario: %s\n",pw->pw_name);
		printf("Directorio home: %s\n",pw->pw_dir);
		printf("Descripcion del usuario: %s\n",pw->pw_gecos);
	}
	else
		perror("Se ha producido un error en getpwuid");
	return 0;
}

