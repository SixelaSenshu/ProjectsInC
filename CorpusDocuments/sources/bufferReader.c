///////////////////////  Fonctions  //////////////////////////////////////////
#include "../headers/bufferReader.h"

FILE* openFile(const char* fileName , const char* openMode){
    assert(fileName != "" && openMode != "");
    FILE * currentFile;
    currentFile = fopen(fileName,openMode);
    if(!currentFile){
        perror("[USAGE] Reading of file not possible : Path to file unknow.");
        exit(EXIT_FAILURE);
    }
    fseek(currentFile , SEEK_SET , 0) ;
    printf("Opening of file %s in progress.\n",fileName);
    return currentFile;
}

int closeFile(FILE* openedFile){
    if(openedFile){
        fclose(openedFile);
        printf("\nClosing of current file in progress\n\n");
    }
    return EXIT_SUCCESS;
}

int readWord(FILE* file, Hashmap * hp, unsigned int choice){
    // buffer qui permet de sauvegarder le mot que l'on veut ajouter
    char buffer[FILE_MAX_SIZE_WORD]={};
    int size_buffer = 0;
    int currentCharacter = fgetc(file);
    while(!isSpecificCharacter(currentCharacter)){
        buffer[size_buffer++] = convertTallToSmallCharacter(currentCharacter);
        currentCharacter = fgetc(file);
    }
    if(currentCharacter == EOF){
        return EOF;
    }
    if(size_buffer != 0){
        if(choice == 1)printf("%s ", buffer);
        addElementHashmap(buffer,hp,hp->currentFile);
    }
    return 1;
}


unsigned int readText(FILE* file, Hashmap * hp, unsigned int choice){
    unsigned int sum = 0;
    // on calcule le nombre de mot dans le texte pour avoir 
    // les fréquences des mots et des occurences dans les textes
    while(readWord(file,hp,choice) != EOF) sum++;
    return sum;
}
