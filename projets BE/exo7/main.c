#include <stdio.h>
#include <stdlib.h>

// Structure de pile
struct noeud {
    int valeur;
    struct noeud *suivant;
};

// Prototype de fonction pour ajouter un �l�ment � la pile
void empiler(struct noeud **tete_ref, int nouvelle_valeur);

// Prototype de fonction pour retirer un �l�ment de la pile
int depiler(struct noeud **tete_ref);

// Prototype de fonction pour fusionner les piles
struct noeud *fusionTriee(struct noeud *a, struct noeud *b);

// Prototype de fonction pour afficher la pile
void afficherListe(struct noeud *noeud);

int main()
{
    struct noeud *resultat = NULL;
    struct noeud *pileA = NULL;
    struct noeud *pileB = NULL;

    // Ajouter des �l�ments � la pile 'pileA'
    empiler(&pileA, 85);
    empiler(&pileA, 45);
    empiler(&pileA, 26);
    empiler(&pileA, 17);
    empiler(&pileA, 17);
    empiler(&pileA, 11);
    empiler(&pileA, 2);
    printf("\n La liste 1 est : ");
    afficherListe(pileA);
    printf("\n");

    // Ajouter des �l�ments � la pile 'pileB'
    empiler(&pileB, 100);
    empiler(&pileB, 78);
    empiler(&pileB, 43);
    empiler(&pileB, 32);
    empiler(&pileB, 20);
    empiler(&pileB, 13);
    empiler(&pileB, 17);
    printf("\n La liste 2 est : ");
    afficherListe(pileB);
    printf("\n");

    // Fusionner les piles 'pileA' et 'pileB'
    resultat = fusionTriee(pileA, pileB);

    printf("\nLa fusion des deux listes : ");
    afficherListe(resultat);
    printf("\n");

    return 0;
}

// Fonction pour ajouter un �l�ment � la pile
void empiler(struct noeud **tete_ref, int nouvelle_valeur)
{
    struct noeud *nouveau_noeud = (struct noeud *)malloc(sizeof(struct noeud));

    if (nouveau_noeud == NULL) {
        printf("Erreur d'allocation de m�moire");
        exit(0);
    }

    nouveau_noeud->valeur = nouvelle_valeur;
    nouveau_noeud->suivant = (*tete_ref);
    (*tete_ref) = nouveau_noeud;
}

// Fonction pour retirer un �l�ment de la pile
int depiler(struct noeud **tete_ref)
{
    int res;
    struct noeud *tete;

    if (*tete_ref == NULL) {
        printf("Pile vide\n");
        exit(0);
    } else {
        tete = *tete_ref;
        res = tete->valeur;
        *tete_ref = tete->suivant;
        free(tete);
        return res;
}
}

// Fonction pour fusionner les piles
struct noeud *fusionTriee(struct noeud *a, struct noeud *b)
{
struct noeud *resultat = NULL;
if (a == NULL)
    return b;
else if (b == NULL)
    return a;

if (a->valeur <= b->valeur) {
    resultat = a;
    resultat->suivant = fusionTriee(a->suivant, b);
} else {
    resultat = b;
    resultat->suivant = fusionTriee(a, b->suivant);
}

return resultat;
}

// Fonction pour afficher la pile
void afficherListe(struct noeud *noeud)
{
while (noeud != NULL) {
printf("%d ", noeud->valeur);
noeud = noeud->suivant;
}
}
