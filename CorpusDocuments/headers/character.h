#ifndef _CHARACTER_H
#include "constants.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

/// @brief Compare deux mots selon leurs lettres et leur taille
/// @param word1 Mot qui sera comparer
/// @param word2 Mot avec lequelle on compare
/// @return Si le premier mot est plus grand ou plus petit
int compare(char * word1 , char* word2);

/// @brief Calcule la taille d'un mot
/// @param word Mot dont on calcule la taille
/// @return La taille du mot
unsigned int sizeWord(char * word);

/// @brief Indique si le caractère est une lettre Minuscule
/// @param c Caractère en cours de vérification
/// @return si la vérification est un succès
int isSmallLetter(char c);

/// @brief Indique si le caractère est une lettre Majuscule
/// @param c Caractère en cours de vérification
/// @return si la vérification est un succès
int isTallLetter(char c);

/// @brief Indique si le caractère est une lettre ou non
/// @param c Caractère en cours de vérification
/// @return si la vérification est un succès
int isSpecificCharacter(char c);

/// @brief Convertie un caractère majuscule en miniscule
/// @param c Caractère en cours de transformation
/// @return si la convertion est un succès
char convertTallToSmallCharacter(char c);


#define _CHARACTER_H 
#endif

