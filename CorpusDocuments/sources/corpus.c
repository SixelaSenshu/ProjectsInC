///////////////////////  Includes  //////////////////////////////////////////
#include "../headers/corpus.h"

Corpus * createCorpus(unsigned int size_c){
    assert(size_c > 0);
    Corpus * cp = (Corpus *)malloc(sizeof(Corpus));
    if(!cp){
        perror("Error of allocation to corpus");
        exit(EXIT_FAILURE);
    }
    cp->capacity = size_c; 
    cp->size = 0;

    char ** files = (char **)malloc(sizeof(char)* size_c * FILE_MAX_SIZE_WORD);
    if(!files){
        perror("Error of allocation to corpus");
        exit(EXIT_FAILURE);
    }
    cp->files = files;

    int * words = (int *)malloc(sizeof(int) * size_c);
    if(!words){
        perror("Error of allocation to corpus");
        exit(EXIT_FAILURE);
    }
    cp->words = words;
    return cp;
}

void addFileCorpus(char * namefile, unsigned int nbWord, Corpus * corpus){
    assert(namefile != "");
    if(corpus->size < corpus->capacity && !inCorpus(namefile,corpus)){
        corpus->words[corpus->size] = nbWord;
        corpus->files[corpus->size] = namefile;
        corpus->size++;
    }
}

unsigned int inCorpus(char * namefile, Corpus * corpus){
    assert(namefile != "");
    for(int i = 0; i < corpus->size; i++ ){
        if(corpus->files[i] == namefile){
            return 1;
        }
    }
    return 0;
}

unsigned int sumWords(Corpus * c){
    unsigned res = 0;
    for(int i = 0; i < c->size;i++){
        res += c->words[i];
    }
}

void toStringCorpus(Corpus * corpus){
    for(int i = 0 ; i < corpus->size; i++){
        printf("{[%d] The file named : %s , has : %d words }\n",i,corpus->files[i],corpus->words[i]);
    }   
}

void destroyCorpus(Corpus * corpus){
    free(corpus->words);
    free(corpus->files);
    free(corpus);
}
