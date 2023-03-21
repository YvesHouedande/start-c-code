#include "stdio.h"
#include "stdlib.h"
#include "string.h"
#include "prototype.h"

/*Une fonction creer_liste qui permet creer ou mettre en place
la tête, permettant d'avoir un point de réfférence 
*/
Liste *creer_liste(){
    Liste *liste = (Liste *)malloc(sizeof(*liste));
    liste->tete = NULL;
    liste->nb_maillons = 0;
    return liste;
}
/* Ici, nous verifions si les alloctaions de memoire se sont bien déroulés
si c'est le cas pour la premiere et pas pour le deuxieme cas, nous libérons l'espace allouer puis quitons le programme
dés que la prmiere echoue, on sort*/
void ajouter_ville(Liste * liste, char *ville, int population, int superficie){
    maillon_ville *nv_ville =  (maillon_ville *) malloc(sizeof(*nv_ville));
    if(nv_ville == NULL){
        printf("Erreur d'allocation \n");
        exit(1);
    }
    nv_ville->ville = (char*) malloc(sizeof(char) * (strlen(ville) + 1));
    if(nv_ville->ville == NULL){
        printf("Erreur d'allocation\n");
        free(nv_ville);
        exit(1);
    }
    strcpy(nv_ville->ville, ville);
    nv_ville->population = population;
    nv_ville->superficie = superficie;
    nv_ville->suivant = liste->tete;
    liste->tete = nv_ville;
    liste->nb_maillons++;
}


// permet de compter le nombre de ville
int compter_nb_villes(Liste * liste){
    maillon_ville *temp = liste->tete;
    int compteur = 0;
    while(temp != NULL){
        compteur++;
        temp = temp->suivant; // temp pour dire temporaire: 
        /* A chaque tour de boucle, temp prend la valeur du noeud suivant*/
    }

    return compteur;
    
}


void afficher_liste(Liste *liste){
    maillon_ville *temp = liste->tete;
    while (temp != NULL)
    {
        printf("Ville :%s , superficie:%d , population:%d\n", temp->ville, temp->superficie, temp->population);
        temp = temp->suivant;
    }
    
}  

// supprimer la premiere ville
void supprimer_ville_1(Liste *liste){
    maillon_ville *temp = liste->tete;
    maillon_ville *prec = NULL;
    //parcours la liste jusqu'au dernier élément
    while (temp->suivant != NULL) {
        prec = temp;
        temp = temp->suivant;
    }
    if (prec != NULL){
        prec->suivant = NULL;
    }
    else{
        liste->tete = NULL;
    }
    free(temp->ville);
    free(temp);
    liste->nb_maillons--;
}

//supprimer la derniere ville ajouter
void supprimer_ville_fin(Liste *liste) {
    if (liste->tete == NULL) {
        printf(" La liste est vide\n");
        return;
    }
    maillon_ville *temp = liste->tete;
    liste->tete = liste->tete->suivant;
    free(temp->ville);// on libere l'espace allouer en debut pour stocker la chaines de caractère
    free(temp);
    liste->nb_maillons--;
}

// 
void sup_ville_plus_400_mille(Liste * liste){
    /*
    Losque la premiere condition n'est pas respecter, c'esta-à-dire que la ville n'est pas sup
    a 400.000, nous continuons le parcours, dans le cas de notre else. Par contre, lorsque la condition,
    est respecté et que la valeur de prec n'est pas nul, alors, nous avons affaire a un noued quelconque
    différend de la tête. "prec" est en effet un noeud qui est à (n-1) rang par rapport au noeudd de refférence que nous 
    devons supprimer qui est au rang n.
    Faut rappeler que nous devons, en supprimant un noued, reajuster les pointeurs pour que la liste chainée reste liée dans son ensemble.
    Pour cela,  nous commencons en premmier par, grâce au pointeur que nous avons, nous sautons de noued en noeud.
    */
    maillon_ville *temp = liste->tete;
    maillon_ville *prec = NULL;
    while (temp != NULL) {
        if(temp->population > 400000){
            if(prec != NULL){
                prec->suivant = temp->suivant;//mise a jour du pointeur de l'element precedent vers celui de l'element suivant
                free(temp);
                liste->nb_maillons--;// nous decrématons notre pointeur pour le mettre a jour
                temp = prec->suivant;// noued suivant
            }
            else{
                liste->tete = temp->suivant;// nous avons affaire a alors a la tête, 
                free(temp);
                liste->nb_maillons--;
                temp = liste->tete;
            }
        }
        else{
            //nous continuons le parcours de la liste lorsque le noeud ne respecte pas notre critére de sélection
            prec = temp;
            temp = temp->suivant;
        }
    }
}

maillon_ville *recuperer_villes(Liste *liste) {
    // Initialisation de variables
    maillon_ville *tab = NULL;
    int taille_tab = 0;
    maillon_ville *temp = liste->tete;

    // Parcours de la liste
    while (temp != NULL) {
        if (temp->population > 500000) {
            // Réallocation de mémoire pour le tableau
            tab = realloc(tab, (taille_tab + 1) * sizeof(maillon_ville));
            if (tab == NULL) {
                printf("Erreur de réallocation de mémoire");
                return NULL;
            }
            // Ajout de l'élément à la fin du tableau
            tab[taille_tab] = *temp;
            taille_tab++;
        }
        temp = temp->suivant;
    }
    if(taille_tab==0){
        free(tab);
        return NULL;
    }
    liste->nb_ville_sup = taille_tab;// on garde une trace sur la longeur de la lsite pour pouvoir la pacourrir ultérieurement.
    return tab;//on retourne le pointeur vers le premier élement de la liste
}



// amelioration


