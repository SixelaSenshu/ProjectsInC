///////////   Les librairies   ///////////////////////////////////// 
#include <stdio.h>
#include <stdlib.h>
#include <error.h>
#include <time.h>
#include <assert.h>
#define MAXVALUE 2000

///////////   Les Structures   ///////////////////////////////////// 

typedef struct stats Stats;

/// @brief -> Test unitaire pour un tri et un tableau donné
struct stats{
    char * name;
    unsigned int size;
    unsigned int nbPm;
    unsigned int nbCp;
};

/// @brief -> Structure de l'arbreBinaire simplifié avec un tableau.
typedef struct bt BinaryTree;
struct bt{
    /* data */
    int * array;
    int size;
    int capacity;
};

///////////   Les Header   ///////////////////////////////////// 

void fillRandom(unsigned int nbElt, int* tab);

///////////   Les Fonctions   //////////////////////////////////////

/// @brief -> Alloue une mémoire à un tableau pour une taille donnée
/// @param size : La taille du tableau 
/// @return : Retourn si l'allocation est possible ou si il n'y a pas assez de mémoire
int * create(int * tab, unsigned int size){
    tab = (int *) realloc(tab,sizeof(int)*size);
    if(!tab){
        perror("Erreur d'allocation de mémoire pour la création d'un tableau");
        exit(0);
    }
    fillRandom(size,tab);
    return tab;
}

/// @brief -> Fonction qui permet d'échanger deux valeurs entre deux adresses
/// @param a : Première valeur (int)
/// @param b : Deuxième valeur (int)
void swap(int *a , int *b){
    assert(&a != NULL && &b != NULL);
    int tempo = *a;
    *a = *b;
    *b = tempo;
}

/// @brief -> Génère un nombre d'élements donnée pour un tableau
/// @param nbElt : Le nombre d'élements que l'on introduit au hasard dans le tableau
/// @param tab : Le tableau en question
void fillRandom(unsigned int nbElt, int* tab){
    assert(tab != NULL && nbElt > 0);
    for(int i = 0; i < nbElt; i++){
        tab[i] = 1 + random() % MAXVALUE;
    }
}

/// @brief -> Fonction qui permet d'afficher la liste sur l'entrée standard
/// @param tab : Le tableau d'entier
/// @param size : La taille du tableau
void toString(int *tab, unsigned int size){
    printf("|");
    for(int i = 0; i < size ; i++)
    {
        printf("%d|", tab[i]);
    }
    printf("\n");
}

/// @brief -> Verifie si le tableau est bien trié
/// @param tab : Le tableau que l'on vérifie 
/// @param size : La taille du tableau
/// @return  : Retourne si le tableau est trié
int check(int *tab, unsigned int size){
    for(int i = 0; i < size-1 ; i++)
    {
        if(tab[i] > tab[i+1]){
            printf("\nLe tableau est trié : False\n");
            return 0;
        }
    }
    printf("\nLe tableau est trié : True\n");
    return 1;
}

/// @brief -> Copie les valeurs de tab dans tabpcy
/// @param tab : Tableau qui donne les valeurs
/// @param tabcpy : Tableau qui reçois les valeurs
/// @param size : Taille du tableau qui donne les valeurs
void cpytab(int *tab, int *tabcpy, unsigned int size){
    assert(tab && tabcpy);
    for(int i = 0; i < size ; i++){
        tabcpy[i] = tab[i];
    }
}


