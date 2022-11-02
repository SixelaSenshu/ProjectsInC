#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "constants.h"
#include "hashmap.h"
#include "linkedlist.h"
#ifndef _FILE_H

#define _FILE_H

/// @brief Permet l'ouverture d'un fichier
/// @param fileName Fichier qui est ouvert
/// @param openMode Mode d'ouverture du fichier
/// @return Le pointeur du fichier
FILE* openFile(const char* fileName , const char* openMode);

/// @brief Permet la fermeture d'un fichier
/// @param openedFile Fichier qui est fermé
/// @return si l'opération est un succès
int closeFile(FILE* openedFile);

/// @brief Permet de lire un mot dans un fichier
/// @param file Fichier en lecture
/// @param hp La table de hachage 
/// @param choice Choix pour l'affichage du texte
/// @return Si le mot est la fin du fichier ou non
int readWord(FILE* file, Hashmap * hp, unsigned int choice);

/// @brief Permet de lire un fichier
/// @param file Fichier en lecture
/// @param hp La table de hachage 
/// @param choice Choix pour l'affichage du texte
/// @return Le nombre de mots
unsigned int readText(FILE* file, Hashmap * hp, unsigned int choice);


#endif
