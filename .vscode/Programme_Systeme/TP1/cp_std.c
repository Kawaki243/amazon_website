#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHK(op) do { if ((op) == NULL) raler (#op);} while (0)


void raler(const char * msg){
    perror (msg);
    exit (EXIT_FAILURE);
}

int main(int argc, char* argv[]){
	// Préconditions : fichier source, fichier destination, taille du buffer
	// argv[1] : nom du fichier source
	// argv[2] : nom du fichier destination
	FILE* fileSource;
	FILE* fileDestination;
	int c;
	fileSource = fopen(argv[1],"r");
	CHK(fileSource);
	fileDestination = fopen(argv[2],"w");
	CHK(fileDestination);
	while((c = getc(fileSource)) != EOF){
		fputc(c, fileDestination);
	}
	
	if ( fclose(fileSource) == -1){
		raler("fclose␣fichier1");
	}
	if ( fclose(fileDestination) == -1){
		raler("fclose␣fichier2");
	}
	return 0;
}