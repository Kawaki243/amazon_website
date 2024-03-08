#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

void write_int(const char *filename, off_t pos, int64_t value) {

    int fd = open(filename, O_RDWR | O_CREAT, 0666);          // Ouvre le fichier en écriture et lecture, en le créant s'il n'existe pas

    off_t offset = lseek(fd, pos, SEEK_SET);                  // Déplacement du curseur à la position spécifiée

    ssize_t bytes_written = write(fd, &value, sizeof(value)); // Écriture de l'entier de 64 bits dans le fichier

    close(fd);                                                // Fermeture du fichier
}

int main(int argc, char *argv[]) {

    const char *filename = argv[1];
    off_t pos = atoll(argv[2]);                               // Conversion de la position en off_t
    int64_t value = atoll(argv[3]);                           // Conversion de la valeur en int64_t

    write_int(filename, pos, value);

    return 0;
}