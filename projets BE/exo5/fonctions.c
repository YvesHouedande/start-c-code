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


void inserer_nb(Pile *pile, int nombre) {
    NombrePile *temp = pile->sommet;
    NombrePile *prec = NULL;
    NombrePile *nouveau = (NombrePile *)malloc(sizeof(NombrePile));
    nouveau->valeur = nombre;
    while (temp != NULL && temp->valeur > nombre) {
        prec = temp;
        temp = temp->suivant;
    }
    if (prec == NULL) {
        nouveau->suivant = pile->sommet;
        pile->sommet = nouveau;
    }
    else {
        nouveau->suivant = prec->suivant;
        prec->suivant = nouveau;
    }
}

void afficherPile(Pile *pile) {
    if (pile->sommet == NULL) {
        printf("La pile est vide !\n");
        return;
    }
    NombrePile *temp = pile->sommet;
    printf("Les piles: ");
    while (temp != NULL) {
        printf("%d ", temp->valeur);
        temp = temp->suivant;
    }
    printf("\n");
}


void saisi_utilisateur(Pile *pile){
    int nb_choix;
    printf("Combien de nombre voulez vous inserer?:");
    scanf("%d", &nb_choix);
    int nb_a_inserer = 0;
    for(int i=1; i<=nb_choix; i++){
        printf("Entrer une valeur a inserer");
        scanf("%d", &nb_a_inserer);
        inserer_nb(pile, nb_a_inserer);
    }
}

