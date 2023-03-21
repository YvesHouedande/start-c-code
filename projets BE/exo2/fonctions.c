#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "prototype.h"





Pile *creer_pile(){
    Pile * pile = (Pile *)malloc(sizeof(*pile));
    pile->sommet = NULL;
    return pile;
}

void empiler(Pile *pile, char *nom_ville, int population, int superficie)
{
    Ville *nv_ville = (Ville *)malloc(sizeof(*nv_ville));
    if (nv_ville == NULL) {
        printf("Erreur d'allocation memoire\n");
        return;
    }
    nv_ville->nom_ville = (char *)malloc(sizeof(char) * (strlen(nom_ville) + 1));
    if (nv_ville->nom_ville == NULL) {
        printf("Erreur d'allocation memoire\n");
        free(nv_ville);
        return;
    }
    strcpy(nv_ville->nom_ville, nom_ville);
    nv_ville->superficie = superficie;
    nv_ville->population = population;
    nv_ville->suivant = pile->sommet;
    pile->sommet = nv_ville;// nv_ville devient le sommet
}



//supprimer ville 3
// char *supprimer3_e_ville(Pile *pile){
//     if(pile->sommet == NULL){
//         printf("La pile est vide!\n");
//         return " ";
//     }


//     Ville *temp = pile->sommet;//le premier element dela pile
//     int i;
//     for(i = 1; i < 2; i++){//on parcours donc a partir de l'indice 1 qui reperesente le deuxieme element
//     //a partir de l'indice 3 nous sommes au deuxieme element
//         if(temp->suivant == NULL){
//             printf("La pile ne contient pas assez de villes!\n");
//             return " ";
//         }
//         temp = temp->suivant;
//     }

//     Ville *temp2 = temp->suivant;
//     temp->suivant = temp2->suivant;
//     char * nom_ville = (char *)malloc(strlen(temp2->nom_ville)+1);
//     strcpy(nom_ville, temp2->nom_ville);
//     free(temp2);
//     return nom_ville;

// }


void supprimer3_e_ville(Pile *pile, char *nom_ville_supprimee){
    if(pile->sommet == NULL){
        printf("La pile est vide!\n");
        return;
    }

    Ville *temp = pile->sommet;
    int i;
    for(i = 1; i < 3; i++){
        if(temp->suivant == NULL){
            printf("\nLa pile ne contient pas assez de villes pour pouvoir supprimer une troisieme ville!\n");
            return;
        }
        temp = temp->suivant;
    }

    Ville *temp2 = temp->suivant;
    temp->suivant = temp2->suivant;
    strcpy(nom_ville_supprimee, temp2->nom_ville);
    free(temp2);
}



void afficher_pile(Pile *pile) {
    Ville *temp = pile->sommet;
    while(temp != NULL) {
        printf("Ville: %s, Population: %d, Superficie: %d\n", temp->nom_ville, temp->population, temp->superficie);
        temp = temp->suivant;
    }
}


void supp_ville_d(Pile *pile) {
    if (pile->sommet == NULL) {
        printf("La pile est vide!\n");
        return;
    }

    Ville *temp = pile->sommet;
    Ville *prec = NULL;
    while (temp != NULL) {
        if (temp->nom_ville[0] == 'D' || temp->nom_ville[0] == 'd') {
            if (prec == NULL) {
                pile->sommet = temp->suivant;
            } else {
                prec->suivant = temp->suivant;
            }
            free(temp->nom_ville);// on libere la memoire allouer dynamiquement à la chaine de caractére
            free(temp);//on libere l'espace allouer auparavant
            temp = prec == NULL ? pile->sommet : prec->suivant;
        } else {
            prec = temp;
            temp = temp->suivant;
        }
    }
    if (prec == NULL) {
        printf("La pile ne contient pas de ville commençant par D!\n");
    }
}


//cette fonction va permettre de recupperer les saisies de l'utilisateur et de gerrer les erreurs
int saisi_utilisateur(){
    int number = 0;
    // int i = 1;
    printf("Combien de pile voulez vous empiler ?\n");
    int ret = scanf("%d", &number);
    //verifions si le choix de l'utilsiateeur est correcte
    while(ret==0){
        printf("\nla valeur saisie n'est pas juste !!!!! \n");
        scanf("%*[^\n]");//clean
        printf("Combien de pile voulez vous empiler ?\n");
        ret = scanf("%d", &number);
    }
         
    return number;
}