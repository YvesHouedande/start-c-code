#ifndef __EXO3__
#define __EXO3__


// Quelques structures de bases
typedef struct Ville {
    char nom_ville[100];
    int superficie;
    int population;
    struct Ville *suivant;
} Ville;

typedef struct File {
    Ville *premier;
    Ville *dernier;
} File;


// declaration de quelques prototypes
File *creer_file();
void enfiler(File *file, char *nom_ville, int population, int superficie);
void defiler(File *file);
void afficher(File * file);
void supprimer_debut_d(File *file);
char *supprimer3e_ville(File *file, char *nom_ville_supprime);

#endif