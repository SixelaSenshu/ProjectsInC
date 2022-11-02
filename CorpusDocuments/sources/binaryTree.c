#include "../headers/binaryTree.h"

BinaryTree * createBinaryTree(char * word, int occurences){
    BinaryTree * bt = (BinaryTree *)calloc(sizeof(BinaryTree),1);
    if(!bt){
        perror("Error of allocation of memories to struct BinaryTree");
        exit(EXIT_FAILURE);
    }
    LinkedList * list = createSimpleLinkedList(word);
    list->statistics = NULL;
    if(!list){
        perror("Error of allocation of memories to struct BinaryTree (LinkedList");
        exit(EXIT_FAILURE);
    }
    bt->list = list;
    bt->occurences = occurences;
    return bt;
}

BinaryTree* addNode(BinaryTree * bt , int occurences, char * word){
    BinaryTree * btnew;
    if(!bt){
        btnew = createBinaryTree(word,occurences);
        return btnew;
    }else{
        if(bt->occurences > occurences){
            if(bt->left != NULL){
                addNode(bt->left,occurences,word);
            }else{
                btnew = createBinaryTree(word,occurences);
                bt->left = btnew;
                return btnew;
            }
        }
        else if(bt->occurences < occurences){
            if(bt->right != NULL){
                addNode(bt->right,occurences,word);
            }else{  
                btnew = createBinaryTree(word,occurences);
                bt->right = btnew;
                return btnew;
            }
        }
        else if(bt->occurences == occurences){
            addSimpleLinkedList(word,bt->list);
            return bt;
        }
    }
    return bt;
}

BinaryTree * createBinaryTreeFromHashmap(Hashmap* hp){
    BinaryTree * bt = NULL;
    int i, j ,sum;
    LinkedList * current;
    for(i = 0; i < hp->size_h; i++){
        current = hp->array[i];
        while(current){
            sum = 0;
            for(j = 0; j < current->statistics->size;j++){
                sum += current->statistics->occurences[j];
            }
            if(bt != NULL){
                addNode(bt,sum,current->word);
            }else{
                bt = createBinaryTree(current->word,sum);
            }
            current = current->next;
        }
    }
    return bt;
}


void toStringBinaryTree(BinaryTree * bt){
    LinkedList * current;
    if(bt){
        if(bt->left != NULL)toStringBinaryTree(bt->left);
        current = bt->list;
        printf("|| %d ||", bt->occurences);
        while(current){
            printf("{ %s }",current->word);
            current = current->next;
        }
        printf("\n");
        if(bt->right  != NULL)toStringBinaryTree(bt->right);
    }
}

void destroyBinaryTree(BinaryTree * bt){
    BinaryTree * left = bt->left;
    BinaryTree * right = bt->right;
    if(bt->left) destroyBinaryTree(left);
    if(bt->right) destroyBinaryTree(right);
    if(bt){
        if(bt->list)destroyLinkedList(bt->list);
        free(bt);
    }
    
}

void toStringGreaterOccurences(BinaryTree * bt, unsigned int nb, int * cpt){
    if(bt->right){
        toStringGreaterOccurences(bt->right,nb,cpt);
    }
    if(*cpt < nb){
        printf("|Occurences : [%d]|",bt->occurences);
        LinkedList * list = bt->list;
        while(list){
            printf("{%s}",list->word);
            list = list->next;
            printf("-->");
        }
        *cpt += 1;
    }
    if(bt->left){
        toStringGreaterOccurences(bt->left,nb,cpt);
    }
}


void toStringSmallerOccurences(BinaryTree * bt, unsigned int nb , int *cpt){
    if(bt->left){
        toStringSmallerOccurences(bt->left,nb,cpt);
    }
     if(*cpt < nb){
        printf("|Occurences : [%d]|",bt->occurences);
        LinkedList * list = bt->list;
        while(list){
            printf("{%s}",list->word);
            list = list->next;
            printf("-->");
        }
        *cpt += 1;
    }
    if(bt->right){
        toStringSmallerOccurences(bt->right,nb,cpt);
    }
}