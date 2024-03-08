#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>

void file_info(const char* filename){
	struct stat file_stat;
	stat(filename,&file_stat);

	printf("UID : %d\n",file_stat.st_uid);
	printf("GID :  %d\n",file_stat.st_gid);
	printf("File size :  : %d octets\n",file_stat.st_size);
	if(S_ISREG(file_stat.st_mode)){
		printf("Type : Regulier\n");
	}
	else if((S_ISDIR(file_stat.st_mode))){
		printf("Type : Repertoire\n");
	}
	else{
		printf("Type : Inconnu\n");
	}
}

int main(int argc, char *argv[]){
	file_info(argv[1]);
	return 0;
}