////////////////////////// Inclusions /////////////////////////////////////////////
#include "../headers/stack.h"
////////////////////////// Fonctions /////////////////////////////////////////////

Stack * initEmptyStack(unsigned int size_s){
    Stack * stack = (Stack *)malloc(sizeof(Stack));
    stack->values = (int *)calloc(size_s,sizeof(int));
    stack->size = 0;
    stack->capacity = size_s;
    if(!stack){
        perror("Erreur d'allocation pour la pile");
        exit(EXIT_FAILURE);
    }
    for(int i = 0; i < SIZE_VAR; i++){
        stack->values[i] = 0;
    }
    return stack;
}

int pop(Stack* stack){
    assert(stack);
    if(stack->size >0){
        return stack->values[--stack->size];
    }
    return -1;   
}

void push(Stack *stack, int elt){
    assert(stack);
    if(stack->size < stack->capacity) stack->values[stack->size++] = elt;
}

int top(Stack *stack){
    assert(stack);
    if(stack->size > 0){
        return stack->values[stack->size - 1];
    }
    return EMPTY;
}

int isEmpty(Stack *stack){ return stack->size == 0; }

void toString(Stack *stack){
    assert(stack);
    if(!stack->size){
        printf("The stack is empty");
    }
    for(int i = 0; i < stack->size; i++) printf("{Pos[%d]: %d} ",stack->size - i,stack->values[i]);
    printf("\n"); 
}

void freeStack(Stack * stack){
    free(stack->values);
    free(stack);
}

/* Pour tester la pile unitairement

int main(){
    unsigned int i, size_s = SIZE_STACK;
    srandom(time(NULL));
    Stack * stack = initEmptyStack(size_s);
    if(!stack){
        perror("Erreur d'allocation de mémoire pour la pile");
        exit(EXIT_FAILURE);
    }else{
        printf("Allocation de la pile réussi : %d bytes\n", sizeof(stack));
    }
    toString(stack);
    for(i = 0; i < size_s ; i++){
        push(stack,random()%MAX_VALUE);
    }
    toString(stack);
    for(i = 0; i < size_s; i++){
        pop(stack);
    }
    toString(stack);
    freeStack(stack);
    return EXIT_SUCCESS;   
}
*/