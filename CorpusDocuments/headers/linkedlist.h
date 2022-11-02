
#ifndef _LINKEDLIST_H
#define _LINKEDLIST_H

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>

#include "character.h"
#include "constants.h"
#include "statistics.h"

typedef struct _linked_list LinkedList;
struct _linked_list{
    struct _linked_list * next;
    char * word;
    unsigned int nbfile;
    struct _statistics * statistics; 
};

//##  Fonctions    #############################################

/// @brief Initilialise une nouvelle liste chainée
/// @param size_l Nombre de la liste des tuples
/// @param word Mot du début de la liste
/// @param file Fichier ou est le mot
/// @return Donne la nouvelle liste 
LinkedList * createLinkedList( unsigned int size_l, char * word, char * file);

/// @brief Initilialise une nouvelle liste chainée sans stats
/// @param word  Mot du début de la liste
/// @return Donne la nouvelle liste 
LinkedList * createSimpleLinkedList(char * word);

/// @brief Fonction qui permet l'affichage de la liste chainée
/// @param list Liste chainée qui sera afficher sur la console
void toStringLinkedList(LinkedList * list);

/// @brief Donne la taille de la liste chainée
/// @param list La liste sur laquelle on cherche la taille
/// @return La taille de la liste
int sizeLinkedList(LinkedList * list);

/// @brief Libère la mémoire pour une liste
/// @param list Liste qui est liberer
void destroyLinkedList(LinkedList * list);

/// @brief Ajoute un élement à la liste ou rajoute une occurence
/// @param word Mot qui sera ajouter à la liste
/// @param list Liste qui subit l'ajout
/// @param file Nom du fichier
/// @return Le début de la liste chainée
LinkedList *  addLinkedList(char* word, LinkedList * list , char * file);

/// @brief Ajoute un élement de la liste sans stats
/// @param word Mot qui sera ajouter à la liste
/// @param list Liste qui subit l'ajout
/// @return Le début de la liste chainée
LinkedList * addSimpleLinkedList(char* word, LinkedList * list);

#endif