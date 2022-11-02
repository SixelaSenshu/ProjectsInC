#ifndef _BINARYTREE_H
#define _BINARYTREE_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "../headers/hashmap.h"
#include "constants.h"

typedef struct _bt BinaryTree;
struct _bt{
    BinaryTree * right;
    BinaryTree * left;
    LinkedList * list;
    int occurences;
};

/// @brief Fonction qui permet de créer un arbre vide
/// @param word Le mot
/// @param occurences Ocurrences du mot
/// @return Retourne l'addrese de l'arbre
BinaryTree * createBinaryTree(char * word, int occurences);

/// @brief Permet d'ajouter un noeud à l'arbre
/// @param bt Arbre de l'arbre ou on ajoute le noeud
/// @param occurences Occurences du mot dans le corpus
/// @param word Mot que l'on ajoute
BinaryTree * addNode(BinaryTree * bt , int occurences, char * word);

/// @brief Fonction qui permet de créer un arbre à partie d'une table de hachage
/// @param hp Table de hachage
/// @return Retourne l'addrese de l'arbre
BinaryTree* createBinaryTreeFromHashmap(Hashmap* hp);

/// @brief Permet d'afficher l'abre en postfixé
/// @param bt Arbre ou on affiche l'arbre
void toStringBinaryTree(BinaryTree * bt);

/// @brief Permet d'effacer de l'adressse mémoire l'arbre
/// @param bt Arbre ou on libère 
void destroyBinaryTree(BinaryTree * bt);

/// @brief Permet de montrer les n plus grandes occurences
/// @param bt Arbre en question
/// @param nb Nombre d'occurences
/// @param cpt Compteur du nombre actuel d'occurences affichées
/// @return le nombre d'occurences actuelles
void toStringGreaterOccurences(BinaryTree * bt, unsigned int nb, int * cpt);

/// @brief Permet de montrer les n plus petites occurences
/// @param bt Arbre en question
/// @param nb Nombre d'occurences
/// @param cpt Compteur du nombre actuel d'occurences affichées
/// @return le nombre d'occurences actuelles
void toStringSmallerOccurences(BinaryTree * bt, unsigned int nb, int * cpt);
#endif