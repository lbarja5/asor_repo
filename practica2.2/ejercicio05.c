#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main()
{
	int fd = open("5.txt", O_RDWR|O_CREAT, 0645);
	if(fd == -1)
		printf("ERROR en open");
	close(fd);
	return 0;
}
//# ls -l
//-rw-r--r-x 1 root root    0 Dec 19 13:37 5.txt
