#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

#define CHK(op) do { if ((op) == -1) raler (#op); } while (0)


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
    fileSource = open(argv[1], O_RDONLY);
    CHK(fileSource);
    fileDestination = open(argv[2], O_WRONLY | O_TRUNC | O_CREAT, 0666);
    CHK(fileDestination);
    int nb_octet;
    while((nb_octet = read(fileSource, buff, buffer)) > 0){
	write(fileDestination, buff, nb_octet);
    }
    CHK(close(fileSource));
    CHK(close(fileDestination));
    return 0;
}