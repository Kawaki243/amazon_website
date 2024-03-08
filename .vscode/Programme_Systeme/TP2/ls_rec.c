#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <string.h>
#include <limits.h>
#include <limits.h>

#define CHK(op) do { if ((op) == -1) raler (#op);} while (0)


void raler(const char * msg){
    perror (msg);
    exit (EXIT_FAILURE);
}

void ls_rec(char *path) {

    DIR *direction;
    struct dirent *enter;
    char new_path[PATH_MAX];

    direction = opendir(path);

    while ((enter = readdir(direction)) != NULL) { 
        if (strcmp(enter->d_name, ".") != 0 && strcmp(enter->d_name, "..") != 0 && enter->d_name[0]!= '.') {
            snprintf(new_path, sizeof(new_path), "%s/%s", path, enter->d_name); 
            printf("%s\n", new_path);
            DIR *subdirection = opendir(new_path);
            if (subdirection){
                closedir(subdirection);
                ls_rec(new_path);
            }
        }
    }
    closedir(direction);
}
int main(int argc, char *argv[]) {
    ls_rec(argv[1]);
    return 0;
}