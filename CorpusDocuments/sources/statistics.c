#include "../headers/statistics.h"

Statistics * createStatistics(unsigned int size_l){
    Statistics * statistics = (Statistics*)malloc(sizeof(Statistics));
    if(!statistics){
        perror("Problème of dynamic allocation to struct Statistics of linkedlist");
        exit(EXIT_FAILURE);
    }
    statistics->occurences = (int *)malloc(sizeof(int)*size_l);
    if(!statistics->occurences){
        perror("Problème of dynamic allocation to struct Statistics of linkedlist:(occurences part)");
        exit(EXIT_FAILURE);
    }
    statistics->namefile = (char **)malloc(sizeof(char *) *size_l);
    if(!statistics->namefile){
        perror("Problème of dynamic allocation to struct Statistics of linkedlist:(files part)");
        exit(EXIT_FAILURE);
    }
    statistics->tf = (float *)malloc(sizeof(float) * size_l);
     if(!statistics->tf){
        perror("Problème of dynamic allocation to struct Statistics of linkedlist:(tf part)");
        exit(EXIT_FAILURE);
    }
    statistics->tf_idf = (float *)malloc(sizeof(float) * size_l);
     if(!statistics->tf_idf){
        perror("Problème of dynamic allocation to struct Statistics of linkedlist:(tf_idf part)");
        exit(EXIT_FAILURE);
    }
    statistics->size = 0;
    statistics->capacity = size_l; 
    return statistics;
}

void addFileOccurences(Statistics * statistics, char * namefile, int occurences){
    assert(namefile != " " && occurences >= 1 && statistics);
    int res = isInLinkedList(statistics,namefile);
    if( res == -1 && statistics->size < statistics->capacity){
        statistics->namefile[statistics->size] = namefile;
        statistics->occurences[statistics->size++] = occurences;
    }else if(res != -1 && res < statistics->size){
        statistics->occurences[res]++;
    }
}

int isInLinkedList(Statistics * statistics, char * file){
    for(int i = 0; i < statistics->size; i++){
        if(statistics->namefile[i] == file){
            return i;
        }
    }
    return -1;
}

void toStringOccurences(Statistics * statistics){
    int i;
    for(i = 0; i < statistics->size; i++){
        printf("[Occ(%d); File(%s)]-",statistics->occurences[i],statistics->namefile[i]);
    }
    printf("%d",i);
}

void destroyStatistics(Statistics * statistics){
    if(statistics){
        if(statistics->namefile)free(statistics->namefile);
        if(statistics->occurences)free(statistics->occurences);
        if(statistics->tf)free(statistics->tf);
        if(statistics->tf_idf)free(statistics->tf_idf);
        free(statistics);
    } 
}

void swapStatistics(Statistics * statistics, Statistics * statistics2){
    for(int i = 0; i < statistics->size;i++){
        statistics2->occurences[i] = statistics->occurences[i];
        statistics2->namefile[i] = statistics->namefile[i];
    }
    statistics2->size = statistics->size;
    statistics2->capacity = statistics->capacity;
    statistics->size = 0;
}