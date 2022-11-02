#include "../headers/bufferReader.h"
#include "../headers/binaryTree.h"
#include "../headers/linkedlist.h"
#include "../headers/hashmap.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int promptWord(char * word, Hashmap * hp){
    int i = 0 , key = 0;
    float max1 = 0, max2 = 0, max3 = 0, tmp = 0;
    char name1[FILE_MAX_SIZE_WORD] = {};
    char name2[FILE_MAX_SIZE_WORD] = {};
    char name3[FILE_MAX_SIZE_WORD] = {};
    LinkedList * current;

    if(hp){
        key = keyOf(word,hp->key);
        current = hp->array[key];
    }
    while(current && key != -1){
        if(compare(current->word,word) == 2){
            for(i = 0; i< current->statistics->size; i++){
                tmp = current->statistics->tf_idf[i] ;
                if(tmp > max1){
                    max3 = max2;
                    strcpy(name3,name2);
                    max2 = max1;
                    strcpy(name2,name1);
                    max1 = tmp;
                    strcpy(name1,current->statistics->namefile[i]);
                }else if(tmp > max2){
                    max3 = max2;
                    strcpy(name3,name2);
                    max2 = tmp;
                    strcpy(name2,current->statistics->namefile[i]);
                }else if(tmp > max3){
                    max3 = tmp;
                    strcpy(name3,current->statistics->namefile[i]);
                }
            }
            printf("Files with most occurencies : \n {");
            if(max1 != 0) printf("(1) %s - %f | ", name1, max1);
            if(max2 != 0) printf("(2) %s - %f | ", name2, max2);
            if(max3 != 0) printf("(3) %s - %f | ", name3, max3);
            printf("}\n");
            key = -1;
        }
        current = current->next;
    }
    printf("Do you want to show a other word ? (0/1) : ");
    scanf("%d", &key);
    if(key == 1) return 1;
    return 0;
}

int main(int argc, char * argv[]){
    printf("\n****************************************************************************************** Launching of programs ***************************************************************************************************\n\n");
    unsigned int size, choice;
    int cpt;
    char word[FILE_MAX_SIZE_WORD] = {};

    if(argc <= 1){// On vérifie les arguments saisie dans la console pour qu'il y est au moin un fichier.
        perror("Incorrect number of files : neccesity to have one file or more.");
        exit(EXIT_FAILURE);
    } // On initialise la table de hachage ou sera créer le corpus de la même façons.
    Hashmap * hp = createHashmap(HASHMAP_SIZE,HASHMAP_KEY,argc-1);
    FILE * texte;
    printf("------------------------------ Reading of files ---------------------------------\n\n");
    printf("Do you want to display the content in texte (1/0) ? : ");
    scanf("%u",&choice);
   
    // On répète la mise à jour du corpus et de la table de hachage pour chaque les fichiers.
    for(cpt = 1; cpt < argc; cpt ++){
        texte = openFile(argv[cpt],"r");                // On gère la lecture.
        hp->currentFile = argv[cpt];                    // On ajoute le fichier actuel dans la table de hachage.
        size = readText(texte,hp,choice);               // Permet oui ou non de montrer le texte
        closeFile(texte);                               // On met à jour le corpus avec le nombre de mot inclus dedans.
        addFileCorpus(argv[cpt],size,hp->corpus);
    }// On affiche les résultats
    printf("------------------------------ About the Hashmap -------------------------------------\n\n");
    printf("Do you want to display the content in hashmap (1/0) ? : ");
    scanf("%u",&choice);
    if(choice == 1) toStringHashmap(hp);

    printf("\n------------------------------ Calculs of frequecies -----------------------------\n\n");
    printf("Do you want to display frequencies in hashmap (1/0) ? : ");
    scanf("%u",&choice);
    calculFrequencies(hp);
    if(choice == 1){
        toStringFrequencies(hp);
    }

    printf("\n------------------------------ Creating of a binary tree -----------------------------\n\n");
    printf("Do you want to display the tree of frequencies in hashmap (1/0) ? : ");
    scanf("%u",&choice);
    BinaryTree * bt = createBinaryTreeFromHashmap(hp);
    if(choice == 1){
        toStringBinaryTree(bt);
    }    

    printf("\n------------------------------ About a occurences ? -----------------------------\n\n");
    printf("Do you want to display the greater/smaller occurences (0/1[tall]/2[small]) ? :");
    scanf("%u",&choice);
    int nb = 0;
    int c = 0;
    if(choice == 1){
        printf("How many occurences? :");
        scanf("%u",&nb);
        if(nb >= 1)toStringGreaterOccurences(bt,nb,&c);
    }else if(choice == 2){
        printf("How many occurences? :");        
        scanf("%u",&nb);
        if(nb >= 1)toStringSmallerOccurences(bt,nb,&c);
    }

    printf("\n------------------------------ About a word ? -----------------------------\n\n");
    printf("Do you want to display the 3 files with the most of occurency of one word (1/0) ? :");
    scanf("%u",&choice);
    if(choice == 1){
        while(choice == 1){
            printf("Choice à word (MAX SIZE = 30) :");
            scanf("%s",&word);
            choice = promptWord(word,hp);
        }
    }// On désalloue toutes la mémoire
    destroyBinaryTree(bt);
    destroyHashmap(hp);
    
    printf("\n****************************************************************************************** Closing of programs ***********************************************************************************************\n");
    return EXIT_SUCCESS;
}