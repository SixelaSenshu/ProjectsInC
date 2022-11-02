#ifndef _HASHMAP_H

#include "linkedlist.h"
#include "corpus.h"

//##  Structures   #############################################

typedef struct hm{
    struct _cp * corpus;
    struct _linked_list** array;
    unsigned char * currentFile;
    unsigned int key;
    unsigned int size_h;
    unsigned int nbDocuments;
}Hashmap;

//##  Fonctions    #############################################

/// @brief Initialise une table de hachage
/// @param size_h La taille de la table
/// @param key La clé de la table
/// @param nbDocuments Le nombre de document dans le corpus
/// @return Si l'allocation est réussie
Hashmap* createHashmap(unsigned int size_h, unsigned int key, unsigned int nbDocuments);

/// @brief Libère la mémoire alloué à la table de hachage
/// @param map Table de Hachage ou on effectue la fouille
void destroyHashmap(Hashmap * map);

/// @brief Retourne la clé d'un mot
/// @param word Mot que l'on cherche
/// @param key Table de Hachage ou on effectue la fouille
/// @return La clé du mot dans la table de hachage
unsigned int keyOf(char * word, unsigned int key);

/// @brief  Ajoute un élement dans la table de hachage
/// @param word Mot que l'on cherche
/// @param map Table de Hachage ou on effectue la fouille
/// @param file Fichier ou on ajoute l'occurence
void addElementHashmap(char * word, Hashmap * map, char * file);

/// @brief Affiche sur la sortie standard la table de hachage
/// @param hp La table de hachage
void toStringHashmap(Hashmap * hp);

/// @brief Permet de chercher les fréquences de chaque mot dans le corpus
/// @param hp La table de hachage
void calculFrequencies(Hashmap * hp);

/// @brief Affiche sur la sortie standard les frequences
/// @param hp La table de hachage
void toStringFrequencies(Hashmap *hp);

#define _HASHMAP_H 
#endif