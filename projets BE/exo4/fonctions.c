#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "prototype.h"


Pile *creer_pile() {
    Pile *pile = (Pile *)malloc(sizeof(Pile));
    pile->sommet = NULL;
    return pile;
}

void empiler(Pile *pile, int valeur) {
    NombrePile *nb_a_empiler = (NombrePile *)malloc(sizeof(NombrePile));
    if(nb_a_empiler == NULL){
        printf("Erreur d'allocation !");
        exit(1);
    }
    nb_a_empiler->valeur = valeur;
    nb_a_empiler->suivant = pile->sommet;
    pile->sommet = nb_a_empiler;
}

int val_max(Pile *pile) {
    if (pile->sommet == NULL) {
        printf("La pile est vide !\n");
        return -1;
    }
    NombrePile *temp = pile->sommet;
    int max = temp->valeur;
    while (temp != NULL) {
        if (temp->valeur > max) {
            max = temp->valeur;
        }
        temp = temp->suivant;
    }
    return max;
}

int val_min(Pile *pile) {
    if (pile->sommet == NULL) {
        printf("La pile est vide !\n");
        return -1;
    }
    NombrePile *temp = pile->sommet;
    int max = temp->valeur;
    while (temp != NULL) {
        if (temp->valeur < max) {
            max = temp->valeur;
        }
        temp = temp->suivant;
    }
    return max;
}

int nombreDePile(Pile *pile) {
    if (pile->sommet == NULL) {
        printf("La pile est vide !\n");
        return 0;
    }
    NombrePile *temp = pile->sommet;
    int compt = 0;
    while (temp != NULL) {
        compt++;
        temp = temp->suivant;
    }
    return compt++;
}


void afficherPile(Pile *pile) {
    if (pile->sommet == NULL) {
        printf("La pile est vide !\n");
        return;
    }
    NombrePile *temp = pile->sommet;
    printf("Les piles sont: ");
    while (temp != NULL) {
        printf("%d ", temp->valeur);
        temp = temp->suivant;
    }
    printf("\n");
}






