#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHK(op) do { if ((op) == -1) raler (#op);} while (0)


void raler(const char * msg){
    perror (msg);
    exit (EXIT_FAILURE);
}

int main(int argc, char* argv[]){
	// Préconditions : fichier source, fichier destination, taille du buffer
	// argv[1] : nom du fichier source
	// argv[2] : nom du fichier destination
	// argv[3] : taille du buffer en octets
	int buffer = atoi(argv[3]);
	char buff[buffer];
	int fileSource;
	int fileDestination;
	char c;
	fileSource = open(argv[1], O_RDONLY);
	CHK(fileSource);
	fileDestination = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0666);
	CHK(fileDestination);
	off_t taille_fichier = lseek(fileSource, 0, SEEK_END);
	for(off_t i = taille_fichier - 1; i >= 0; i--){
		off_t position = lseek(fileSource, i, SEEK_SET);
		int lecture = read(fileSource, &c, 1);
		int ecriture = write(fileDestination, &c, 1);
	}
    CHK(close(fileSource));
    CHK(close(fileDestination));
    return 0;
}