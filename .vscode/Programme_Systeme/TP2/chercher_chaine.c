#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <fcntl.h>
#include <limits.h>

#define MAX_BUF_SIZE 4096

void search_in_file(const char *filename, const char *search_string) {
    char buf[MAX_BUF_SIZE];
    ssize_t bytes_read;
    int fd;

    fd = open(filename, O_RDONLY);
    if (fd == -1) {
        perror("Erreur lors de l'ouverture du fichier");
        return;
    }


    while ((bytes_read = read(fd, buf, sizeof(buf))) > 0) {
        if (strstr(buf, search_string) != NULL) {
            printf("%s\n", filename);
            break;
        }
    }

    close(fd);
}

void search_in_directory(const char *dir_name, const char *search_string) {

    DIR *dir;
    struct dirent *entry;
    char path[PATH_MAX];

    dir = opendir(dir_name);
    if (dir == NULL) {
        perror("Erreur lors de l'ouverture du répertoire");
        return;
    }

    while ((entry = readdir(dir)) != NULL) {
        if (strcmp(entry->d_name, ".") == 0 || strcmp(entry->d_name, "..") == 0) {
            continue; 
        }

        snprintf(path, sizeof(path), "%s/%s", dir_name, entry->d_name);

        DIR *subdir = opendir(path);
        if (subdir) {
            closedir(subdir);
            search_in_directory(path, search_string);
        } else {
            search_in_file(path, search_string);
        }

    }

    closedir(dir);
}

int main(int argc, char *argv[]) {
    if (argc != 3) {
        fprintf(stderr, "Utilisation : %s <chaîne> <répertoire>\n", argv[0]);
        return EXIT_FAILURE;
    }

    const char *search_string = argv[1];
    const char *directory = argv[2];

    search_in_directory(directory, search_string);

    return EXIT_SUCCESS;
}
