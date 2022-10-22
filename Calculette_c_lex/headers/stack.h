#ifndef _STACK_H

#define _STACK_H 1

////////////////////////// Inclusions /////////////////////////////////////////////
#include "cal.h"
#include "utils.h"
////////////////////////// Structures ////////////////////////////////////////////

typedef struct stack Stack;
struct stack{
    /* data */
    int * values;
    int capacity;
    int size;
};
////////////////////////// Fonctions /////////////////////////////////////////////

/// @brief Initialise une pile avec une capacity prédéfinie
/// @param pile Pile qui est initialisé.
/// @param size_p Taille de la pile
/// @return La nouvelle pile
Stack* initEmptyStack(unsigned int size_p);

/// @brief Retire un élement de la pile
/// @param pile Pile qui subit le retrait de l'élement
/// @return L'élement retirée de la pile
int pop(Stack* stack);

/// @brief Ajoute d'un élement à la pile
/// @param stack Pile sur laquelle on ajoute un element
/// @param elt Élement que l'on ajoute
void push(Stack* stack, int elt);

/// @brief Retourne l'élement du haut de la pile
/// @param stack Pile sur laquelle ont montre le sommet
/// @param elt Élement du sommet
int top(Stack *stack);

/// @brief Indique si la pile est vide
/// @param stack Pile qui subit la vérification
/// @return Si la pile est vide ou non
int isEmpty(Stack* stack);

/// @brief Affiche le contenu de la pile
/// @param stack Pile qui subit la verification
void toString(Stack* stack);

/// @brief Libère l'adresse mémoire de la pile
/// @param stack Pile qui sera libérer
void freeStack(Stack * stack);

#endif