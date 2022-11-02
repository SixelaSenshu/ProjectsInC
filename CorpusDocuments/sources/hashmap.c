#include "../headers/hashmap.h"

//##  Fonctions    #############################################

Hashmap* createHashmap(unsigned int size_h, unsigned int key, unsigned int nbDocuments){
    Hashmap * map = (Hashmap *)malloc(sizeof(Hashmap));
    if(map == NULL){
        fprintf(stderr,"[SYSTEM]Error of allocation to hashmap");
        exit(EXIT_FAILURE);
    }
    map->corpus = createCorpus(nbDocuments);
    map->key = key;
    map->size_h = size_h;
    map->nbDocuments = nbDocuments;
    map->array = (LinkedList **)malloc(sizeof(LinkedList *) *size_h);
    for(int i = 0; i < size_h; i++){
        map->array[i] = NULL;
    }
    if(!map->array){
        fprintf(stderr,"[SYSTEM]Error of allocation to array of hashmap");
        exit(EXIT_FAILURE);
        
    }
    return map;
}

void destroyHashmap(Hashmap * map){
    if(map){
        for(int i = 0; i < map->size_h ; i++)if(map->array[i] != NULL) destroyLinkedList(map->array[i]);
        if(map->corpus)destroyCorpus(map->corpus);
        if(map->array)free(map->array);
        free(map);
    }
}

unsigned int keyOf(char * word, unsigned int key){
    unsigned res = 0;
    for(int i = 0; i < sizeWord(word); i++){
        res = res + (convertTallToSmallCharacter(word[i]) % key);
    }   
    res = res % HASHMAP_SIZE;
    return res;
}

void toStringHashmap(Hashmap * map){
    LinkedList * list;
    printf("\nAbout Corpus: \n");
    printf("-----------------------------------------------------\n\n");

    toStringCorpus(map->corpus);
    printf("\nAbout elements of Hashmap : \n");
    printf("-----------------------------------------------------\n\n");

    for(int i = 0; i < map->size_h ; i++){
        list = map->array[i];
        if(list != NULL){
            printf("|| Case n°%d : ",i +1);
            toStringLinkedList(list);
            printf("|| \n");
        }
    }
}

void addElementHashmap(char * word, Hashmap * map, char * file){
    unsigned int key = keyOf(word,map->key);
    if(map->array[key] == NULL ){
        map->array[key] = createLinkedList(map->nbDocuments,word,file); 
    }else{
        addLinkedList(word,map->array[key],file);
        
    }
}

void calculFrequencies(Hashmap * hp){
    int i , j , nbFiles ,nbStats, namefile;
    LinkedList * current;
    Statistics * stats;
    if(hp) nbFiles = hp->corpus->size;
    for(i = 0; i < hp->size_h; i++){
        current = hp->array[i];
        while(current != NULL){
            stats = current->statistics;
            nbStats = stats->size;
            stats->df = (float)nbFiles / (float)nbStats; 
            for(j =  0; j < nbStats;j++){
                namefile = inCorpus(stats->namefile[j],hp->corpus); 
                stats->tf[j] = (float) stats->occurences[j] / (float) hp->corpus->words[namefile] ;
                stats->tf_idf[j] =  stats->tf[j] * stats->df;
            }   
            current = current->next;
        }
    }
}

void toStringFrequencies(Hashmap *hp){
    int i , j , nbFiles, namefile;
    LinkedList * current;
    Statistics * stats;
    nbFiles = hp->corpus->size;
    for(i = 0; i < hp->size_h; i++){
        current = hp->array[i];
        while(current){
            if(current)printf("|case %d|\n",i+1);
            stats = current->statistics;
            printf("{%s|",current->word);
            for(j =  0; j < stats->size;j++){
                printf("[%s|tf = %.6f - df = %.2f - tf_idf = %.6f]--->---",stats->namefile[j],stats->tf[j],stats->df,stats->tf_idf[j]);
            }   
            current = current->next;
            printf("end}\n");
        }
    }
}
