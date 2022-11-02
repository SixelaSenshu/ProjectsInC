///////////////////////  Includes  //////////////////////////////////////////
#include "../headers/character.h"

///////////////////////  Fonctions  //////////////////////////////////////////

int compare(char * word1 , char* word2){
    int i = 0;
    if(strcmp(word1,word2) == 0)return 2; // Si il est égale
    while(word1[i] != '\n' && word2[i] != '\n'){
        if(word1[i] > word2[i]) return 1;
        else if(word1[i] < word2[i]) return 0;
        i++;
    }
    if(word1[i] == '\0') return 0;
    return 1;
}

unsigned int sizeWord(char * word){
    assert(word);
    unsigned int ind=0;
    char letter = word[0]; 
    while (letter != '\0'){
        letter = word[++ind];
    }
    return ind;
}

int isSmallLetter(char c){
    if (c >= 'a' && c <= 'z' ){
        return 1;
    }
    return 0;
}

int isTallLetter(char c){ 
    if (c >= 'A' && c <= 'Z'){
        return 1;
    }
    return 0;
}

int isSpecificCharacter(char c){
    int cl = c;
    if(isTallLetter(c)) return 0;
    if(isSmallLetter(c)) return 0;
    else return 1;
}

char convertTallToSmallCharacter(char c){
    if(c >= 'A' && c <= 'Z'){
        int res = c + 32;
        return res;
    }else{
        return c;
    }
}
