Exercice 1 :

Voir fichier cp-sys.c

1. Dans : man 2 open , soit la page open(2)
2. Dans : man 2 chmod , soit la page chmod(2) (int chmod (const char ⁎path, mode_t mode))
3. Si le deuxième fichier n'existe pas et que le programme omet de le créer, la programme retournera -1
4. Si le deuxième fichier est créé mais que le programme omet de spécifier ses permissions, les permissions par défaut seront utilisées

Exercise 2 : 
Voir fichier cp-std.c

1. Dans : man 3 fopen , soit la page fopen(3)
2. Un nouveau fichier sera crees
3. La constante EOF est utilisée pour indiquer la fin de fichier (End Of File) 

Exercise 3 :
1.  | Temps `cp_std` (ms) |
    |:----------------:|
    | 0,239s |

    |Taille du buffer (octets) | Temps `cp_sys` (ms) |
    |:----------------:|:--------------:|
    |  1               |   1m30,207s    |
    |  8               |   0m10,877s    |
    |  16              |    0m5,637s    |
    |  256             |    0m0,408s    |
    |  512             |    0m0,206s    |
    |  1024            |    0m0,117s    |
    |  2048            |    0m0,077s    |
    |  4096            |    0m0,052s    |
    |  8192            |    0m0,045s    |

2. La taille du buffer utiliser par les fonctions de bibliothèque comme fopen(), fgetc() et fputc() ont un petit buffer 
    mais qui depend il n'est pas explicitement spécifiée par l'utilisateur, mais est déterminée par l'implémentation de 
    la fonction et peut varier selon la plateforme

Exercice 4 :

Voir cp_rev.c

Question 

1. Avec SEEK_END :  lseek(fichierSource, 0, SEEK_END);
2. Avec SEEK_SET :  lseek(fichierSource, i, SEEK_SET);
3. Tout d'abord nous pouvons connaitre ca taille avec seek end comme nous l'avons vu
   Mais aussi avec sys/stat.h et lutilisation de la fonction stat()
   Ou encore avec fseek() et ftell()

Exercice 5 :

Voir read_int.c et write_int.c

Question 

1. Essayer de lire a une position negative peut entraîner un comportement indéfini 
   ou une erreur, en l'occurence dans mon programme j'obtiens des valeur presente dans la memoire
2. Pareil que la question precedente
3. On peut obtenir la taille du fichier de la maniere suivante
   off_t file_size = lseek(fd, 0, SEEK_END);
   Puis placer un if afin deviter quon ai des valeur negative ou des valeurs superieur a la taille du fichier
   if (0 >= pos >= file_size)
4. Le systeme d'exploitation etend automatiquement le fichier jusqu'a lendroit ou nous avons ecrit.