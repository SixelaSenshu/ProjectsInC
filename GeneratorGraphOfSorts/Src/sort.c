/////////////////////////////////// Includes
#include "binaryTree.c"

/***********************************************************/
/*                     Tri Bulle                           */
/***********************************************************/

/// @brief : Tri à bulles
/// @param tab : Tableau en cours de tri
/// @param size_t : Taille du tableau
/// @param stats : Informations sur le trie
void bubble_sort(int *tab, int size_t, Stats *stats)
{
    int j;
    for (int i = size_t-1; i > 0; i--){
        j = 0;
        while (j < i){
            stats->nbCp++;
            if (tab[j] > tab[j + 1])
            {
                stats->nbPm++;
                swap(&tab[j], &tab[j + 1]);
                
            }
            j++;
        }
    }
}

/***********************************************************/
/*                     Tri Insertion                       */
/***********************************************************/

/// @brief : Tri à insertion
/// @param tab : Tableau en cours de tri
/// @param size_t : Taille du tableau
/// @param stats : Informations sur le trie
void insert_sort(int *tab, unsigned int size_t, Stats *stats)
{
    int i = 0, j = 0, has = 1;
    while (i < size_t)
    {
        j = i;
        has = 1;
        while (j > 0 && has)
        {
            stats->nbCp++;
            if (tab[j - 1] > tab[j])
            {
                stats->nbPm++;
                swap(&tab[j], &tab[j - 1]);
                j--;
            }
            else
            {
                has = 0;
            }
        }
        i++;
    }
}

/***********************************************************/
/*                     Tri Selection                       */
/***********************************************************/

/// @brief -> Tri par Selection
/// @param tab : Tableau en cours de tri
/// @param size_t : Taille du tableau
/// @param stats : Informations sur le trie
void select_sort(int *tab, unsigned int size_t, Stats *stats)
{
    int min;
    for (int i = 0; i < size_t - 1; i++)
    {
        min = i;
        for (int y = i + 1; y < size_t; y++)
        {
            stats->nbCp += 1;
            if (tab[min] > tab[y])
            {
                min = y;
            }
        }
        if (min != i)
        {
            stats->nbPm += 1;
        }
        swap(&tab[i], &tab[min]);
    }
}

/***********************************************************/
/*                     Tri Fusion                          */
/***********************************************************/

/// @brief -> Tri une partition du tableau en cours de traitement par le tri fusion.
/// @param tab : Tableau en cours de tri.
/// @param start : Début de la partition.
/// @param pivot : Milieu de la partition
/// @param end : Fin de la partition.
/// @param stats : Informations sur le trie.
void fusion_tab(int *tab, unsigned int left, unsigned int middle, unsigned int right, Stats *stats){
    int i, j, k = left;
    int left_pos = middle - left + 1;
    int right_pos = right - middle;
    // printf("Taile Gauche : %d Taille Droite : %d , Taille Tableau %d , Indice start : %d, Indice pivot : %d, Indice end : %d \n",left_pos, right_pos, end-start, start,pivot,end);
    int *left_tab = (int *)malloc(sizeof(int) * left_pos);
    int *right_tab = (int *)malloc(sizeof(int) * right_pos);
    if (!left_tab || !right_tab){
        perror("[%SYSTEM] Problème d'allocation de mémoire dans les tableaux de partitions de gauche ou droite ");
        exit(0);
    }

    for (i = 0; i < left_pos; i++) left_tab[i] = tab[i + left];
    for (j = 0; j < right_pos; j++) right_tab[j] = tab[j + middle + 1];

    i = 0, j = 0;
    while (i < left_pos && j < right_pos){
        stats->nbCp++;
        if (left_tab[i] <= right_tab[j]){
            tab[k] = left_tab[i];
            i++;
            stats->nbPm++;
        }else{
            tab[k] = right_tab[j];
            j++;
        }
        k++;
    }
    while (i < left_pos){
        tab[k] = left_tab[i];
        i++;
        k++;
    }
    while (j < right_pos){
        tab[k] = right_tab[j];
        j++;
        k++;
    }
    free(right_tab);
    free(left_tab);
}

/// @brief -> Tri à fusion.
/// @param tab : Tableau en cours de tri.
/// @param start : Début de la partition.
/// @param end : Fin de la partition.
/// @param stats : Informations sur le trie
void fusion_sort(int *tab, unsigned int start, unsigned int end, Stats *stats)
{
    assert(*tab);
    unsigned int pivot;
    if (start < end ){
        pivot = start + ((end - start) / 2);
        fusion_sort(tab, start, pivot, stats);
        fusion_sort(tab, pivot + 1, end, stats);
        fusion_tab(tab, start, pivot, end, stats);
    }
}

/***********************************************************/
/*                     Tri Rapide                          */
/***********************************************************/

/// @brief : Tri Rapide
/// @param tab : Tableau en cours de tri
/// @param start : Début de la partition.
/// @param end : Fin de la partition.
/// @param stats : Informations sur le trie.
void quick_sort(int *tab, int start, int end, Stats *stats)
{
    int pivot = start, i;
    for (i = start + 1; i < end; i++)
    {
        stats->nbCp++;
        if (tab[i] < tab[pivot])
        {
            swap(&tab[i], &tab[pivot + 1]);
            swap(&tab[pivot], &tab[pivot + 1]);
            stats->nbPm += 2;
            pivot++;
        }
    }
    if (pivot - start > 0)
    {
        quick_sort(tab, start, pivot, stats);
    }
    if (end - pivot + 1 >= 0)
    {
        quick_sort(tab, pivot + 1, end, stats);
    }
}

/***********************************************************/
/*                     Tri par Tas                         */
/***********************************************************/

/// @brief -> Tri par tas.
/// @param values : Liste qui subit le tri.
/// @param size_v : Taille de la lsite
/// @param stats : Informations sur le trie.
void heapSort(int *values, unsigned int size_v, Stats *stats)
{
    //////////////////// Initialisation
    BinaryTree *abr = initBinaryTree(abr,size_v);
    int i = 0, max;

    if (!abr){
        perror("[%SYSTEM] Erreur d'allocation pour l'arbre de tas");
        exit(EXIT_FAILURE);
    }
    int *tabtmp = (int *)malloc(sizeof(int) * size_v);
    if (!tabtmp){
        perror("[%SYSTEM] Erreur d'allocation pour le tableau ");
        exit(EXIT_FAILURE);
    }
    ///////////////////////////////// Ajouts des élements
    while (i < size_v){
        addElement(abr, values[i], stats);
        i++;
    }
    ///////////////////////////////// Suppresions des élements
    while ((*abr).size > 0){
        max = deleteMaxElement(abr, stats);
        tabtmp[(*abr).size] = max;
    }
    (*abr).array = tabtmp;
    (*abr).size = size_v;
    cpytab(tabtmp,values,size_v);
    freeBinaryTree(abr);
    free(tabtmp);
}
