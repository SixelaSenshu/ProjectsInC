#include "constants.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#ifndef _STATISTIQUE_H
#define _STATISTIQUE_H


typedef struct _statistics Statistics;
struct _statistics{
    float df; 
    float * tf;
    float * tf_idf;
    unsigned int size , capacity;
    unsigned int * occurences;
    char ** namefile;
};


/// @brief Initialise l'ensemble de tuples pour une liste 
/// @param size_l La taille de la liste
/// @return La liste des tuples
Statistics * createStatistics(unsigned int size_l);

/// @brief Ajoute un tuple File - Occurence
/// @param statistics Les stats que l'on modifie
/// @param namefile Le nom du fichier 
/// @param occurences Le nombre d'occurence
void addFileOccurences(Statistics * statistics, char * namefile, int occurences);

/// @brief Permet de vérifier si un élement est dans la liste
/// @param statistics Les stats en question
/// @param file Le nom du fichier
/// @return Si il y est ainsi que la pos
int isInLinkedList(Statistics * statistics, char * file);

/// @brief Affiche les occurences d'un mot pour tous les textes
/// @param statistics La liste des stats pour le mots
void toStringOccurences(Statistics * statistics);

/// @brief Désalloue la mémoire pour une liste de tuples 
/// @param statistics La liste des stats
void destroyStatistics(Statistics * tuples);

/// @brief Permet d'échanger de places les statistiques
/// @param statistics Celui qui donne
/// @param statistics2 Celui qui reçoit
void swapStatistics(Statistics * statistics, Statistics * statistics2);

#endif