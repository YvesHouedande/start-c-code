#ifndef __EXO2__
#define __EXO2__


// les structures de base
typedef struct Ville{
    char* nom_ville;//la taille sera calculer automatiquement
    int population;
    int superficie;
    struct Ville *suivant; 
}Ville;


typedef struct Pile{
    Ville *sommet;
}Pile;


/*---------------------------Prototype des fonctions-------------------------------*/
Pile *creer_pile();
void empiler(Pile *pile, char *nom_ville, int population, int superficie);
void supprimer3_e_ville(Pile *pile, char *nom_ville_supprimee);
void afficher_pile(Pile *pile);
void afficher_pile(Pile *pile);
void supp_ville_d(Pile *pile);
int saisi_utilisateur();

#endif