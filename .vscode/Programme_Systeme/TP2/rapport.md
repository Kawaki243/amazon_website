Exercice 1

Voir my_stat.c

Question

1. Dans le man : man 2 stat\
2. C'est st_mode et cest avec loperation bit a bit : file_stat.st_mode & (S_IRWXU | S_IRWXG | S_IRWXO)
3. En base octal on obtiens trois chiffres le premier represente les permissions de lutilisateur, le deuxieme du groupe , le troisieme des autres
    chaque chiffre ce decompose en binaire de la maniere suivante ou on a : lecture (4), écriture (2) et exécution (1)
    7 (111 en binaire) : Lecture, écriture et exécution.
    6 (110 en binaire) : Lecture et écriture.
    5 (101 en binaire) : Lecture et exécution.
    4 (100 en binaire) : Lecture seule.
    3 (011 en binaire) : Écriture et exécution.
    2 (010 en binaire) : Écriture seule.
    1 (001 en binaire) : Exécution seule.
    0 (000 en binaire) : Aucune permission.


 4. Les macros POSIX pour verifier le type de fichier sont :
    S_ISREG(mode) : Vérifie si le fichier est un fichier ordinaire (régulier).
    S_ISDIR(mode) : Vérifie si le fichier est un répertoire.
    S_ISCHR(mode) : Vérifie si le fichier est un périphérique caractère.
    S_ISBLK(mode) : Vérifie si le fichier est un périphérique bloc.
    S_ISFIFO(mode) : Vérifie si le fichier est un tube nommé (fifo).
    S_ISLNK(mode) : Vérifie si le fichier est un lien symbolique.
    S_ISSOCK(mode) : Vérifie si le fichier est une prise (socket).


Exercice 2

voir ls2.c

Question

1. A l'aide de la bibliotheque <dirent.h> qui va lire les fichier puis un if entry->d_name[0] != '.'
2. Avec les POSIX :
    S_IRUSR
    S_IWUSR
    S_IXUSR
    S_IRGRP
    S_IWGRP
    S_IXGRP
    S_IROTH
    S_IWOTH
    S_IXOTH

Exercice 3

Voir ls_rec.c


1.     while ((entry = readdir(dir)) != NULL) { // Lis tout les fichiers ou repertoire dans le répertoire
        if (strcmp(entry->d_name, ".") != 0 && strcmp(entry->d_name, "..") != 0 && entry->d_name[0]!= '.') {
            snprintf(new_path, sizeof(new_path), "%s/%s", path, entry->d_name); // stock dans new path : path/entry->d_name
            printf("%s\n", new_path);
            DIR *subdir = opendir(new_path);
            if (subdir) {
                closedir(subdir);
                ls_rec(new_path);
            }
        }
    }
    comme ci dessus

2.  Le deuxieme argument de snprintf et de taille sizeof(new_path) , ou new path est defini comme tel
    char new_path[PATH_MAX];
    
3. Readdir retourne NULL si il arrive a la fin du repertoire ou quil rencontre une erreur.

4. entry = readdir(dir) != NULL



Exercice 4

1.  while ((bytes_read = read(fd, buf, sizeof(buf))) > 0) {
        if (strstr(buf, search_string) != NULL) {
            printf("%s\n", filename);
            break;
        }
    }