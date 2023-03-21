#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "prototype.h"



int main(){
    Liste *liste = creer_liste();// ici liste est la tête T

    ajouter_ville(liste, "Abidjan", 5616633, 2119);
    ajouter_ville(liste, "bouake", 832371, 1770);
    ajouter_ville(liste, "Daloa", 421819, 1080);
    ajouter_ville(liste, "Yamoussokro", 372559, 2075);
    ajouter_ville(liste, "San-Pedro", 390654, 887);
    ajouter_ville(liste, "Divo" ,294559, 949);

    



    saisi_utilisateur(liste);
    printf("----------------FIN DU PROGRAMME----------------------");
    return 0;
}

