#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>

#define CHK(op) do { if ((op) == NULL) raler (#op);} while (0)


void raler(const char * msg){
    perror (msg);
    exit (EXIT_FAILURE);
}

void print_files(mode_t mode) {
    char files[11];
    strcpy(files, "----------");
    if (S_ISDIR(mode)) files[0] = 'd';  
    if (mode & S_IRUSR) files[1] = 'r';  
    if (mode & S_IWUSR) files[2] = 'w';  
    if (mode & S_IXUSR) files[3] = 'x';  
    if (mode & S_IRGRP) files[4] = 'r';  
    if (mode & S_IWGRP) files[5] = 'w';  
    if (mode & S_IXGRP) files[6] = 'x';  
    if (mode & S_IROTH) files[7] = 'r';  
    if (mode & S_IWOTH) files[8] = 'w';
    if (mode & S_IXOTH) files[9] = 'x';
    printf("%s", files);
}

int main() {
    DIR *direction;
    struct dirent *enter;
    struct stat file_stat;

    direction = opendir(".");
    if(direction == NULL){
	raler("opendir");
    }
    while ((enter = readdir(direction)) != NULL) {
	if (enter->d_name[0] != '.') {
		stat(enter->d_name, &file_stat);
            print_files(file_stat.st_mode);
            printf(" %s\n", enter->d_name);
      }
    }
    if(closedir(direction) == -1){
        raler("closedir");
    }
    return 0;
}