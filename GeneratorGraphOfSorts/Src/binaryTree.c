/////////////////////////////////// Includes
#include "utils.c"
///////////   Les Fonctions   /////////////////////////////////////

/// @brief -> Initialise le tas
/// @param bt tas en question
/// @param capacity capacité du tas actuelle
/// @return l'arbre récemment créer
BinaryTree * initBinaryTree(BinaryTree* btnew , unsigned int capacity){
    btnew = (BinaryTree *) malloc(sizeof(BinaryTree));
    btnew->capacity = capacity;
    btnew->size = 0;
    btnew->array =(int *)malloc(sizeof(int)*capacity);
    if (!btnew)
    {
        perror("[%SYSTEM] Erreur d'allocation pour l'arbre binaire de recherche");
        exit(EXIT_FAILURE);
    }
    return btnew;
}

void freeBinaryTree(BinaryTree* btnew){
    
    if(btnew){
        free(btnew);
    }
}

/// @brief -> Ajoute un élement à l'arbre Binaire de tas.
/// @param elt : Element qui sera ajouter.
/// @param li : Arbre qui prend un nouvel élement
/// @param stats : Informations sur le trie.
void addElement(BinaryTree *abr, int elt, Stats *stats){
    int i = (*abr).size, end = 0;
    if (abr->size < abr->capacity){
        (*abr).size += 1;
        (*abr).array[i] = elt;
        while (i > 0 && !end){
            stats->nbCp++;
            if ((*abr).array[i] > (*abr).array[i / 2]){
                stats->nbPm++;
                swap(&(*abr).array[i], &(*abr).array[i / 2]);
            }
            else{
                end = 1;
            }
            i = i /2;
        }
    }
    else
    {
        perror("[%DATA] Plus d'ajout de valeurs possibles");
    }
}

/// @brief -> Supprime l'élement max de l'arbre.
/// @param li : Liste qui subit la suppresion.
/// @param stats : Informations sur le trie.
/// @return l'élement max
int deleteMaxElement(BinaryTree *abr, Stats *stats){
    assert((*abr).size >= 1);
    ///////////////////////////////// Paramètres
    int i, fin, max, indl, indr;
    i = 0, fin = 1;
    max = (*abr).array[0] ;
    (*abr).array[0] = (*abr).array[(*abr).size-1];
    (*abr).size--;
    indl = i * 2 + 1;                   // pour eviter les (0 * 2) = 0 ou (0 * 2) + 1 . De ce fait le fils gauche de 0 -> 1
    indr = indl + 1;  

    while (fin && indl <= (*abr).size && indr <= (*abr).size  ){//////////////////// Calcul d'indices
        stats->nbCp += 2;
        if ((*abr).array[indl] > (*abr).array[indr]){
            if((*abr).array[indl] >= (*abr).array[i]){
                stats->nbPm++;
                swap(&((*abr).array[i]), &((*abr).array[indl]));
                //printf("%d - %d\n",((*abr).array[i]), ((*abr).array[indl]));
                i = indl;
            }else{
                fin = 0;
            }
        }else if ((*abr).array[indr] >= (*abr).array[indl]){
            stats->nbPm++;
            if((*abr).array[indr] >= (*abr).array[i]){
                swap(&((*abr).array[i]), &((*abr).array[indr]));
                //printf("%d - %d\n",((*abr).array[i]), ((*abr).array[indr]));
                i = indr;
            }else{
                fin = 0;
            }
            stats->nbCp += 2;
        }
        indl = i * 2 + 1;                   // pour eviter les (0 * 2) = 0 ou (0 * 2) + 1 . De ce fait le fils gauche de 0 -> 1
        indr = indl + 1;  
        
    }
    return max;

}
