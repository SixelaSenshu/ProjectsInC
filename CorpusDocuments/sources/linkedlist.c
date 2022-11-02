#include "../headers/linkedlist.h"

/////////////////// Linkedlist

LinkedList * createLinkedList(unsigned int size_l, char * word, char *file){
    assert(word && size_l > 0);
    LinkedList * lk = (LinkedList *) calloc(sizeof(LinkedList),1);
    if(!lk){
        perror("Problème of dynamic allocation to linkedlist");
        exit(EXIT_FAILURE);
    }
    Statistics * stats = createStatistics(size_l);
    lk->statistics = stats;
    if(!lk->statistics){
        perror("Problème of dynamic allocation to tuples of linkedlist");
        exit(EXIT_FAILURE);
    }
    char * w = (char *)malloc(sizeof(char)*FILE_MAX_SIZE_WORD);
    strcpy(w,word);
    lk->word = w;
    if(!lk->word){
        perror("Problème of dynamic allocation to word of linkedlist");
        exit(EXIT_FAILURE);
    }
    lk->nbfile = size_l;
    addFileOccurences(lk->statistics,file,1);
    return lk;
}

LinkedList * createSimpleLinkedList(char * word){
    assert(word);
    LinkedList * lk = (LinkedList *) calloc(sizeof(LinkedList),1);
    if(!lk){
        perror("Problème of dynamic allocation to linkedlist");
        exit(EXIT_FAILURE);
    }
    lk->word = (char *)malloc(sizeof(char)*FILE_MAX_SIZE_WORD);
    lk->word = strcpy(lk->word,word);
    return lk;
}

void toStringLinkedList(LinkedList * list){
    assert(list);
    LinkedList * current;
    if(list){
        current = list;
        while(current){
            printf("{ Word [%s]:",current->word);
            toStringOccurences(current->statistics);
            printf(" }---->");
            current = current->next;
        }
    } 
    printf("end\n");
}

int sizeLinkedList(LinkedList * list){
    if(!list) return 0;
    int res = 0;
    LinkedList * currentlist = list;
    while(currentlist){
        res+=1;
        currentlist = currentlist->next;
    }
    return res;
}

void destroyLinkedList(LinkedList * list){
    if(list != NULL){
        LinkedList * current = list;
        LinkedList * previous;
        while(current){
            previous = current;
            current = current->next;
            if(previous->statistics){destroyStatistics(previous->statistics);}
            if(previous->word)free(previous->word);
            free(previous);
        }
    }
}

LinkedList * addLinkedList(char* word, LinkedList * list, char * file){
    LinkedList * previous = NULL;
    LinkedList * current = list;
    LinkedList * new = NULL;
    unsigned int size_l = list->nbfile;

    while(current){
        if(compare(current->word,word) == 2){
            addFileOccurences(current->statistics,file,1);
            return list;
        }else if(compare(current->word,word) == 1){
            if(current == list){
                new = createLinkedList(size_l,current->word,file);
                swapStatistics(current->statistics,new->statistics);
                addFileOccurences(current->statistics,file,1);
                strcpy(current->word ,word);
                current->next = new;
            }else{
                new = createLinkedList(size_l,word,file);
                previous->next = new;
                new->next = current;
            }
            return list;
        }
        previous = current;
        current = current->next;
    }
    previous->next = createLinkedList(size_l,word,file);    
    return list;
}

LinkedList * addSimpleLinkedList(char* word, LinkedList * list){
    LinkedList * previous = NULL;
    LinkedList * current = list;
    LinkedList * new = NULL;

    while(current){
        if(compare(current->word,word) == 1){
            if(current == list){
                new = createSimpleLinkedList(current->word);
                strcpy(current->word ,word);
                current->next = new;
            }else{
                new = createSimpleLinkedList(word);
                previous->next = new;
                new->next = current;
            }
            return list;
        }else{
            previous = current;
            current = current->next;
        }
    }
    previous->next = createSimpleLinkedList(word);    
    return list;
}