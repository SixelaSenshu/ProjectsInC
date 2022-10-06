///////////   Les Librairies   /////////////////////////////////////
#include "sort.c"
///////////   Les Fonctions   /////////////////////////////////////

/// @brief -> Fonction qui permet de générer un test pour un tri.
/// @param givenTab Tableau qui est donnée pour le tri.
/// @param size_t Taille du tableau.
/// @param stats Statistique pour le tri
/// @param mode Mode de sortie des données de stats
/// @param choice Choix du tri
void createTest(int *givenTab, int size_t, Stats *stats, char *mode, int choice)
{
    (*stats).nbCp = 0;
    (*stats).nbPm = 0;
    if (mode == "Output")
    {
        printf("----------------------------------------------\n");
        printf("Nb d'élement : %d \n", size_t);
        toString(givenTab, size_t);
    }
    switch (choice)
    {
    case 0:
        (*stats).name = "Bubble";
        bubble_sort(givenTab, size_t, stats);
        break;
    case 1:
        (*stats).name = "Insert";
        insert_sort(givenTab, size_t, stats);
        break;
    case 2:
        (*stats).name = "Select";
        select_sort(givenTab, size_t, stats);
        break;
    case 3:
        (*stats).name = "Quick";
        quick_sort(givenTab, 0, size_t, stats);
        break;
    case 4:
        (*stats).name = "Fusion";
        fusion_sort(givenTab, 0, size_t-1, stats);
        break;
    case 5:
        (*stats).name = "Heap";
        heapSort(givenTab, size_t, stats);
        break;
    default:
        break;
    }

    if (mode == "Output")
    {
        toString(givenTab, size_t);
        check(givenTab, size_t);
        printf("Tri : %s, Taille : %d, NbPermutation : %d,  NbComparaison : %d \n", stats->name, stats->size, stats->nbPm, stats->nbCp);
    }
    else if (mode == "CSV")
    {
        printf("%s;%d;%d;%d\n", stats->name, stats->size, stats->nbPm, stats->nbCp);
    }
    else if (mode == "Plot")
    {
        printf("%d %d %d ", stats->nbCp, stats->nbPm, stats->nbCp + stats->nbPm);
    }
}

/// @brief -> Permet d'analyser les temps d'éxecution pour des valeurs données
/// @param choice Choix du tri (de 0 à 6)
/// @param nb_expes  Un ensemble de listes que l'on va générer.
/// @param taille_mini  Nombre minimal d'élements.
/// @param nb_listes  Le Nombre d'ensemble de listes que l'on va générer.
/// @param mode : Mode de sortie : Génération uniquement de chiffre pour csv ou détails pour sortie sur console
int createPlatformTest(unsigned int nb_expes, unsigned int taille_mini, unsigned int nb_listes, char *mode)
{
    /*---------------------------------------------------------------
    Fonction qui permet de tester une fonction de differents tris sur plusieurs
    taille de tableau. Cela affiche les résultats des différents tests
    ---------------------------------------------------------------*/
    assert(nb_expes >= 1 && taille_mini >= 1 && nb_listes >= 1);

    Stats *stats;
    stats = (Stats *)malloc(sizeof(Stats));
    int *copyTab = NULL;
    int *givenTab = NULL;
    int size_t;

    if (!stats)
    {
        perror("[%SYSTEM] Problème d'allocation de mémoire pour la structure Stats");
        return EXIT_FAILURE;
    }

    // Pour un nombre de tris proposées et un nombre d'ensemble
    for (unsigned int i = 1; i < nb_listes + 1; i++)
    {
        size_t = taille_mini * i;
        copyTab = create(copyTab,size_t);
        givenTab = create(givenTab,size_t);
        (*stats).size = size_t;

        if (!copyTab || !givenTab)
        {
            perror("[%SYSTEM] Problème d'allocation de mémoire pour la liste d'entier de réfèrence ou d'instance ");
            return EXIT_FAILURE;
        }

        for (unsigned int nb = 0; nb < nb_expes; nb++)
        {
            fillRandom(size_t, copyTab);
            if (mode == "Plot")
            {
                printf("%d ", size_t);
            }

            for (unsigned int choice = 0; choice < 6; choice++)
            {
                cpytab(copyTab, givenTab, size_t);
                
                createTest(givenTab, size_t, stats, mode, choice);
            }
            if (mode == "Plot")
            {
                printf("\n");
            }
        }
    }
    free(stats);
    free(givenTab);
    free(copyTab);
    return EXIT_SUCCESS;
}

int main(int argc, char **argv)
{
    srandom(time(NULL));
    if (argc != 5)
    {
        fprintf(stderr, "[USAGE] %s RULE NB_ITERATION\n", *argv);
        exit(EXIT_FAILURE);
    }
    int choice = (int)atoi(argv[1]), nb_expes = atoi(argv[2]), taille_mini = atoi(argv[3]), nb_listes = atoi(argv[4]);
    if (choice == 1)
    {
        createPlatformTest(nb_expes, taille_mini, nb_listes, "Output");
    }
    else if (choice == 2)
    {
        printf("Tri;Taille;Permutations;Comparaisons\n");
        createPlatformTest(nb_expes, taille_mini, nb_listes, "CSV");
    }
    else if (choice == 3)
    {
        // printf("#Taille - Nombre de permutations - Nombre de comparaisons - Nombre d'opération \n");
        createPlatformTest(nb_expes, taille_mini, nb_listes, "Plot");
    }
    else
    {
        printf("Aucun type de sortie choisie");
    }

    return EXIT_SUCCESS;
}