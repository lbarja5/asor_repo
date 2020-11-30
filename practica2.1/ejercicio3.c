#include <sys/utsname.h>
#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>

#include <sys/types.h>
#include <unistd.h>

int main(){
    int i;
    for(i = 0; i < 255;i++){
        
        if(strerror(i) != NULL){
            printf("%d: %s\n",i,strerror(i));
        }
    }
    return 1;
}