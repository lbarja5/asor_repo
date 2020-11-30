#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include <sys/types.h>
#include <unistd.h>

int main(){
    errno = setuid(0);
    if (errno == -1)
        perror("Se ha producido un error en setuid");
    return 1;
}