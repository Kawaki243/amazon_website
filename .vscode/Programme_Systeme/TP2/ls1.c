#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>


#define CHK(op) do { if ((op) == NULL) raler (#op);} while (0)


void raler(const char * msg){
    perror (msg);
    exit (EXIT_FAILURE);
}

int main(){
	DIR *direction;
	struct dirent* enter;
	direction = opendir(".");
	if ( direction == NULL ){
		raler ( " opendir " ) ;
	}
	while ((enter = readdir(direction)) != NULL) {
		if (enter->d_name[0] != '.') {
			printf("%s\n", enter->d_name);
		}
	}
	if ( closedir (direction) == -1){
		raler ( " closedir " ) ;
	}
	return 0;
}