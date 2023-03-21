#ifndef __EXO5__
#define __EXO5__


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
void inserer_nb(Pile *pile, int nombre);
void afficherPile(Pile *pile);
void saisi_utilisateur(Pile *pile);
#endif