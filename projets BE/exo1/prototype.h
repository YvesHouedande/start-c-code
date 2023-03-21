#ifndef __LISTE__
#define __LISTE__

/*
cette structure represente le noeud de chaque element ville 
*/ 
typedef struct maillon_ville{
    char* ville;
    int population;
    int superficie;
    struct maillon_ville *suivant; 
}maillon_ville;


// cette structure contient comme champ "tête" qui represente le T de notre liste chainée precisé dans l'enoncé
/* c'est la structure de controle de notre programme, c'est a dire qu'elle contiendra
des valeurs importantes concernant notre liste chainé, comme la taille, la tête*/
typedef struct Liste{
    maillon_ville *tete;
    int nb_maillons;// taille de la liste.
    int nb_ville_sup;// taille du tableau qui contiendra une liste des villes ayant plus de 50000hbts
}Liste;

//prototype des fonctions
Liste *creer_liste();
void ajouter_ville(Liste * liste, char *ville, int population, int superficie);
int compter_nb_villes(Liste * liste);
void afficher_liste(Liste *liste);
void supprimer_ville_1(Liste *liste);
void supprimer_ville_fin(Liste *liste);
void sup_ville_plus_400_mille(Liste * liste);
maillon_ville *recuperer_villes(Liste *liste);
void afficher_option();
void saisi_utilisateur(Liste *liste);

#endif