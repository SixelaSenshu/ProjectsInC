#ifndef _CORPUS_H

#include "character.h"
#include "constants.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

typedef struct _cp Corpus;
struct _cp{
    int * words;
    char** files;
    unsigned int capacity, size;
};

/// @brief Permet d'initialiser une instance statique d'un corpus de document
/// @param size_c Taille du corpus
/// @return Le corpus 
Corpus * createCorpus(unsigned int size_c);

/// @brief Ajoute un fichier au corpus
/// @param namefile Nom du nouveau fichier
/// @param nbWord Nombre de mots inclus dans le nouveau fichier
/// @param corpus Corpus auquel on ajoute un fichier
void addFileCorpus(char * namefile, unsigned int nbWord, Corpus * corpus);

/// @brief Permet de connaître si un texte est déja dans le corpus
/// @param namefile Le nom du fichier
/// @param corpus Le corpus
/// @return Si le fichier est dedans ou non
unsigned int inCorpus(char * namefile, Corpus * corpus);

/// @brief Fait la somme des mots de tous les documents
/// @param c Le corpus en question
/// @return Le nombre de mots total
unsigned int sumWords(Corpus * c);

/// @brief Affiche les élements du corpus
/// @param corpus Corpus que l'on affiche
void toStringCorpus(Corpus * corpus);

/// @brief Termine l'allocation pour un corpus
/// @param corpus le corpus qui est éffacer
void destroyCorpus(Corpus * corpus);

#define _CORPUS_H 
#endif