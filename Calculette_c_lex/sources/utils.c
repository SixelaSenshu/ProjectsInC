////////////////////////// Inclusions /////////////////////////////////////////////
#include "../headers/utils.h"
////////////////////////// Fonctions /////////////////////////////////////////////


void help(){
    printf("\n----------------------------------------------\nCommand to:\n");
    printf("0.help : launch the command \"help\" in writing </help> in your input to display help.\n");
    printf("1.end : launch the command \"end\" in writing <.> in your input to close the program.\n");
    printf("1.endcommand : launch the command \"endcommand\" in writing <<command>.> in your input to finish the command.\n");
    printf("2.display : launch the command \"display\" in writing <$var> to display $var value\n");
    printf("3.save : launch the command \"save\" in writing <!var> to save the last result in $var \n");
    printf("4.calculate : launch the command \"calculate\" in writing <?var var2 ope var3 ope ... varN opeN> to calculate an expression \n");
    printf("5.variables ! launch the command \"displayAll\" in wrinting </variables> to display all variables");
    printf("----------------------------------------------\n\n");
}

void variables(int * tab, unsigned size){
    assert(tab);
    int i = 0;
    printf("\n |-| Variable -> ");
    for(i = 0; i < size ;i++){
        if(tab[i] >= 0 )printf("[%d]:%d -> ",i,tab[i]);
    }
    printf("length : %d\n", i);
}
