#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "prototype.h"


// typedef struct Ville{
//     char* nom_ville;//la taille sera calculer automatiquement
//     int population;
//     int superficie;
//     struct Ville *suivant; 
// }Ville;


// typedef struct Pile{
//     Ville *sommet;
// }Pile;



// Pile *creer_pile(){
//     Pile * pile = (Pile *)malloc(sizeof(*pile));
//     pile->sommet = NULL;
//     return pile;
// }



// void empiler(Pile *pile, char *nom_ville, int population, int superficie)
// {
//     Ville *nv_ville = (Ville *)malloc(sizeof(*nv_ville));
//     if (nv_ville == NULL) {
//         printf("Erreur d'allocation memoire\n");
//         return;
//     }
//     nv_ville->nom_ville = (char *)malloc(sizeof(char) * (strlen(nom_ville) + 1));
//     if (nv_ville->nom_ville == NULL) {
//         printf("Erreur d'allocation memoire\n");
//         free(nv_ville);
//         return;
//     }
//     strcpy(nv_ville->nom_ville, nom_ville);
//     nv_ville->superficie = superficie;
//     nv_ville->population = population;
//     nv_ville->suivant = pile->sommet;
//     pile->sommet = nv_ville;// nv_ville devient le sommet
// }


// //supprimer ville 3
// Pile *supprimer3_e_ville(Pile *pile){
//     if(pile->sommet == NULL){
//         printf("La pile est vide!\n");
//         return pile;
//     }


//     Ville *temp = pile->sommet;//le premier element dela pile
//     int i;
//     for(i = 1; i < 2; i++){//on parcours donc a partir de l'indice 1 qui reperesente le deuxieme element
//     //a partir de l'indice 3 nous sommes au deuxieme element
//         if(temp->suivant == NULL){
//             printf("La pile ne contient pas assez de villes!\n");
//             return pile;
//         }
//         temp = temp->suivant;
//     }

//     Ville *temp2 = temp->suivant;
//     temp->suivant = temp2->suivant;
//     free(temp2);
//     return pile;

// }

// void afficher_pile(Pile *pile) {
//     Ville *temp = pile->sommet;
//     while(temp != NULL) {
//         printf("Ville: %s, Population: %d, Superficie: %d\n", temp->nom_ville, temp->population, temp->superficie);
//         temp = temp->suivant;
//     }
// }



// void supp_ville_d(Pile *pile) {
//     if (pile->sommet == NULL) {
//         printf("La pile est vide!\n");
//         return;
//     }

//     Ville *temp = pile->sommet;
//     Ville *prec = NULL;
//     while (temp != NULL) {
//         if (temp->nom_ville[0] == 'D' || temp->nom_ville[0] == 'd') {
//             if (prec == NULL) {
//                 pile->sommet = temp->suivant;
//             } else {
//                 prec->suivant = temp->suivant;
//             }
//             free(temp->nom_ville);// on libere la memoire allouer dynamiquement à la chaine de caractére
//             free(temp);//on libere l'espace allouer auparavant
//             temp = prec == NULL ? pile->sommet : prec->suivant;
//         } else {
//             prec = temp;
//             temp = temp->suivant;
//         }
//     }
//     if (prec == NULL) {
//         printf("La pile ne contient pas de ville commençant par D!\n");
//     }
// }

// //cette fonction va permettre de recupperer les saisies de l'utilisateur et de gerrer les erreurs
// int saisi_utilisateur(){
//     int number = 0;
//     // int i = 1;
//     printf("Combien de pile voulez vous empiler ?\n");
//     int ret = scanf("%d", &number);
//     //verifions si le choix de l'utilsiateeur est correcte
//     while(ret==0){
//         printf("\nla valeur saisie n'est pas juste !!!!! \n");
//         scanf("%*[^\n]");//clean
//         printf("Combien de pile voulez vous empiler ?\n");
//         ret = scanf("%d", &number);
//     }
         
//     return number;
// }



int main (){
    Pile *pile = creer_pile();
    int nb_habitants, superficie, choix = 0;
    char nom_ville[100];

    printf("Combien de ville voulez vous ajouter:");
    scanf("%d", &choix);

    for(int i=1; i<=choix; i++){
        printf("Entrez Le nom de la ville:");
        scanf("%s", &nom_ville);
        printf("Entrer la superficie de la ville:");
        scanf("%d", &superficie);
        printf("Entrer le nombre d'habitants de la ville:");
        scanf("%d", &nb_habitants);
        printf("\n");
        empiler(pile, nom_ville, nb_habitants, superficie);
    }
    



    // empiler(pile, "Paris", 22000000, 105);
    // empiler(pile, "Marseille", 8610000, 240);
    // empiler(pile, "Dyon", 5150000, 47);
    // empiler(pile, "Doulouse", 1180000, 118);
    // empiler(pile, "Dice", 3430000, 71);


    printf("--------------------Pile avant suppression:---------------------------\n");
    afficher_pile(pile);
     char * ville_3;
    supprimer3_e_ville(pile, ville_3);
    if(ville_3){
        printf("-------------------Pile apres suppression de la 3eme ville:%s -----------------:\n", ville_3);
        afficher_pile(pile);
        }

    printf("\n-------------------------Pile apres suppression des villes commencant par La lettre D--------------------:\n");
    supp_ville_d(pile);
    afficher_pile(pile);
    free(ville_3);
    return 0;
}