// cette fonction va permettre à l'utilisateur d'entré toutes les options possibles
void afficher_option(){
    printf("\n #################### VOUS AVEZ LES OPTIONS SUIVANTES ##################\n");
    printf("0: Sortir du programme\n");
    printf("1:Ajouter une ou plusieurs villes.\n");
    printf("2:Recuperer toutes les villes ayant plus de 500.0000 habitants\n");
    printf("3:Compter le nombre de ville\n");
    printf("4:Supprimer la premier ville\n");
    printf("5:Supprimer la derniere ville\n");
    printf("6:Supprimer toutes les villes ayant plus de 400.0000 habitants\n");
    printf("7:Afficher toutes les villes \n");

    printf("Entrer une valeur comprise entre 1 et 7: ");
}

//cette fonction va permettre de recupperer les saisies de l'utilisateur et de gerrer les erreurs
int choix_utilisateur(){
    /* Nous allons verifier si les entrées utilisateur correspondent a ce que nous affichons en option.
        Dans le cas contraire, nous démandons à l'utisateur en boucle d'entré les donnés que l'on souhaite.
        scanf("%*[^\n]");//clean

        Nous gérons ainsi tous les cas de figures !!!!
    */
    int number = 0;
    // int i = 1;
    afficher_option();
    int ret = scanf("%d", &number);
    //verifions si le choix de l'utilsiateeur est correcte
    while(!(number>=0 && number<= 7) || ret==0){
        printf("\nla valeur saisie n'est pas juste !!!!! \n");
        scanf("%*[^\n]");//clean
        afficher_option();
        ret = scanf("%d", &number);
    }
         
    return number;
}

// permet de gerer tout ce qui est saisi utilisateur
void saisi_utilisateur(Liste *liste){
    int nb_ville = 0;
    int ville_compter = 0;
    //int ville_compter = 0 ;
    maillon_ville *liste_ville_sup = NULL;
    // Permet a l'utlisateur de choisir une option.
    int choix = choix_utilisateur();

    while(choix){
        switch (choix)
        {
        case 1: // Ajouter une ville
            printf("\nCombien de ville souhaitez-Vous ajouter ?:");
            int pas_erreur =  scanf("%d", &nb_ville);
            while (!pas_erreur)
            {
                scanf("%*[^\n]");
                printf("Ce n'est pas un chiffre, Veuillez Entrez Une Bonne Valeur!!!\n");
                pas_erreur =  scanf("%d", &nb_ville);
            }

            // tout se passe bien
            for (int i = 1; i <= nb_ville; i++)
            {
                char nom_ville[100];
                int superficie;
                int population;
                printf("Entrer le nom de la ville %d:", i);
                scanf("%s", &nom_ville);
                printf("Entrer la superficie de ville %d:", i);
                scanf("%d", &superficie);
                printf("Entrer Le nombre de population de la ville %d:",i );
                scanf("%d", &population);
                printf("\n");
                ajouter_ville(liste, nom_ville, population, superficie);
            }
            printf("\n--------FAITES UN NOUVEAU CHOIX OU TAPEZ 0 POUR QUITTER !--------");
            choix = choix_utilisateur();
        break;
        case 2://ville de plus 500.000hbts
            liste_ville_sup = recuperer_villes(liste);

            if(liste_ville_sup != NULL){//si la liste n'est pas vide
                printf("\nLES VILLES RECUPPERER DE PLUS DE 500.0000 HBTS SONT AU NOMBRE DE %d:\n", liste->nb_ville_sup);
                for (int i = 0; i < liste->nb_ville_sup; i++)
                {
                    printf("\n#################### VILLE RECUPERER  %d ######################\n", (i+1));
                    printf("Ville: %s, population: %d, superficie: %d\n ",liste_ville_sup[i].ville, liste_ville_sup[i].population,
                    liste_ville_sup[i].superficie);
                    printf("##################################################################\n");
                }
            }else{
                printf("\nIl n'exite pas de ville de supperficie superieur 500.0000 habitants\n ");
            }

            free(liste_ville_sup);
            printf("\n--------FAITES UN NOUVEAU CHOIX OU TAPEZ 0 POUR QUITTER !--------");
            choix = choix_utilisateur();
        break;
        case 3://compter les villes
            ville_compter = compter_nb_villes(liste);
            printf("\nLe Nombre de ville est %d :\n", ville_compter);
            printf("\n--------FAITES UN NOUVEAU CHOIX OU TAPEZ 0 POUR QUITTER !--------");
            choix = choix_utilisateur();
        break;
        case 4:// supprimer la premiere ville
            if(liste->tete==NULL){
                printf("\nIL n'existe pas encore de ville dans la liste  !!!!!!\n");
                printf("Vous pouvez en ajouter avec l'option 1\n");
                
            }else{
                supprimer_ville_1(liste);
                printf("La premiere ville est supprimer !!!!\n");
            }
            printf("\n--------FAITES UN NOUVEAU CHOIX OU TAPEZ 0 POUR QUITTER !--------");
            choix = choix_utilisateur();
        break;
        case 5://supprimer la derniere ville
            supprimer_ville_fin(liste);//elle verifie dejà si la liste est vide.
            printf("\n--------FAITES UN NOUVEAU CHOIX OU TAPEZ 0 POUR QUITTER !--------");
            choix = choix_utilisateur();
        break;
        case 6:
            sup_ville_plus_400_mille(liste);
            printf("\nLes Villes de plus de 400.000 habitants sont supprimer !!\n");
            choix = choix_utilisateur();
        break;
        case 7:
            printf("\n");
            afficher_liste(liste);
            choix = choix_utilisateur();
        break;
        default:
            break;
        }

    }
}