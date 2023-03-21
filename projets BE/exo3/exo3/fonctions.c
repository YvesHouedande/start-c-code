#include "stdlib.h"
#include "stdio.h"
#include "string.h"
#include "prototype.h"




// Initialise une file vide
File *creer_file() {
    File *file = (File *)malloc(sizeof(*file));
    file->premier = NULL;
    file->dernier = NULL;
    return file;
}


// Ajoute une ville à la fin de la file
void enfiler(File *file, char *nom_ville, int population, int superficie) {
    /* On gere deux cas lors de l'enfilage de la liste.
     le cas ou la file est vide et le cas ou la file est non vide.
    */
    Ville *nv_ville = (Ville *)malloc(sizeof(*nv_ville));
    if (nv_ville == NULL) {
        printf("Erreur d'allocation de mémoire\n");
        exit(1);
    }

    strcpy(nv_ville->nom_ville, nom_ville);
    nv_ville->superficie = superficie;
    nv_ville->population = population;
    nv_ville->suivant = NULL;

    if (file->dernier != NULL) {
        file->dernier->suivant = nv_ville;
    }
    file->dernier = nv_ville;

    if (file->premier == NULL) {
        file->premier = nv_ville;
    }
}


// Supprime la ville en tête de file
void defiler(File *file) {
    if (file->premier == NULL) {
        printf("La file est vide\n");
        return;
    }

    Ville *a_supprimer = file->premier;
    file->premier = a_supprimer->suivant;//on actualise l'information sur le premier élément de la file

    if (file->premier == NULL) {
        file->dernier = NULL;
    }

    free(a_supprimer);
}


void afficher(File * file){
    Ville * temp = file->premier;
    while(temp != NULL){
        printf("Nom: %s, population: %d, superficie: %d\n", temp->nom_ville, temp->population, temp->superficie);
        temp = temp->suivant;
    }
}


void supprimer_debut_d(File *file) {
    Ville *temp = file->premier;
    Ville *precedent = NULL;

    while (temp != NULL) {
        if (temp->nom_ville[0] == 'D' || temp->nom_ville[0] == 'd') {
            if (temp == file->premier) {
                file->premier = temp->suivant;
            } else {
                precedent->suivant = temp->suivant;
            }
            if (temp == file->dernier) {
                file->dernier = precedent;
            }
            Ville *a_supprimer = temp;
            temp = temp->suivant;
            free(a_supprimer);
        } else {
            precedent = temp;
            temp = temp->suivant;
        }
    }
}

char *supprimer3e_ville(File *file, char *nom_ville_supprime) {
    if (file->premier == NULL) {
        printf("La file est vide\n");
        return NULL;
    }
    Ville *temp = file->premier;
    Ville *precedent = NULL;
    int compt = 0;
    while (temp != NULL) {
        if (compt == 2) {
            char *nom_ville = temp->nom_ville;
            if (temp == file->premier) {
                file->premier = temp->suivant;
            } else {
                precedent->suivant = temp->suivant;
            }
            if (temp == file->dernier) {
                file->dernier = precedent;
            }
            Ville *a_supprimer = temp;
            temp = temp->suivant;
            strcpy(nom_ville_supprime, a_supprimer->nom_ville);
            free(a_supprimer);
            return nom_ville;
        }
        precedent = temp;
        temp = temp->suivant;
        compt++;
    }
    printf("La file n'a pas assez d'éléments\n");
    return NULL;
}
