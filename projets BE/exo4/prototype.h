#ifndef __EXO4__
#define __EXO4__


// les structures de base
typedef struct NombrePile{
    int valeur;
    struct NombrePile *suivant; 
}NombrePile;


typedef struct Pile{
    NombrePile *sommet;
}Pile;


/*---------------------------Prototype des fonctions-------------------------------*/
Pile *creer_pile();
void empiler(Pile *pile, int valeur);
void afficherPile(Pile *pile);
int nombreDePile(Pile *pile);
int saisi_utilisateur();
int val_max(Pile *pile);
int val_min(Pile *pile);

#endif