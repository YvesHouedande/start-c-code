#include <stdio.h>
#include <stdlib.h>

// CONSTRUCTION DE LA STRUCTURE PILE
typedef struct PILE {
    int valeur;
    struct PILE *suivant;
};
typedef struct PILE PILE;
            // PROCEDURE POUR AJOUTER UN ELEMENT
void empiler(PILE **tete, int element) {
    // ALLOCATION DE MEMOIRE POUR UN ELEMENT
    PILE *nouveau_elm = (struct PILE *)malloc(sizeof(struct PILE));
    nouveau_elm->valeur = element;
    nouveau_elm->suivant = (*tete);
    (*tete) = nouveau_elm;
}

// PROCEDURE POUR TRIER LA PILE
void tri_bulle_pile(PILE *tete) {
     PILE *pointeur_1, *pointeur_2;
    int tempo;
            // PARCOURIR LA PILE
    for (pointeur_1 = tete; pointeur_1 != NULL; pointeur_1 = pointeur_1->suivant) {
        for (pointeur_2 = pointeur_1->suivant; pointeur_2 != NULL; pointeur_2 = pointeur_2->suivant) {

            if (pointeur_1->valeur > pointeur_2->valeur) {  // ECHANGER LES VALEURS
                tempo = pointeur_1->valeur;
                pointeur_1->valeur = pointeur_2->valeur;
                pointeur_2->valeur = tempo;
            }
        }
    }
}
            // PROCEDURE POUR AFFICHER LA LISTE
void afficher_liste(PILE *tete) {
    while (tete != NULL) {
        printf("%d ; ", tete->valeur);
        tete = tete->suivant;
    }
    printf(" fin de liste.\n\n ");
}

int main() {
    PILE *pile = NULL; //Initialisation de la liste
            // CREATION DE LA LISTE EN AJOUTANT DES ELEMENTS
    empiler(&pile, 16);
    empiler(&pile, 19);
    empiler(&pile, 34);
    empiler(&pile, 4);
    empiler(&pile, 25);
    empiler(&pile, 9);
    empiler(&pile, 130);
    empiler(&pile, 1);
    empiler(&pile, 201);
    empiler(&pile, 56);
    empiler(&pile, 300);
    empiler(&pile, 39);

    printf("\nLA LISTE AVANT LE TRI : "); // AVANT LE TRI
    afficher_liste(pile);

    tri_bulle_pile(pile); // TRI DE LA LISTE

    printf("\n\nVOICI LA LISTE EN ORDRE CROISSANT APRES LE TRI : \n"); //APRES LES TRI
    afficher_liste(pile);

    return 0;
}
