#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <fcntl.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>

int64_t read_int(const char *filename, off_t pos) {
    
    int fd = open(filename, O_RDONLY);                     // Ouvre le fichier en lecture seule
    
    
    off_t offset = lseek(fd, pos, SEEK_SET);               // Déplacement du curseur à la position spécifiée

    
    int64_t value;
    ssize_t bytes_read = read(fd, &value, sizeof(value));  // Lecture de l'entier de 64 bits depuis le fichier

    close(fd);

    return value;
}

int main(int argc, char *argv[]) {

    const char *filename = argv[1];
    off_t pos = atoll(argv[2]);                             // Conversion de la position en off_t

    int64_t value = read_int(filename, pos);

    printf("La valeur lue à la position %ld est : %ld\n", pos, value);

    return 0;
}
