#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "prototype.h"

int main(){
    Pile *pile = creer_pile();
    empiler(pile, 1);
    empiler(pile, 74);
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

    afficherPile(pile);
    printf("la valeur min est: %d\n", val_min(pile));
    printf("la valeur max est: %d\n", val_max(pile));
    int val = nombreDePile(pile);
    printf("Le nombre de piles est %d", val);
    return 0;
}


