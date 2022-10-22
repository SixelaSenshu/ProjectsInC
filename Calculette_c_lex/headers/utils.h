#ifndef _UTILS_H


////////////////////////// Inclusions /////////////////////////////////////////////
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <string.h>
////////////////////////// Fonctions /////////////////////////////////////////////

/// @brief Afficher les commandes
void help();

/// @brief Affiche les variables
/// @param tab Le tableau des variables
/// @param size LA taille du tableau
void variables(int * tab, unsigned size);

#define _UTILS_H 
#endif