#include "stdlib.h"
#include "string.h"
#include "stdio.h"
#include "prototype.h"


int main(){
    File *file = creer_file();






    enfiler(file, "Dyakro", 787878, 8989);
    enfiler(file, "Dabidjan", 787878, 8989);
    enfiler(file, "blean", 974878, 8989);
    enfiler(file, "AvionDeChasse", 297878, 8989);
    enfiler(file, "Developpement", 546878, 8989);

    // supprimer_debut_d(file);
    printf("\n---------------------------LA file avant supresion-------------------\n");
    afficher(file);

    //suppression de la troisieme ville
    char *ville_3;
    supprimer3e_ville(file, ville_3);
    if (ville_3){
        printf("\n---------------LA file apres supression de la troisieme ville: %s-----------------\n", ville_3);
        afficher(file);
    }
    printf("\n---------------------------LA file apres supression des villes se terminant par la lettre d -------------------\n");
    supprimer_debut_d(file);
    afficher(file);


    return 0;
}