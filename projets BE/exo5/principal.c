#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "prototype.h"

int main(){
    Pile *pile = creer_pile();
    empiler(pile, 1);
    empiler(pile, 4);
    empiler(pile, 9);
    empiler(pile, 13);
    empiler(pile, 16);
    empiler(pile, 19);
    empiler(pile, 25);
    empiler(pile, 34);
    empiler(pile, 39);
    empiler(pile, 56);
    empiler(pile, 201);
    empiler(pile, 300);


    printf("--------------------Avant insertion-----------------------");
    afficherPile(pile);

    // inserer_nb(pile, 12);
    // inserer_nb(pile, 24);
    // inserer_nb(pile, 35);
    // inserer_nb(pile, 305);
    // afficherPile(pile);

    saisi_utilisateur(pile);

    printf("-----------------------------Apres Insertion-----------------------");
    afficherPile(pile);
    return 0;
}


